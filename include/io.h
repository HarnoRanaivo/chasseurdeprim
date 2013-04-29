/* This program is free software. It comes WITHOUT ANY WARRANTY, to
* the extent permitted by applicable law. You can redistribute it
* and/or modify it under the terms of the Do What The Fuck You Want
* To Public License, Version 2, as published by Sam Hocevar. See
* http://wtfpl.net for more details. */
/**
 * \file io.h
 * \brief Entrées/Sorties (header)
 * \author Meyer Jérémy
 */
 
#ifndef __IO_H
#define __IO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/stat.h>

#include "base.h"
#include "sommet.h"
#include "adjacence.h"
#include "graphe.h"

/**
 * \fn void sauvegarder_graphe (const Graphe * g, const char* destination)
 * \brief Permet de sauvegarder le graphe dans un fichier passé en argument
 * \param g (Graphe)
 * \param destination (fichier de sauvegarde)
 * \relatesalso Graphe
 * \return \b void
 */
void sauvegarder_graphe (const Graphe * g, const char* destination);

/**
 * \fn Graphe * charger_graphe (const char* source)
 * \brief Permet de charger un graphe dans un fichier texte
 * \param source (fichier de chargement)
 * \relatesalso Graphe
 * \return Graphe du fichier
 */
Graphe * charger_graphe (const char* source);

/**
 * \brief Afficher les arêtes d'un graphe.
 * \relatesalso Graphe
 * \param g Graphe.
 */
void afficherAretesGraphe(const Graphe * g);

/**
 * \brief Afficher les sommets d'un graphe.
 * \relatesalso Graphe
 * \param g Graphe.
 */
void afficherListeSommets(const Graphe * g);

/**
 * \brief Afficher les arêtes incidentes à un sommet.
 * \relatesalso Graphe
 * \param g Graphe.
 * \param s Sommet.
 */
void afficherAdjacence(const Graphe * g, const Sommet * s);

/**
 * \brief Afficher les voisins d'un sommet.
 * \relatesalso Graphe
 * \param g Graphe.
 * \param s Sommet.
 */
void afficherVoisins(const Graphe * g, const Sommet * s);

/**
 * \brief Vérification de l'intention de l'utilisateur.
 * \param chaine Complétion de « Êtes vous sûr %s ».
 * \return #VRAI si l'utilisateur confirme son choix, #FAUX sinon.
 */
Bool verifier(const char * chaine);

/**
 * \brief Vérifier l'existence d'un fichier.
 * \param nomfichier nom de fichier
 * \return #VRAI si le fichier existe, #FAUX sinon.
 */
Bool existeFichier(const char * nomfichier);

#endif /* __IO_H */
