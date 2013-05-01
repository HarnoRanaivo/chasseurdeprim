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
#include "script.h"

static void batchScript(int debut, int fin, char ** argv)
{
    for (int i = 2; i < fin; i++)
        if (existeFichier(argv[i]))
            traiterFichier(argv[i]);
        else
            fprintf(stderr, "Le fichier %s n'existe pas.\n", argv[i]);
}

/**
 * \brief Main.
 */
int main(int argc, char ** argv)
{
    if (argc > 1)
    {
        if (rechercherMot("--version", (const char * const *)argv) || rechercherMot("-v", (const char * const *)argv))
            printf("Chasseur de Prim, version 1.2.0\n"
                    "Copyright © 2013, MEYER Jérémy, RAZANAJATO Harenome.\n"
                    "<https://github.com/remove/chasseurdeprim>\n"
                  );
        else if (rechercherMot(argv[1], (const char *[]) {"--scripts", "--script", "-s", NULL, }))
            batchScript(2, argc, argv);
        else
            batchScript(1, argc, argv);
    }
    else
        afficherPrompt();

    return 0;
}
