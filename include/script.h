/* This program is free software. It comes WITHOUT ANY WARRANTY, to
* the extent permitted by applicable law. You can redistribute it
* and/or modify it under the terms of the Do What The Fuck You Want
* To Public License, Version 2, as published by Sam Hocevar. See
* http://wtfpl.net for more details. */
/**
 * \file script.h
 * \brief Script (header)
 * \author Harenome RAZANAJATO
 */
#ifndef __SCRIPT_H
#define __SCRIPT_H

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
#include "prompt.h"
#include "edition.h"

/**
 * \brief Traiter la ligne de commande d'un script.
 * \relatesalso PromptCommande
 * \param ligne Ligne de commande entrée par l'utilisateur.
 * \param pc Commande.
 * \param d Données du programme.
 * \param fichier Script.
 * \return Nouvelles données du programme, si elles ont été modifiées.
 */
Donnees * traiterLigneCommandeNI(const char * ligne, PromptCommande pc, Donnees * d, FILE * fichier);

/**
 * \brief Gérer un script.
 * \param script Fichier contenant les instructions.
 */
void traiterFichier(const char * script);

/**
 * \brief Traiter la ligne de commande d'un script.
 * \relatesalso EditCommande
 * \param ligne Ligne de commande entrée par l'utilisateur.
 * \param ec Commande.
 * \param g Graphe.
 * \param fichier Script.
 * \return Nouveau graphe.
 */
Graphe * traiterLigneEditionNI(const char * ligne, EditCommande ec, Graphe * g);

/**
 * \brief Gérer un script, mode édition.
 * \param script Fichier contenant les instructions.
 */
Graphe * modeEditionNI(Graphe * g, FILE * fichier);

#endif /* __SCRIPT_H */
