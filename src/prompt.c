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

static const char * AIDE_CHG = "\tch, charger <fichier>\n\
\t\tCharger un graphe depuis un fichier.\n\
\t\tLe graphe actuel ne sera pas conservé.\n\n";

static const char * AIDE_SAV = "\tsv, sauvegarder <fichier>\n\
\t\tSauvegarder un graphe dans un fichier.\n\n";

static const char * AIDE_MOD = "\tm, modifier <sommet> <sommet> <poids>\n\
\t\tModifier le poids une arête du graphe.\n\n";

static const char * AIDE_AJAR = "\taj, ajouter <sommet> <sommet> <poids>\n\
\t\tAjouter une arête au graphe.\n\
\t\tSi l'ajout de cette arête est susceptible\n\
\t\tde rendre le graphe non connexe, alors l'arête ne sera pas ajoutée.\n\n";

static const char * AIDE_SUPAR = "\tsa, sarete <sommet> <sommet>\n\
\t\tSupprimer une arête du graphe.\n\
\t\tSi la suppression de cette arête est\n\
\t\tsusceptible de rendre le graphe non connexe, alors l'arête ne sera pas\n\
\t\tsupprimée.\n\n";

static const char * AIDE_SUPSOM = "\tss, ssommet <sommet>\n\
\t\tSupprimer un somet du graphe.\n\
\t\tToutes les arêtes incidentes à ce sommet\n\
\t\tseront supprimées. Si cette opération est susceptible de rendre le graphe\n\
\t\tnon connexe, alors elle ne sera pas effectuée.\n\n";

static const char * AIDE_CAL = "\tcal, calculer <sommet>\n\
\t\tCalculer l'arbre couvrant minimum à partir d'un sommet donné.\n\n";

static const char * AIDE_AFF = "\taff, afficher <fichier>\n\
\t\t« Afficher » le(s) graphe(s).\n\
\t\tCrée un fichier compilable avec Latex,\n\
\t\tsous réserve de disponibilité du paquet TikZ, permettant de représenter\n\
\t\tle graphe actuel. Si un arbre couvrant minimum a été calculé et a été\n\
\t\tconservé, il sera « affiché » avec le graphe à partir duquel il a été créé.\n\n";

static const char * AIDE_LSV = "\tlsv, listevoisins <sommet>\n\
\t\tAfficher la liste des voisins d'un sommet.\n\n";

static const char * AIDE_LSI = "\tlsi, listeincidence <sommet>\n\
\t\tAfficher la liste des arêtes incidentes à un sommet.\n\n";

static const char * AIDE_LSS = "\tlss, listesommets\n\
\t\tAfficher la liste des sommets du graphe actuel.\n\n";

static const char * AIDE_LSA = "\tlsa, listearetes\n\
\t\tAfficher la liste des arêtes du graphe actuel.\n\n";

static const char * AIDE_AIDE = "\ta, aide [commande]\n\
\t\tAfficher l'aide.\n\
\t\tSans argument, cette commande affiche l'aide pour toutes\n\
\t\tles commandes. Avec un argument, elle affiche l'aide correspondant à la\n\
\t\tcommande renseignée.\n\n";

static const char * AIDE_QUIT = "\tq, quit, quitter\n\
\t\tQuitter. You don't say?\n\n";

static const char * AIDE_INC = "\tAucune aide n'existe pour cette commande car elle n'existe pas\n\n";

static const char * ERR_ARG = "Arguments invalides.\n";

Bool verifier(void)
{
    char buffer[8] = { '\0' };

    printf("Êtes-vous sûr de vouloir quitter le programme ?\n? ");
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

    for (const char * s = chaine; s != NULL; s = strchr(s, ' '))
    {
        n++;
        s++;
    }

    return n;
}

