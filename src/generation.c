/* This program is free software. It comes WITHOUT ANY WARRANTY, to
* the extent permitted by applicable law. You can redistribute it
* and/or modify it under the terms of the Do What The Fuck You Want
* To Public License, Version 2, as published by Sam Hocevar. See
* http://wtfpl.net for more details. */
/**
 * \file generation.c
 * \brief Generation d'un fichier latex (code)
 * \author Harenome RAZANAJATO
 */
#include "generation.h"

static Bool printDebut(FILE * const fichier)
{
    int succes = fprintf(fichier,
                        "\\documentclass[10pt]{report}\n"
                        "\\usepackage{tikz}\n"
                        "\\usetikzlibrary{shapes}\n"
                        "\\title{Chasseur de Prim}\n"
                        "\\author{Boba Fett}\n"
                        "\\begin{document}\n"
                        "\\chapter{Graphe}\n"
                        "\\tikzset{sommet/.style={draw,circle,fill=blue}}\n"
                        );
    if (succes < 0)
    {
        fprintf(stderr, "Erreur lors de l'écriture de l'introduction.\n");
        return VRAI;
    }
    else
        return FAUX;
}

static Bool printSommets(const Graphe * g, FILE * const fichier)
{
    Bool erreurs = FAUX;

    if (!gEstVide(g))
    {
        Nat n = 360 / gNombreSommets(g);

        for (int i = 0; !gEstVide(g); g = gSuivant(g), i++)
        {
            int succes = fprintf(fichier,
                                "\\node[sommet] (%s) at (%d:%d) {%s};\n",
                                gSommetTete(g), n*i, 4, gSommetTete(g));
            if (succes < 0)
            {
                fprintf(stderr,
                        "Erreur lors du traitement du sommet %s.\n",
                        gSommetTete(g));
                erreurs = VRAI;
            }
        }
    }

    return erreurs;
}

static Bool printAretes(const Graphe * g, FILE * const fichier)
{
    Bool erreurs = FAUX;
    ListeArete * liste = gAretes(g);

    for (const ListeArete * l = liste; !larEstVide(l); l = larSuivante(l))
    {
        const Arete * const a = larAreteTete(l);
        int succes = fprintf(fichier,
                            "\\draw (%s) -- (%s) node [pos=0.25, auto, above] {%d};\n",
                            aA(a), aB(a), aPoids(a));
        if (succes < 0)
        {
            fprintf(stderr,
                    "Erreur lors du traitement de l'arête (%s, %s).\n",
                    aA(larAreteTete(l)), aB(larAreteTete(l)));
            erreurs = VRAI;
        }
    }

    liste = larLiberer(liste);

    return erreurs;
}

static Bool printGraphe(const Graphe * g, FILE * const fichier)
{
    Bool erreurs = FAUX;

    erreurs = fprintf(fichier, "\\begin{tikzpicture}\n\n") < 0 ? VRAI : erreurs;
    erreurs = printSommets(g, fichier) == VRAI ? VRAI : erreurs;
    erreurs = printAretes(g, fichier) == VRAI ? VRAI : erreurs;
    erreurs = fprintf(fichier, "\\end{tikzpicture}\n\n") < 0 ? VRAI : erreurs;

    return erreurs;
}

static int printFin(FILE * const fichier)
{
    int succes = fprintf(fichier, "\\end{document}\n");

    if (succes < 0)
    {
        fprintf(stderr, "Erreur lors de l'écriture de la fin de fichier.\n");
        return -1;
    }
    else
        return 0;
}

int gGenererLatex(const Graphe * g, const Graphe * a, const char * destination)
{
    FILE * const fichier = fopen(destination, "w");

    if (fichier == NULL)
    {
        return -1;
    }
    else
    {
        Bool erreurs = FAUX;

        erreurs = printDebut(fichier) == VRAI ? VRAI : erreurs;
        erreurs = printGraphe(g, fichier) == VRAI ? VRAI : erreurs;
        if (a != NULL)
        {
            fprintf(fichier, "\n\n\\chapter{Arbre couvrant minimum}\n");
            erreurs = printGraphe(a, fichier) == VRAI ? VRAI : erreurs;
        }
        erreurs = printFin(fichier) == VRAI ? VRAI : erreurs;

        fclose(fichier);

        if (erreurs)
            return -2;
        else
            return 0;
    }
}
