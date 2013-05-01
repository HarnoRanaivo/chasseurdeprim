/* This program is free software. It comes WITHOUT ANY WARRANTY, to
* the extent permitted by applicable law. You can redistribute it
* and/or modify it under the terms of the Do What The Fuck You Want
* To Public License, Version 2, as published by Sam Hocevar. See
* http://wtfpl.net for more details. */
/**
 * \file edition.c
 * \brief Prompt mode édition (code)
 * \author Harenome RAZANAJATO
 *
 * Le fonctionnement de ce fichier est très proche de celui de prompt.c.
 */
#include "edition.h"

static const char * ERR_ARG = "Arguments invalides.\n";
static const char * ERR_SOM = "Ce sommet n'existe pas.\n";
static const char * ERR_ART = "Cette arête n'existe pas.\n";
static const char * ERR_VID = "Le graphe est vide.\n";

/* Le membre commande de la dernière structure doit absolument contenir
 * ED_INCONNU. */
static const struct
{
    EditCommande commande;
    const char * aide;
    const char * alias[4];
} EDS[] =
{
    [ED_NOUV] =
    {
        ED_NOUV,
        "\tn, nouv, nouveau\n\
\t\tCréer un nouveau graphe.\n\n",
        { "n", "nouv", "nouveau", NULL, }
    },

    [ED_AJS] =
    {
        ED_AJS,
        "\tajs, ajoutersommet <sommet>\n\
\t\tAjouter un sommet au graphe.\n\
\t\tSi le sommet existe déjà, le graphe reste intact.\n\n",
        { "ajs", "ajoutersommet", NULL, },
    },

    [ED_AJAR] =
    {
        ED_AJAR,
        "\tajar, ajouterarete <sommet> <sommet> <poids>\n\
\t\tAjouter une arête au graphe.\n\
\t\tSi l'un des sommets n'existe pas, il est ajouté au graphe avant\n\
\t\td'ajouter l'arête. Si l'arête existe déjà, le graphe reste intact.\n\n",
        { "ajar", "ajouterarete", NULL, },
    },

    [ED_MOD] =
    {
        ED_MOD,
        "\tmod, modifier <sommet> <sommet> <poids>\n\
\t\tModifier une arête, si elle existe, du graphe.\n\n",
        { "mod", "modifier", NULL, },
    },

    [ED_SUPS] =
    {
        ED_SUPS,
        "\tss, sups, supprimersommet <sommet>\n\
\t\tSupprimer un sommet, si il existe, du graphe.\n\n",
        { "ss", "sups", NULL, },
    },

    [ED_SUPAR] =
    {
        ED_SUPAR,
        "\tsa, supar, supprimerarete <sommet> <sommet> <poids>\n\
\t\tSupprimer une arête, si elle existe, du graphe.\n\n",
        { "sa", "supar", NULL, },
    },

    [ED_LSV] =
    {
        ED_LSV,
        "\tlsv, listeVoisins <sommet>\n\
\t\tAfficher la liste des voisins d'un sommet.\n\n",
        { "lsv", "listevoisins", NULL, },
    },

    [ED_LSI] =
    {
        ED_LSI,
        "\tlsi, listeIncidence <sommet>\n\
\t\tAfficher la liste des arêtes incidentes à un sommet.\n\n",
        { "lsi", "listeincidence", NULL, },
    },

    [ED_LSS] =
    {
        ED_LSS,
        "\tlss, listeSommets\n\
\t\tAfficher la liste des sommets du graphe actuel.\n\n",
        { "lss", "listesommets", NULL, },
    },

    [ED_LSA] =
    {
        ED_LSA,
        "\tlsa, listeAretes\n\
\t\tAfficher la liste des arêtes du graphe actuel.\n\n",
        { "lsa", "listearetes", NULL, },
    },

    [ED_CNX] =
    {
        ED_CNX,
        "\tco, connexe\n\
\t\tVérifier la connexité du graphe actuel.\n\n",
        { "co", "connexe", NULL, },
    },

    [ED_AIDE] =
    {
        ED_AIDE,
        "\ta, aide [commande]\n\
\t\tAfficher l'aide.\n\
\t\tSans argument, cette commande affiche l'aide pour toutes\n\
\t\tles commandes. Avec un argument, elle affiche l'aide correspondant à la\n\
\t\tcommande renseignée.\n\n",
        { "a", "aide", NULL, },
    },

    [ED_QUIT] =
    {
        ED_QUIT,
        "\tq, quit, quitter\n\
\t\tQuitter.\n\n",
        { "q", "quit", NULL, },
    },

    [ED_INCONNU] =
    {
        ED_INCONNU,
        "\tAucune aide n'existe pour cette commande car elle n'existe pas\n\n",
        { NULL },
    },
};

void afficherAideEditCommande(EditCommande ec)
{
    printf("%s", EDS[ec].aide);
}

void afficherAideEdition(void)
{
    printf("Aide [Mode Édition] :\n\n");
    for (int i = 0; i < ED_INCONNU; i++)
        printf("%s", EDS[i].aide);
}

