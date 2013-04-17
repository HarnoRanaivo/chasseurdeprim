/**
 * \file generation.c
 * \brief Generation d'un fichier latex (code)
 * \author Harenome RAZANAJATO
 */
#include "generation.h"

static int printDebut(FILE * const fichier)
{
    int succes = fprintf(fichier,
                        "\\documentclass[10pt]{report}\n"
                        "\\usepackage{tikz}\n"
                        "\\title{Chasseur de Prim}\n"
                        "\\author{Boba Fett}\n"
                        "\\begin{document}\n"
                        "\\begin{tikzpicture}\n\n");
    if (succes < 0)
    {
        fprintf(stderr, "Erreur lors de l'écriture de l'introduction.\n");
        return -1;
    }
    else
        return 0;
}

static int printSommets(const Graphe * g, FILE * const fichier)
{
    int i;
    int erreurs = 0;
    Nat n = 360 / gNombreSommets(g);

    for (g = g, i = 0; !gEstVide(g); g = gSuivant(g), i++)
    {
        int succes = fprintf(fichier,
                            "\\node[draw] (%s) at (%d:%d) {%s};\n",
                            gSommetTete(g), n*i, 4, gSommetTete(g));
        if (succes < 0)
        {
            fprintf(stderr,
                    "Erreur lors du traitement du sommet %s.\n",
                    gSommetTete(g));
            erreurs++;
        }
    }

    if (erreurs == 0)
        return 0;
    else
        return -erreurs;
}

static int printAretes(const Graphe * g, FILE * const fichier)
{
    int erreurs = 0;
    const ListeArete * l = gAretes(g);

    for (l = l; !larEstVide(l); l = larSuivante(l))
    {
        int succes = fprintf(fichier,
                            "\\draw (%s) -- (%s);\n",
                            aA(larAreteTete(l)), aB(larAreteTete(l)));
        if (succes < 0)
        {
            fprintf(stderr,
                    "Erreur lors du traitement de l'arête (%s, %s).\n",
                    aA(larAreteTete(l)), aB(larAreteTete(l)));
            erreurs++;
        }
    }

    if (erreurs == 0)
        return 0;
    else
        return -erreurs;
}

static int printFin(FILE * const fichier)
{
    int succes = fprintf(fichier,
                        "\\end{tikzpicture}\n"
                        "\\end{document}\n");
    if (succes < 0)
    {
        fprintf(stderr, "Erreur lors de l'écriture de la fin de fichier.\n");
        return -1;
    }
    else
        return 0;
}

int gGenererLatex(const Graphe * g, const char * destination)
{
    FILE * fichier = fopen(destination, "w");

    if (fichier == NULL)
    {
        return -1;
    }
    else
    {
        int erreurs = 0;

        erreurs += printDebut(fichier);
        erreurs += printSommets(g, fichier);
        erreurs += printAretes(g, fichier);
        erreurs += printFin(fichier);

        fclose(fichier);

        if (erreurs == 0)
            return 0;
        else
            return erreurs;
    }
}
