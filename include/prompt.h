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

/**
 * \enum PromptCommande
 * \brief Alias pour les commandes.
 */
typedef enum PromptCommande
{
    PC_INCONNU,     /**<- Commande inconnue. */
    PC_CHG,         /**<- Charger un graphe. */
    PC_SAV,         /**<- Sauvegarder le graphe. */
    PC_MOD,         /**<- Modifier une arête. */
    PC_AJAR,        /**<- Ajouter une arête. */
    PC_SUPAR,       /**<- Supprimer une arête. */
    PC_SUPSOM,      /**<- Supprimer un sommet. */
    PC_CAL,         /**<- Calculer l'arbre couvrant minimum. */
    PC_AFF,         /**<- « Afficher » le graphe. */
    PC_AIDE,        /**<- Aide. */
    PC_QUIT         /**<- Quitter. */
} PromptCommande;

/**
 * \brief Liste des PromptCommande.
 */
static const PromptCommande PC_LISTE[] =
{
    PC_CHG, PC_SAV, PC_MOD, PC_AJAR, PC_SUPAR, PC_SUPSOM, PC_AJAR, PC_SUPAR,
    PC_SUPSOM, PC_CAL, PC_AFF, PC_AIDE, PC_QUIT, PC_INCONNU
};

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
 * \brief Vérification de l'intention de l'utilisateur.
 * \return #VRAI si l'utilisateur confirme son choix, #FAUX sinon.
 */
Bool verifier(void);

/**
 * \brief Compter le nombre de mots dans une chaîne de caractères.
 * \param chaine Chaîne de caractères.
 * \pre \a chaine est une chaîne de caractères valide terminée par \c '\0'.
 * \return Nombre de mots.
 */
int compterMots(const char * chaine);

/**
 * \brief Afficher l'aide correspondant à une commande.
 * \relatesalso PromptCommande
 * \param pc Commande.
 */
void afficherAideCommande(PromptCommande pc);

/**
 * \brief Afficher l'aide du programme.
 */
void afficherAide(void);

/**
 * \brief Traiter la ligne de commande entrée par l'utilisateur.
 * \relatesalso Donnees
 * \param ligne Ligne de commande entrée par l'utilisateur.
 * \param pc Commande entrée par l'utilisateur.
 * \param d Données du programme.
 * \return Nouvelles données du programme, si elles ont été modifiées.
 */
Donnees * traiterLigneCommande(const char * ligne, PromptCommande pc, Donnees * d);

/**
 * \brief Afficher un prompt et gérer les entrées de l'utilisateur.
 */
void prompt(void);

#endif /* __PROMPT_H */
