/* This program is free software. It comes WITHOUT ANY WARRANTY, to
* the extent permitted by applicable law. You can redistribute it
* and/or modify it under the terms of the Do What The Fuck You Want
* To Public License, Version 2, as published by Sam Hocevar. See
* http://wtfpl.net for more details. */
/**
 * \file prompt.h
 * \brief Prompt (header)
 * \author Harenome RAZANAJATO
 */
#ifndef __PROMPT_H
#define __PROMPT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sysexits.h>

#include "base.h"
#include "graphe.h"
#include "grapheconnexe.h"
#include "io.h"
#include "prim.h"
#include "generation.h"
#include "parcours.h"
#include "edition.h"

/**
 * \enum PromptCommande
 * \brief Alias pour les commandes du prompt.
 */
typedef enum PromptCommande
{
    PC_NOUV,        /**<- Nouveau graphe. */
    PC_CHG,         /**<- Charger un graphe. */
    PC_SAV,         /**<- Sauvegarder le graphe. */
    PC_MOD,         /**<- Modifier une arête. */
    PC_AJAR,        /**<- Ajouter une arête. */
    PC_SUPAR,       /**<- Supprimer une arête. */
    PC_SUPSOM,      /**<- Supprimer un sommet. */
    PC_CAL,         /**<- Calculer l'arbre couvrant minimum. */
    PC_AFF,         /**<- « Afficher » le graphe. */
    PC_LSV,         /**<- Afficher la liste des voisins d'un sommet. */
    PC_LSI,         /**<- Afficher la liste des arêtes incidentes à un sommet. */
    PC_LSS,         /**<- Afficher la liste des sommets du graphe. */
    PC_LSA,         /**<- Afficher la liste des arêtes du graphe. */
    PC_EDIT,        /**<- Entrer en mode « édition ». */
    PC_AIDE,        /**<- Aide. */
    PC_QUIT,        /**<- Quitter. */
    PC_INCONNU,     /**<- Commande inconnue. */
} PromptCommande;
/* PC_INCONNU *DOIT* se trouver en dernier. */

/**
 * \struct Donnees
 * \brief Stockage des données temporaires du programme.
 */
typedef struct Donnees
{
    Graphe * graphe;
    Graphe * arbre;
    Bool sauvegarde;
} Donnees;

/**
 * \brief Afficher l'aide correspondant à une commande.
 * \relatesalso PromptCommande
 * \param pc Commande.
 */
void afficherAidePromptCommande(PromptCommande pc);

/**
 * \brief Afficher l'aide du programme.
 */
void afficherPromptAide(void);

/**
 * \brief Rechercher la commande correspondante.
 * \relatesalso PromptCommande
 * \param ligne Ligne de commande.
 * \return commande correspondante.
 */
PromptCommande rechercherPromptCommande(const char * ligne);

/**
 * \brief Traiter la ligne de commande entrée par l'utilisateur.
 * \relatesalso PromptCommande
 * \param ligne Ligne de commande entrée par l'utilisateur.
 * \param pc Commande entrée par l'utilisateur.
 * \param d Données du programme.
 * \return Nouvelles données du programme, si elles ont été modifiées.
 */
Donnees * traiterLigneCommande(const char * ligne, PromptCommande pc, Donnees * d);

/**
 * \brief Afficher un prompt et gérer les entrées de l'utilisateur.
 */
void afficherPrompt(void);

#endif /* __PROMPT_H */