EditCommande rechercherEditCommande(const char * ligne)
{
    char commande[32] = { '\0' };

    if (sscanf(ligne, "%31s", commande) == 1)
    {
        chaineEnMinuscules(commande);

        for (int i = 0; i < ED_INCONNU; i++)
            if (rechercherMot(commande, EDS[i].alias))
                return EDS[i].commande;
    }

    return ED_INCONNU;
}

Graphe * traiterLigneEdition(const char * ligne, EditCommande ec, Graphe * g)
{
    char buffer1[481] = { '\0' };
    char buffer2[100] = { '\0' };
    int poids;

    switch (ec)
    {
        case ED_NOUV :
            if (compterMots(ligne) != 1)
                printf("%s", ERR_ARG);
            else
            {
                if (verifier("de vouloir créer un nouveau graphe "))
                {
                    g = gLiberer(g);
                    g = gNouv();
                }
            }
            break;

        case ED_AJS :
            if (compterMots(ligne) != 2
                || sscanf(ligne, "%*s %99s", buffer1) != 1)
                printf("%s", ERR_ARG);
            else if (!gExisteSommet(g, buffer1))
                g = gAjouterSommet(g, buffer1);
            else
                printf("Ce sommet existe déjà.\n");
            break;

        case ED_AJAR :
            if (compterMots(ligne) != 4
                || sscanf(ligne, "%*s %99s %99s %d", buffer1, buffer2, &poids) != 3)
                printf("%s", ERR_ARG);
            else if (!gExisteArete(g, buffer1, buffer2))
                g = gAjouterArete(g, buffer1, buffer2, poids);
            else
                printf("Cette arête existe déjà.\n");
            break;

        case ED_MOD :
            if (compterMots(ligne) != 4
                || sscanf(ligne, "%*s %99s %99s %d", buffer1, buffer2, &poids) != 3)
                printf("%s", ERR_ARG);
            else if (gExisteArete(g, buffer1, buffer2))
                g = gModifierArete(g, buffer1, buffer2, poids);
            else
                printf("%s", ERR_ART);
            break;

        case ED_SUPS :
            if (compterMots(ligne) != 2
                || sscanf(ligne, "%*s %99s", buffer1) != 1)
                printf("%s", ERR_ARG);
            else if (gExisteSommet(g, buffer1))
                g = gSupprimerSommet(g, buffer1);
            else
                printf("%s", ERR_SOM);
            break;

        case ED_SUPAR :
            if (compterMots(ligne) != 3
                || sscanf(ligne, "%*s %99s %99s", buffer1, buffer2) != 2)
                printf("%s", ERR_ARG);
            else if (gExisteArete(g, buffer1, buffer2))
                g = gSupprimerArete(g, buffer1, buffer2);
            else
                printf("%s", ERR_ART);
            break;

        case ED_LSV :
            if (compterMots(ligne) != 2
                || sscanf(ligne, "%*s %99s", buffer1) != 1)
                printf("%s", ERR_ARG);
            else if (gExisteSommet(g, buffer1))
                afficherVoisins(g, buffer1);
            else
                printf("%s", ERR_SOM);
            break;

        case ED_LSI :
            if (compterMots(ligne) != 2
                || sscanf(ligne, "%*s %99s", buffer1) != 1)
                printf("%s", ERR_ARG);
            else if (gExisteSommet(g, buffer1))
                afficherAdjacence(g, buffer1);
            else
                printf("%s", ERR_SOM);
            break;

        case ED_LSS :
            if (compterMots(ligne) != 1)
                printf("%s", ERR_ARG);
            else if (!gEstVide(g))
                afficherListeSommets(g);
            else
                printf("%s", ERR_VID);
            break;

        case ED_LSA :
            if (compterMots(ligne) != 1)
                printf("%s", ERR_ARG);
            else if (!gEstVide(g))
                afficherAretesGraphe(g);
            else
                printf("%s", ERR_VID);
            break;

        case ED_CNX :
            if (compterMots(ligne) != 1)
                printf("%s", ERR_ARG);
            else
            {
                if (gEstConnexe(g))
                    printf("Le graphe est connexe.\n");
                else
                    printf("Le graphe n'est pas connexe.\n");
            }
            break;

        case ED_AIDE :
            if (sscanf(ligne, "%*s %31s", buffer1) == 1)
                afficherAideEditCommande(rechercherEditCommande(buffer1));
            else
                afficherAideEdition();
            break;

        case ED_QUIT :
            if (!gEstConnexe(g))
            printf("Le graphe actuel n'est pas connexe. Il ne sera pas conservé.\n");
            break;

        case ED_INCONNU :

        default :
            sscanf(ligne, "%s", buffer1);
            printf("%s : Commande inconnue. Entrez 'aide' pour plus d'informations.\n", buffer1);
            break;
    }

    return g;
}

Graphe * modeEdition(Graphe * g)
{
    Bool continuer = VRAI;

    do
    {
        int succes;
        char buffer[512] = { '\0' };

        printf("# ");
        fflush(stdout);

        succes = scanf("%511[^\n]%*[^\n]", buffer);
        getchar();

        if (succes == 1)
        {
            EditCommande ec = rechercherEditCommande(buffer);

            g = traiterLigneEdition(buffer, ec, g);
            if (ec == ED_QUIT && verifier("de vouloir quitter le mode édition ") == VRAI)
                continuer = FAUX;
        }
    }
    while (continuer);

    return g;
}
