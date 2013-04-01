#include "testio.h"

int main(int argc, char ** argv)
{
    char * copie = malloc((strlen(argv[1]) + 7) * sizeof *copie);
    Graphe g = charger_graphe(argv[1]);
    copie = sprintf("%s_copie", argv[1]);
    sauvegarder_graphe(g, copie);

    g = gLiberer(g);
    free(copie);
    return 0;
}