void afficherAideCommande(PromptCommande pc)
{
    const char * aide = AIDE_INC;

    switch (pc)
    {
        case PC_CHG :
            aide = AIDE_CHG;
            break;

        case PC_SAV :
            aide = AIDE_SAV;
            break;

        case PC_MOD :
            aide = AIDE_MOD;
            break;

        case PC_AJAR :
            aide = AIDE_AJAR;
            break;

        case PC_SUPAR :
            aide = AIDE_SUPAR;
            break;

        case PC_SUPSOM :
            aide = AIDE_SUPSOM;
            break;

        case PC_CAL :
            aide = AIDE_CAL;
            break;

        case PC_AFF :
            aide = AIDE_AFF;
            break;

        case PC_LSV :
            aide = AIDE_LSV;
            break;

        case PC_LSI :
            aide = AIDE_LSI;
            break;

        case PC_LSS :
            aide = AIDE_LSS;
            break;

        case PC_LSA :
            aide = AIDE_LSA;
            break;

        case PC_AIDE :
            aide = AIDE_AIDE;
            break;

        case PC_QUIT :
            aide = AIDE_QUIT;
            break;

        default :
            break;
    }

    printf("%s", aide);
}

void afficherAide(void)
{
    printf("Aide :\n\n");
    for (int i = 0; PC_LISTE[i] != PC_INCONNU; i++)
        afficherAideCommande(PC_LISTE[i]);
}

PromptCommande rechercherCommande(const char * ligne)
{
    char commande[32] = { '\0' };

    if (sscanf(ligne, "%31s", commande) == 1)
    {
        for (int i = 0; commande[i] != '\0'; i++)
            commande[i] = tolower(commande[i]);

        if (strcmp(commande, "ch") == 0 || strcmp(commande, "charger") == 0)
            return PC_CHG;
        else if (strcmp(commande, "sv") == 0 || strcmp(commande, "sauvegarder") == 0)
            return PC_SAV;
        else if (strcmp(commande, "m") == 0 || strcmp(commande, "modifier") == 0)
            return PC_MOD;
        else if (strcmp(commande, "aj") == 0 || strcmp(commande, "ajouter") == 0)
            return PC_AJAR;
        else if (strcmp(commande, "sa") == 0 || strcmp(commande, "sarete") == 0)
            return PC_SUPAR;
        else if (strcmp(commande, "ss") == 0 || strcmp(commande, "ssomet") == 0)
            return PC_SUPSOM;
        else if (strcmp(commande, "cal") == 0 || strcmp(commande, "calculer") == 0)
            return PC_CAL;
        else if (strcmp(commande, "aff") == 0 || strcmp(commande, "afficher") == 0)
            return PC_AFF;
        else if (strcmp(commande, "a") == 0 || strcmp(commande, "aide") == 0)
            return PC_AIDE;
        else if (strcmp(commande, "q") == 0
                 || strcmp(commande, "quitter") == 0
                 || strcmp(commande, "quit") == 0
                )
            return PC_QUIT;
        else if (strcmp(commande, "lsv") == 0 || strcmp(commande, "listevoisins") == 0)
            return PC_LSV;
        else if (strcmp(commande, "lsi") == 0 || strcmp(commande, "listeincidence") == 0)
            return PC_LSI;
        else if (strcmp(commande, "lss") == 0 || strcmp(commande, "listesommets") == 0)
            return PC_LSS;
        else if (strcmp(commande, "lsa") == 0 || strcmp(commande, "listearetes") == 0)
            return PC_LSA;
    }

    return PC_INCONNU;
}

