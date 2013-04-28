/* This program is free software. It comes WITHOUT ANY WARRANTY, to
* the extent permitted by applicable law. You can redistribute it
* and/or modify it under the terms of the Do What The Fuck You Want
* To Public License, Version 2, as published by Sam Hocevar. See
* http://wtfpl.net for more details. */
/**
 * \file edition.h
 * \brief Prompt mode édition (header)
 * \author Harenome RAZANAJATO
 */
#ifndef __EDITION_H
#define __EDITION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "base.h"
#include "graphe.h"
#include "io.h"
#include "parcours.h"

/**
 * \enum EditCommande
 * \brief Alias pour les commandes du mode « édition ».
 */
typedef enum EditCommande
{
    ED_NOUV,        /**<- Nouveau graphe. */
    ED_AJS,         /**<- Ajouter un sommet. */
    ED_AJAR,        /**<- Ajouter une arête. */
    ED_MOD,         /**<- Modifier une arête. */
    ED_SUPS,        /**<- Supprimer un sommet. */
    ED_SUPAR,       /**<- Supprimer une arête. */
    ED_LSV,         /**<- Afficher la liste des voisins d'un sommet. */
    ED_LSI,         /**<- Afficher la liste des arêtes incidentes à un sommet. */
    ED_LSS,         /**<- Afficher la liste des sommets d'un graphe. */
    ED_LSA,         /**<- Afficher la liste des arêtes du graphe. */
    ED_CNX,         /**<- Tester la connexité d'un graphe. */
    ED_AIDE,        /**<- Aide. */
    ED_QUIT,        /**<- Quitter le mode édition. */
    ED_INCONNU,     /**<- Commande inconnue. */
} EditCommande;
/* ED_INCONNU *DOIT* se trouver en dernier. */

/**
 * \brief Afficher l'aide correspondant à une commande.
 * \relatesalso EditCommande
 * \param ec Commande.
 */
void afficherAideEditCommande(EditCommande ec);

/**
 * \brief Afficher l'aide du mode « édition ».
 */
void afficherAideEdition(void);

/**
 * \brief Rechercher la commande correspondante.
 * \relatesalso EditCommande
 * \param ligne Ligne de commande.
 * \return commande correspondante.
 */
EditCommande rechercherEditCommande(const char * ligne);

/**
 * \brief Traiter la ligne de commande entrée par l'utilisateur.
 * \relatesalso EditCommande
 * \param ligne Ligne de commande entrée par l'utilisateur.
 * \param ec Commande entrée par l'utilisateur.
 * \param g Graphe manipulé.
 * \return Le nouveau graphe, s'il a été modifié.
 */
Graphe * traiterLigneEdition(const char * ligne, EditCommande ec, Graphe * g);

/**
 * \brief Afficher le prompt du mode édition, et gérer les entrées utilisateur.
 * \param g Graphe manipulé
 * \return Le nouveau graphe, s'il a été modifié.
 */
Graphe * modeEdition(Graphe * g);

#endif /* __EDITION_H */
