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

static const char * ERR_ARG = "Arguments invalides.\n";

/* Le membre commande de la dernière structure doit absolument contenir
 * PC_INCONNU. */
static const struct
{
    PromptCommande commande;
    const char * aide;
    const char * alias[4];
} PCS[] =
{
    [PC_NOUV] =
    {
        PC_NOUV,
        "\tn, nouv, nouveau\n\
\t\tCréer un nouveau graphe.\n\n",
        { "n", "nouv", "nouveau", NULL, },
    },
    [PC_CHG] =
    {
        PC_CHG,
        "\tch, charger <fichier>\n\
\t\tCharger un graphe depuis un fichier.\n\
\t\tLe graphe actuel ne sera pas conservé.\n\n",
        { "ch", "charger", NULL, },
    },
    [PC_SAV] =
    {
        PC_SAV,
        "\tsv, sauvegarder <fichier>\n\
\t\tSauvegarder un graphe dans un fichier.\n\n",
        { "sv", "sauvegarder", NULL, },
    },
    [PC_MOD] =
    {
        PC_MOD,
        "\tm, mod, modifier <sommet> <sommet> <poids>\n\
\t\tModifier le poids une arête du graphe.\n\n",
        { "m", "mod", "modifier", NULL, },
    },
    [PC_AJAR] =
    {
        PC_AJAR,
        "\tajar, ajouter, ajouterArete <sommet> <sommet> <poids>\n\
\t\tAjouter une arête au graphe.\n\
\t\tSi l'ajout de cette arête est susceptible\n\
\t\tde rendre le graphe non connexe, alors l'arête ne sera pas ajoutée.\n\n",
        { "ajar", "ajouter", "ajouterarete", NULL, },
    },
    [PC_SUPAR] =
    {
        PC_SUPAR,
        "\tsa, supar, supprimerArete <sommet> <sommet>\n\
\t\tSupprimer une arête du graphe.\n\
\t\tSi la suppression de cette arête est\n\
\t\tsusceptible de rendre le graphe non connexe, alors l'arête ne sera pas\n\
\t\tsupprimée.\n\n",
        { "sa", "supar", "supprimerarete", NULL, },
    },
    [PC_SUPSOM] =
    {
        PC_SUPSOM,
        "\tss, sups, supprimerArete <sommet>\n\
\t\tSupprimer un somet du graphe.\n\
\t\tToutes les arêtes incidentes à ce sommet\n\
\t\tseront supprimées. Si cette opération est susceptible de rendre le graphe\n\
\t\tnon connexe, alors elle ne sera pas effectuée.\n\n",
        { "ss", "sups", "supprimersommet", NULL, },
    },
    [PC_CAL] =
    {
        PC_CAL,
        "\tcal, calculer <sommet>\n\
\t\tCalculer l'arbre couvrant minimum à partir d'un sommet donné.\n\n",
        { "cal", "calculer", NULL, },
    },
    [PC_AFF] =
    {
        PC_AFF,
        "\taff, afficher <fichier>\n\
\t\t« Afficher » le(s) graphe(s).\n\
\t\tCrée un fichier compilable avec Latex,\n\
\t\tsous réserve de disponibilité du paquet TikZ, permettant de représenter\n\
\t\tle graphe actuel. Si un arbre couvrant minimum a été calculé et a été\n\
\t\tconservé, il sera « affiché » avec le graphe à partir duquel il a été créé.\n\n",
        { "aff", "afficher", NULL, },
    },
    [PC_LSV] =
    {
        PC_LSV,
        "\tlsv, listeVoisins <sommet>\n\
\t\tAfficher la liste des voisins d'un sommet.\n\n",
        { "lsv", "listevoisins", NULL, },
    },
    [PC_LSI] =
    {
        PC_LSI,
        "\tlsi, listeIncidence <sommet>\n\
\t\tAfficher la liste des arêtes incidentes à un sommet.\n\n",
        { "lsi", "listeincidence", NULL, },
    },
    [PC_LSS] =
    {
        PC_LSS,
        "\tlss, listeSommets\n\
\t\tAfficher la liste des sommets du graphe actuel.\n\n",
        { "lss", "listesommets", NULL, },
    },
    [PC_LSA] =
    {
        PC_LSA,
        "\tlsa, listeAretes\n\
\t\tAfficher la liste des arêtes du graphe actuel.\n\n",
        { "lsa", "listearetes", NULL, },
    },
    [PC_EDIT] =
    {
        PC_EDIT,
        "\te, edit, editer\n\
\t\tPasser en mode « édition ».\n\
\t\tDans ce mode, il est possible d'éditer librement le graphe. Les\n\
\t\topérations ne conservent pas la connexité du graphe. Le graphe\n\
\t\tne sera pas conservé à la sortie de ce mode s'il n'est pas connexe.\n\n",
        { "e", "edit", "editer", NULL, }
    },
    [PC_AIDE] =
    {
        PC_AIDE,
        "\ta, aide [commande]\n\
\t\tAfficher l'aide.\n\
\t\tSans argument, cette commande affiche l'aide pour toutes\n\
\t\tles commandes. Avec un argument, elle affiche l'aide correspondant à la\n\
\t\tcommande renseignée.\n\n",
        { "a", "aide", NULL, },
    },
    [PC_QUIT] =
    {
        PC_QUIT,
        "\tq, quit, quitter\n\
\t\tQuitter. You don't say?\n\n",
        { "q", "quit", "quitter", NULL, },
    },
    [PC_INCONNU] =
    {
        PC_INCONNU,
        "\tAucune aide n'existe pour cette commande car elle n'existe pas\n\n",
        { NULL, },
    },
};

