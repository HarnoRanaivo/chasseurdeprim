#include "testgeneration.h"

int main(int argc, char ** argv)
{
    if (argc < 2)
    {
        fprintf(stderr, "Usage : %s <ficher1> ...\n", argv[0]);
    }
    else
    {
        int i;
        for (i = 1; i < argc; i++)
        {
            /* Chargement du graphe. */
            Graphe * g1 = charger_graphe(argv[i]);

            /* Génération du fichier latex. */
            char * tex = malloc((strlen(argv[i]) + 5) * sizeof *tex);
            sprintf(tex, "%s.tex", argv[i]);
            gGenererLatex(g1, NULL, tex);

            g1 = gLiberer(g1);
            free(tex);
        }
    }

    return 0;
}
