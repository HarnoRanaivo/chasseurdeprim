/* This program is free software. It comes WITHOUT ANY WARRANTY, to
* the extent permitted by applicable law. You can redistribute it
* and/or modify it under the terms of the Do What The Fuck You Want
* To Public License, Version 2, as published by Sam Hocevar. See
* http://wtfpl.net for more details. */
/**
 * \file prompt.c
 * \brief Prompt (code)
 * \author Harenome RAZANAJATO
 */
#include "prompt.h"

Bool verifier(void)
{
    char buffer[8] = { '\0' };

    printf("Êtes-vous sûr ?\n? ");
    fflush(stdout);
    scanf(" %7[^\n]", buffer);
    fflush(stdin);

    for (int i = 0; buffer[i] != '\0'; i++)
        buffer[i] = tolower(buffer[i]);

    if (strcmp(buffer, "o") == 0 || strcmp(buffer, "oui") == 0)
        return VRAI;
    else
        return FAUX;
}

int compterMots(const char * chaine)
{
    int n = 0;

    for (char * m = (char *) chaine; m != NULL; m = strchr(m, ' '));
        n++;

    return n;
}

void afficherAide(void)
{
    printf("Commandes :\n\n"
            "\tch, charger <fichier>\n"
            "\t\tCharger un graphe. Le graphe actuel ne sera pas conservé.\n\n"

            "\tsv, sauvegarder <fichier>\n"
            "\t\tSauvegarder un graphe.\n\n"

            "\tm, modifier <sommet> <sommet> <poids>\n"
            "\t\tModifier le poids une arête du graphe.\n\n"

            "\taj, ajouter <sommet> <sommet>\n"
            "\t\tAjouter une arête au graphe.\n\n"

            "\tsa, sarete\n"
            "\t\tSupprimer une arête du graphe.\n\n"

            "\tss, ssommet\n"
            "\t\tSupprimer un sommet du graphe.\n\n"

            "\tcal, calculer\n"
            "\t\tCalculer l'arbre couvrant minimum.\n\n"

            "\taf, afficher"
            "\t\t« Afficher » le graphe.\n\n"

            "\tq, quit, quitter\n"
            "\t\tQuitter. You don't say?\n\n"
          );
}

MenuCommande rechercherCommande(const char * ligne)
{
    char commande[32] = { '\0' };

    if (sscanf(ligne, "%31s", commande) == 1)
    {
        for (int i = 0; commande[i] != '\0'; i++)
            commande[i] = tolower(commande[i]);

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
        else if (strcmp(commande, "aide") == 0)
            return MC_AIDE;
        else if (strcmp(commande, "q") == 0
                 || strcmp(commande, "quitter") == 0
                 || strcmp(commande, "quit") == 0
                )
            return MC_QUIT;
    }

    return MC_INCONNU;
}