Donnees * traiterLigneCommande(const char * ligne, PromptCommande pc, Donnees * d)
{
    char buffer1[481] = { '\0' };
    char buffer2[100] = { '\0' };
    int poids;
    Bool sur = VRAI;

    switch (pc)
    {
        case PC_CHG :
            if (compterMots(ligne) != 2 || sscanf(ligne, "%*s %480s", buffer1) != 1)
            {
                printf("%s", ERR_ARG);
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

        case PC_SAV :
            if (compterMots(ligne) != 2 || sscanf(ligne, "%*s %480s", buffer1) != 1)
            {
                printf("%s", ERR_ARG);
            }
            else
            {
                sauvegarder_graphe(d->graphe, buffer1);
                d->sauvegarde = VRAI;
            }
            break;

        case PC_MOD :
            if (compterMots(ligne) != 4
                || sscanf(ligne, "%*s %99s %99s %d", buffer1, buffer2, &poids) != 3)
            {
                printf("%s", ERR_ARG);
            }
            else
            {
                d->graphe = gcModifierArete(d->graphe, buffer1, buffer2, poids);
                d->arbre = gLiberer(d->arbre);
                d->sauvegarde = FAUX;
            }
            break;

        case PC_AJAR :
            if (compterMots(ligne) != 4
                || sscanf(ligne, "%*s %99s %99s %d", buffer1, buffer2, &poids) != 3)
            {
                printf("%s", ERR_ARG);
            }
            else
            {
                d->graphe = gcAjouterArete(d->graphe, buffer1, buffer2, poids);
                d->arbre = gLiberer(d->arbre);
                d->sauvegarde = FAUX;
            }
            break;

        case PC_SUPAR :
            if (compterMots(ligne) != 3
                || sscanf(ligne, "%*s %99s %99s", buffer1, buffer2) != 2)
            {
                printf("%s", ERR_ARG);
            }
            else
            {
                d->graphe = gcSupprimerArete(d->graphe, buffer1, buffer2);
                d->arbre = gLiberer(d->arbre);
                d->sauvegarde = FAUX;
            }
            break;

        case PC_SUPSOM :
            if (compterMots(ligne) != 2
                || sscanf(ligne, "%*s %99s", buffer1) != 1)
            {
                printf("%s", ERR_ARG);
            }
            else
            {
                d->graphe = gcSupprimerSommet(d->graphe, buffer1);
                d->arbre = gLiberer(d->arbre);
                d->sauvegarde = FAUX;
            }
            break;

        case PC_CAL :
            if (compterMots(ligne) != 2
                || sscanf(ligne, "%*s %99s", buffer1) != 1)
            {
                printf("%s", ERR_ARG);
            }
            else
            {
                d->arbre = gLiberer(d->arbre);
                d->arbre = gArbreCouvrantMinimum(d->graphe, buffer1);
            }
            break;

        case PC_AFF :
            if (compterMots(ligne) != 2
                || sscanf(ligne, "%*s %480s", buffer1) != 1)
            {
                printf("%s", ERR_ARG);
            }
            else
            {
                gGenererLatex(d->graphe, d->arbre, buffer1);
            }
            break;

        case PC_LSV :
            if (compterMots(ligne) != 2
                || sscanf(ligne, "%*s %99s", buffer1) != 1)
            {
                printf("%s", ERR_ARG);
            }
            else
            {
                afficherVoisins(d->graphe, buffer1);
            }
            break;

        case PC_LSI :
            if (compterMots(ligne) != 2
                || sscanf(ligne, "%*s %99s", buffer1) != 1)
            {
                printf("%s", ERR_ARG);
            }
            else
            {
                afficherAdjacence(d->graphe, buffer1);
            }
            break;

        case PC_LSS :
            if (compterMots(ligne) != 1)
                printf("%s", ERR_ARG);
            else
                afficherListeSommets(d->graphe);
            break;

        case PC_LSA :
            if (compterMots(ligne) != 1)
                printf("%s", ERR_ARG);
            else
                afficherAretesGraphe(d->graphe);
            break;

        case PC_AIDE :
            if (sscanf(ligne, "%*s %31s", buffer1) == 1)
                afficherAideCommande(rechercherCommande(buffer1));
            else
                afficherAide();
            break;

        case PC_QUIT :
            if (d->sauvegarde == FAUX)
                printf("Le graphe actuel n'a pas été sauvegardé.\n");
            break;

        case PC_INCONNU :

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
    d->sauvegarde = VRAI;

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
            PromptCommande pc = rechercherCommande(buffer);

            d = traiterLigneCommande(buffer, pc, d);
            if (pc == PC_QUIT && verifier() == VRAI)
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