void afficherAidePromptCommande(PromptCommande pc)
{
    printf("%s", PCS[pc].aide);
}

void afficherAidePrompt(void)
{
    printf("Aide [Mode Normal] :\n\n");
    for (int i = 0; i < PC_INCONNU; i++)
        printf("%s", PCS[i].aide);
}

PromptCommande rechercherPromptCommande(const char * ligne)
{
    char commande[32] = { '\0' };

    if (sscanf(ligne, "%31s", commande) == 1)
    {
        for (int i = 0; commande[i] != '\0'; i++)
            commande[i] = tolower(commande[i]);

        for (int i = 0; i < PC_INCONNU; i++)
            if (rechercherMot(commande, PCS[i].alias) == VRAI)
                return PCS[i].commande;
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
        case PC_NOUV :
            if (compterMots(ligne) != 1)
                printf("%s", ERR_ARG);
            else
            {
                if (d->sauvegarde == FAUX)
                {
                    printf("Le graphe actuel n'a pas été sauvegardé.\n");
                    sur = verifier("de vouloir créer un nouveau graphe ");
                }
                if (sur)
                {
                    d->graphe = gLiberer(d->graphe);
                    d->arbre = gLiberer(d->arbre);
                    d->graphe = gNouv();
                    d->sauvegarde = VRAI;
                }

            }
            break;

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
                    sur = verifier("de vouloir charger un nouveau graphe ");
                }
                if (sur)
                {
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

        case PC_EDIT :
            if (d->sauvegarde == FAUX)
            {
                printf("Le graphe actuel n'a pas été sauvegardé.\n");
                sur = verifier("de vouloir entrer dans le mode « édition » ");
            }
            if (sur)
            {
                Graphe * g = modeEdition(gCopier(d->graphe));
                if (gEstConnexe(g))
                {
                    d->graphe = gLiberer(d->graphe);
                    d->arbre = gLiberer(d->arbre);
                    d->sauvegarde = FAUX;
                    d->graphe = g;
                }
                else
                    g = gLiberer(g);
            }
            break;

        case PC_AIDE :
            if (sscanf(ligne, "%*s %31s", buffer1) == 1)
                afficherAidePromptCommande(rechercherPromptCommande(buffer1));
            else
                afficherAidePrompt();
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
            PromptCommande pc = rechercherPromptCommande(buffer);

            d = traiterLigneCommande(buffer, pc, d);
            if (pc == PC_QUIT && verifier("de vouloir quitter le programme ") == VRAI)
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