Donnees * traiterLigneCommande(const char * ligne, MenuCommande mc, Donnees * d)
{
    char buffer1[481] = { '\0' };
    char buffer2[100] = { '\0' };
    int poids;
    Bool sur = VRAI;

    switch (mc)
    {
        case MC_CHG :
            if (compterMots(ligne) != 2 || sscanf(ligne, "%*s %480s", buffer1) != 1)
            {
                printf("Arguments invalides.\n");
            }
            else
            {
                if (d->sauvegarde == FAUX)
                {
                    printf("Le graphe actuel n'a pas été sauvegardé.\n");
                    sur = verifier();
                }
                if (sur)
                {
                    if (compterMots(ligne) != 2
                        || sscanf(ligne, "%*s %480s", buffer1) != 1)
                    d->graphe = gLiberer(d->graphe);
                    d->arbre = gLiberer(d->arbre);
                    d->graphe = charger_graphe(buffer1);
                    d->sauvegarde = VRAI;
                }
            }
            break;

        case MC_SAV :
            if (compterMots(ligne) != 2 || sscanf(ligne, "%*s %480s", buffer1) != 1)
            {
                printf("Arguments invalides.\n");
            }
            else
            {
                sauvegarder_graphe(d->graphe, buffer1);
                d->sauvegarde = VRAI;
            }
            break;

        case MC_MOD :
            if (compterMots(ligne) != 4
                || sscanf(ligne, "%*s %99s %99s %d", buffer1, buffer2, &poids) != 3)
            {
                printf("Arguments invalides.\n");
            }
            else
            {
                d->graphe = gcModifierArete(d->graphe, buffer1, buffer2, poids);
                d->arbre = gLiberer(d->arbre);
                d->sauvegarde = FAUX;
            }
            break;

        case MC_AJAR :
            if (compterMots(ligne) != 4
                || sscanf(ligne, "%*s %99s %99s %d", buffer1, buffer2, &poids) != 3)
            {
                printf("Arguments invalides.\n");
            }
            else
            {
                d->graphe = gcAjouterArete(d->graphe, buffer1, buffer2, poids);
                d->arbre = gLiberer(d->arbre);
                d->sauvegarde = FAUX;
            }
            break;

        case MC_SUPAR :
            if (compterMots(ligne) != 3
                || sscanf(ligne, "%*s %99s %99s", buffer1, buffer2) != 2)
            {
                printf("Arguments invalides.\n");
            }
            else
            {
                d->graphe = gcSupprimerArete(d->graphe, buffer1, buffer2);
                d->arbre = gLiberer(d->arbre);
                d->sauvegarde = FAUX;
            }
            break;

        case MC_SUPSOM :
            if (compterMots(ligne) != 2
                || sscanf(ligne, "%*s %99s", buffer1) != 1)
            {
                printf("Arguments invalides.\n");
            }
            else
            {
                d->graphe = gcSupprimerSommet(d->graphe, buffer1);
                d->arbre = gLiberer(d->arbre);
                d->sauvegarde = FAUX;
            }
            break;

        case MC_CAL :
            if (compterMots(ligne) != 1
                || sscanf(ligne, "%*s %99s", buffer1) != 1)
            {
                printf("Arguments invalides.\n");
            }
            else
            {
                d->arbre = gLiberer(d->arbre);
                d->arbre = gArbreCouvrantMinimum(d->graphe, buffer1);
            }
            break;

        case MC_AFF :
            if (compterMots(ligne) != 2
                || sscanf(ligne, "%*s %480s", buffer1) != 1)
            {
                printf("Arguments invalides.\n");
            }
            else
            {
                gGenererLatex(d->graphe, d->arbre, buffer1);
            }
            break;

        case MC_AIDE :
            afficherAide();
            break;

        case MC_QUIT :
            break;

        case MC_INCONNU :

        default :
            sscanf(ligne, "%s", buffer1);
            printf("%s : Commande inconnue. Entrez 'aide' pour plus d'informations.\n", buffer1);
            break;
    }

    return d;
}

void prompt(void)
{
    Donnees * d = MALLOC(d);

    /* Le reste du programme ne peut pas fonctionner sans d. */
    if (d == NULL)
    {
        perror("malloc");
        exit(EX_OSERR);
    }

    d->graphe = gNouv();
    d->arbre = gNouv();
    d->sauvegarde = FAUX;

    Bool continuer = VRAI;

    do
    {
        int succes;
        char buffer[512] = { '\0' };

        printf("> ");
        fflush(stdout);

        succes = scanf(" %511[^\n]", buffer);
        fflush(stdin);

        if (succes == 1)
        {
            MenuCommande mc = rechercherCommande(buffer);

            d = traiterLigneCommande(buffer, mc, d);
            if (mc == MC_QUIT && verifier() == VRAI)
            {
                d->graphe = gLiberer(d->graphe);
                d->arbre = gLiberer(d->arbre);
                free(d);
                continuer = FAUX;
            }
        }
    }
    while (continuer);
}
