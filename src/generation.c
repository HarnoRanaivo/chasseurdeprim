/**
 * \file generation.c
 * \brief Generation d'un fichier latex (code)
 * \author Harenome RAZANAJATO
 */
#include "generation.h"

static int printDebut(FILE * const fichier)
{
    if (fprintf(fichier,
                "\\documentclass[10pt]{report}\n\
                \\usepackage{tikz}\n\
                \\title{Chasseur de Prim}\n\
                \\author{Boba Fett}\n\
                \\begin{document}\n\
                \\begin{tikzpicture}\n\n"
                ) < 0)
        return -1;
    else
        return 0;
}

static int printSommets(const Graphe * g, FILE * const fichier)
{
    int i;
    Nat n = 360 / gNombreSommets(g);

    for (g = g, i = 0; !gEstVide(g); g = gSuivant(g), i++)
        fprintf(fichier,
                "\\node[draw] (%s) at (%d:%d) {%s};\n",
                gSommetTete(g), n*i, 4, gSommetTete(g));

    return 0;
}

static int printAretes(const Graphe * g, FILE * const fichier)
{
    const ListeArete * l = gAretes(g);

    for (l = l; !larEstVide(l); l = larSuivante(l))
        fprintf(fichier,
                "\\draw (%s) -- (%s);\n",
                aA(larAreteTete(l)), aB(larAreteTete(l)));

    return 0;
}

static int printFin(FILE * const fichier)
{
    if (fprintf(fichier,
            "\\end{tikzpicture}\n\
            \\end{document}\n"
            ) < 0)
        return -1;
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
        printDebut(fichier);
        printSommets(g, fichier);
        printAretes(g, fichier);
        printFin(fichier);

        fclose(fichier);

        return 0;
    }
}
