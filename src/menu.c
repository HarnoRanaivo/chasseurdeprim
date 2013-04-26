#include "menu.h"

void afficherAide(void)
{
    printf("Commandes :\n\n"
            "\tch, charger <fichier>\n"
            "\t\tCharger un graphe.\n"

            "\t sv, sauvegarder <fichier>\n"
            "\t\tSauvegarder un graphe.\n"

            "\tm, modifier <sommet> <sommet> <poids>\n"
            "\t\tModifier une arête du graphe.\n"

            "\taj, ajouter <sommet> <sommet>\n"
            "\t\tAjouter une arête au graphe.\n"

            "\tsa, sarete\n"
            "\t\tSupprimer une arête du graphe.\n"

            "\tss, ssommet\n"
            "\t\tSupprimer un sommet du graphe.\n"

            "\tcal, calculer\n"
            "\t\tCalculer l'arbre couvrant minimum.\n"

            "\taf, afficher"
            "\t\t« Afficher » le graphe.\n"

            "\tq, quitter\n"
            "\t\tQuitter. You don't say?\n"
          );
}

MenuCommande rechercheCommande(const char * commande)
{
    if (strcmp(commande, "ch") == 0 || strcmp(commande, "charger") == 0)
        return MC_CHG;
    else if (strcmp(commande, "sv") == 0 || strcmp(commande, "sauvegarder") == 0)
        return MC_SAV;
    else if (strcmp(commande, "m") == 0 || strcmp(commande, "modifier") == 0)
        return MC_MOD;
    else if (strcmp(commande, "aj") == 0 || strcmp(commande, "ajouter") == 0)
        return MC_AJAR;
    else if (strcmp(commande, "sa") == 0 || strcmp(commande, "sarete") == 0)
        return MC_SUPAR;
    else if (strcmp(commande, "ss") == 0 || strcmp(commande, "ssomet") == 0)
        return MC_SUPSOM;
    else if (strcmp(commande, "cal") == 0 || strcmp(commande, "calculer") == 0)
        return MC_CAL;
    else if (strcmp(commande, "aff") == 0 || strcmp(commande, "afficher") == 0)
        return MC_AFF;
    else if (strcmp(commande, "q") == 0 || strcmp(commande, "quitter") == 0)
        return MC_QUIT;
    else
        return MC_INCONNU;
}

Bool traitementLigneCommande(const char * ligne, Graphe * g)
{
    char commande[32];

    if (sscanf(ligne, "%31s", commande) == 1)
    {
        for (int i = 0; commande[i] != '\0'; i++)
            commande[i] = tolower(commande[i]);

        MenuCommande mc = rechercheCommande(commande);
        switch (mc)
        {
            case MC_CHG :
                break;
            case MC_INCONNU :
            default :
                printf("Commande inconnue.\n");
                return VRAI;
        }
    }
}


Bool scanCommande(Graphe * g)
{
    char buffer[256] = { '\0' };

    if (scanf(" %255[^\n]", buffer) == 1)
        return traitementLigneCommande(buffer, g);
    else
        return VRAI;
}

void prompt(void)
{
    Graphe * g;
    do
    {
        printf("> ");
        fflush(stdout);
    }
    while (scanCommande(g));
}
