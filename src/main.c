/**
 * \file main.c
 * \brief Main
 */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "generation.h"
#include "prompt.h"
#include "io.h"

/**
 * \brief Main.
 */
int main(int argc, char ** argv)
{
    if (argc > 1)
    {
        for (int i = 1; i < argc; i++)
        {
            Graphe * g = charger_graphe(argv[i]);

            if (gEstConnexe(g))
            {
                char * affichage = malloc(strlen(argv[i] + 15) * sizeof *affichage);
                sprintf(affichage, "%s_affichage.tex", argv[i]);

                Graphe * a = gArbreCouvrantMinimum(g, gSommetTete(g));
                gGenererLatex(g, a, affichage);

                a = gLiberer(a);
            }
            else
            {
                fprintf(stderr,
                        "Erreur : Le fichier %s ne contient pas un graphe connexe.\n",
                        argv[i]);
            }
            
            g = gLiberer(g);
        }
    }
    else
        afficherPrompt();

    return 0;
}
