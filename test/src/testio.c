#include "testio.h"

int main(int argc, char ** argv)
{
    if (argc < 2)
    {
        fprintf(stderr, "Usage : %s <ficher1> ...\n", argv[0]);
    }
    else
    {
        int i;
        for (i = 1; i <= argc; i++)
        {
            /* Chargement du graphe. */
            Graphe g1 = charger_graphe(argv[i]);

            /* Sauvegarde du graphe précédemment chargé. */
            char * copie = malloc((strlen(argv[i]) + 7) * sizeof *copie);
            sprintf(copie, "%s_copie", argv[1]);
            sauvegarder_graphe(g1, copie);

            /* Chargement de la sauvegarde et comparaison des deux graphes. */
            Graphe g2 = charger_graphe(copie);
            printf("%s : %s\n", argv[i], gEgalite(g1, g2) ? "OK" : "Échec");

            g1 = gLiberer(g1);
            g2 = gLiberer(g2);
            free(copie);
        }
    }

    return 0;
}
