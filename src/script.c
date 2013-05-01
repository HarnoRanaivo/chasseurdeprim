/* This program is free software. It comes WITHOUT ANY WARRANTY, to
* the extent permitted by applicable law. You can redistribute it
* and/or modify it under the terms of the Do What The Fuck You Want
* To Public License, Version 2, as published by Sam Hocevar. See
* http://wtfpl.net for more details. */
/**
 * \file script.c
 * \brief Script (code)
 * \author Harenome RAZANAJATO
 */
#include "script.h"

static int numero = 1;

void ligneIncorrecte(const char * ligne)
{
    char buffer[32];
    sscanf(ligne, "%31s", buffer);
    printf("%s, ligne %d : Arguments incorrects.\n", buffer, numero);
}

Donnees * traiterLigneCommandeNI(const char * ligne, PromptCommande pc, Donnees * d, FILE * fichier)
{
    char buffer1[481] = { '\0' };
    char buffer2[100] = { '\0' };
    int poids;

    switch (pc)
    {
        case PC_NOUV :
            if (compterMots(ligne) == 1)
            {
                d->graphe = gLiberer(d->graphe);
                d->arbre = gLiberer(d->arbre);
                d->graphe = gNouv();
                d->sauvegarde = VRAI;
            }
            else
                ligneIncorrecte(ligne);
            break;

        case PC_CHG :
            if (compterMots(ligne) == 2 && sscanf(ligne, "%*s %480s", buffer1) == 1)
            {
                d->graphe = gLiberer(d->graphe);
                d->arbre = gLiberer(d->arbre);
                d->graphe = charger_graphe(buffer1);
                d->sauvegarde = VRAI;
            }
            else
                ligneIncorrecte(ligne);
            break;

        case PC_SAV :
            if (compterMots(ligne) == 2
                && sscanf(ligne, "%*s %480s", buffer1) == 1
                && !existeFichier(buffer1)
               )
            {
                sauvegarder_graphe(d->graphe, buffer1);
                d->sauvegarde = VRAI;
            }
            else
                ligneIncorrecte(ligne);
            break;

        case PC_MOD :
            if (compterMots(ligne) == 4
                && sscanf(ligne, "%*s %99s %99s %d", buffer1, buffer2, &poids) == 3
                && gExisteArete(d->graphe, buffer1, buffer2)
               )
            {
                d->graphe = gcModifierArete(d->graphe, buffer1, buffer2, poids);
                d->arbre = gLiberer(d->arbre);
                d->sauvegarde = FAUX;
            }
            else
                ligneIncorrecte(ligne);
            break;

        case PC_AJAR :
            if (compterMots(ligne) == 4
                && sscanf(ligne, "%*s %99s %99s %d", buffer1, buffer2, &poids) == 3
                && !gExisteArete(d->graphe, buffer1, buffer2)
               )
            {
                d->graphe = gcAjouterArete(d->graphe, buffer1, buffer2, poids);
                d->arbre = gLiberer(d->arbre);
                d->sauvegarde = FAUX;
            }
            else
                ligneIncorrecte(ligne);
            break;

        case PC_SUPAR :
            if (compterMots(ligne) == 3
                && sscanf(ligne, "%*s %99s %99s", buffer1, buffer2) == 2
                && gExisteArete(d->graphe, buffer1, buffer2)
               )
            {
                d->graphe = gcSupprimerArete(d->graphe, buffer1, buffer2);
                d->arbre = gLiberer(d->arbre);
                d->sauvegarde = FAUX;
            }
            else
                ligneIncorrecte(ligne);
            break;

        case PC_SUPSOM :
            if (compterMots(ligne) == 2
                && sscanf(ligne, "%*s %99s", buffer1) == 1
                && gExisteSommet(d->graphe, buffer1)
               )
            {
                d->graphe = gcSupprimerSommet(d->graphe, buffer1);
                d->arbre = gLiberer(d->arbre);
                d->sauvegarde = FAUX;
            }
            else
                ligneIncorrecte(ligne);
            break;

        case PC_CAL :
            if (compterMots(ligne) == 2
                && sscanf(ligne, "%*s %99s", buffer1) == 1
                && !gEstVide(d->graphe)
                && gExisteSommet(d->graphe, buffer1)
               )
            {
                d->arbre = gLiberer(d->arbre);
                d->arbre = gArbreCouvrantMinimum(d->graphe, buffer1);
            }
            else
                ligneIncorrecte(ligne);
            break;

        case PC_AFF :
            if (compterMots(ligne) == 2
                && sscanf(ligne, "%*s %480s", buffer1) == 1
                && !gEstVide(d->graphe)
                && !existeFichier(buffer1)
               )
            {
                gGenererLatex(d->graphe, d->arbre, buffer1);
            }
            else
                ligneIncorrecte(ligne);
            break;

        case PC_LSV :
            break;

        case PC_LSI :
            break;

        case PC_LSS :
            break;

        case PC_LSA :
            break;

        case PC_EDIT :
            {
                Graphe * g = modeEditionNI(gCopier(d->graphe), fichier);
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
            break;

        case PC_QUIT :
            break;

        case PC_INCONNU :

        default :
            sscanf(ligne, "%s", buffer1);
            printf("%s, ligne %d : Commande inconnue.\n", buffer1, numero);
            break;
    }

    return d;
}

void traiterFichier(const char * script)
{
    Donnees * d;
    FILE * fichier;

    /* Le reste du programme ne peut pas fonctionner sans d. */
    if ((d = MALLOC(d)) == NULL)
    {
        perror("malloc");
        exit(EX_OSERR);
    }

    if ((fichier = fopen(script, "r")) == NULL)
    {
        free(d);
        perror("fopen");
        exit(EX_NOINPUT);
    }

    d->graphe = gNouv();
    d->arbre = gNouv();
    d->sauvegarde = VRAI;

    Bool continuer = VRAI;

    do
    {
        int succes;
        char buffer[512] = { '\0' };
        /* buffer est initialisé à '\0', car les *scanf ne rajoutent ce '\0'
         * que pour le format %s. Avec le format %c ou une expression, ce
         * '\0' doit être ajouté ultérieurement, si on souhaite travailler
         * sur des chaînes de caractères valides.
         */

        /* Lecture des entrées de l'utilisateur. */
        succes = fscanf(fichier, "%511[^\n]%*[\n]", buffer);

        if (succes == 1)
        {
            PromptCommande pc = rechercherPromptCommande(buffer);

            d = traiterLigneCommandeNI(buffer, pc, d, fichier);
            if (pc == PC_QUIT)
            {
                d->graphe = gLiberer(d->graphe);
                d->arbre = gLiberer(d->arbre);
                free(d);
                continuer = FAUX;
            }
        }
        else if (succes == EOF)
            continuer = FAUX;

        numero++;
    }
    while (continuer);
}

Graphe * traiterLigneEditionNI(const char * ligne, EditCommande ec, Graphe * g)
{
    char buffer1[481] = { '\0' };
    char buffer2[100] = { '\0' };
    int poids;

    switch (ec)
    {
        case ED_NOUV :
            if (compterMots(ligne) == 1)
            {
                g = gLiberer(g);
                g = gNouv();
            }
            else
                ligneIncorrecte(ligne);
            break;

        case ED_AJS :
            if (compterMots(ligne) == 2
                && sscanf(ligne, "%*s %99s", buffer1) == 1
                && !gExisteSommet(g, buffer1)
               )
                g = gAjouterSommet(g, buffer1);
            else
                ligneIncorrecte(ligne);
            break;

        case ED_AJAR :
            if (compterMots(ligne) == 4
                && sscanf(ligne, "%*s %99s %99s %d", buffer1, buffer2, &poids) == 3
                && !gExisteArete(g, buffer1, buffer2)
               )
                g = gAjouterArete(g, buffer1, buffer2, poids);
            else
                ligneIncorrecte(ligne);
            break;

        case ED_MOD :
            if (compterMots(ligne) == 4
                && sscanf(ligne, "%*s %99s %99s %d", buffer1, buffer2, &poids) == 3
                && gExisteArete(g, buffer1, buffer2)
               )
                g = gModifierArete(g, buffer1, buffer2, poids);
            else
                ligneIncorrecte(ligne);
            break;

        case ED_SUPS :
            if (compterMots(ligne) == 2
                && sscanf(ligne, "%*s %99s", buffer1) == 1
                && gExisteSommet(g, buffer1)
               )
                g = gSupprimerSommet(g, buffer1);
            else
                ligneIncorrecte(ligne);
            break;

        case ED_SUPAR :
            if (compterMots(ligne) == 3
                && sscanf(ligne, "%*s %99s %99s", buffer1, buffer2) == 2
                && gExisteArete(g, buffer1, buffer2)
               )
                g = gSupprimerArete(g, buffer1, buffer2);
            else
                ligneIncorrecte(ligne);
            break;

        case ED_LSV :
            break;

        case ED_LSI :
            break;

        case ED_LSS :
            break;

        case ED_LSA :
            break;

        case ED_CNX :
            break;

        case ED_AIDE :
            break;

        case ED_QUIT :
            break;

        case ED_INCONNU :

        default :
            sscanf(ligne, "%s", buffer1);
            printf("%s, ligne %d : Commande inconnue.\n", buffer1, numero);
            break;
    }

    return g;
}

Graphe * modeEditionNI(Graphe * g, FILE * fichier)
{
    Bool continuer = VRAI;

    do
    {
        int succes;
        char buffer[512] = { '\0' };

        succes = fscanf(fichier, "%511[^\n]%*[\n]", buffer);

        if (succes == 1)
        {
            EditCommande ec = rechercherEditCommande(buffer);

            g = traiterLigneEdition(buffer, ec, g);
            if (ec == ED_QUIT)
                continuer = FAUX;
        }
        else if (succes == EOF)
            continuer = FAUX;

        numero++;
    }
    while (continuer);

    return g;
}
