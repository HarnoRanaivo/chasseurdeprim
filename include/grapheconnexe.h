/* This program is free software. It comes WITHOUT ANY WARRANTY, to
* the extent permitted by applicable law. You can redistribute it
* and/or modify it under the terms of the Do What The Fuck You Want
* To Public License, Version 2, as published by Sam Hocevar. See
* http://wtfpl.net for more details. */
/**
 * \file grapheconnexe.h
 * \brief GrapheConnexes connexes (header)
 * \author Harenome RAZANAJATO
 */
#ifndef __GRAPHECONNEXE_H
#define __GRAPHECONNEXE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "base.h"
#include "sommet.h"
#include "adjacence.h"
#include "graphe.h"
#include "parcours.h"

/**
 * \brief GrapheConnexe
 */
typedef Graphe GrapheConnexe;

/**
 * \brief Nouveau ::GrapheConnexe.
 * \relatesalso Graphe
 * \return NULL
 */
GrapheConnexe * gcNouv(void);

/**
 * \brief Ajout d'un sommet dans un graphe connexe.
 * \relatesalso Graphe
 * \param g GrapheConnexe où ajouter le sommet.
 * \param s Sommet à ajouter.
 * \return GrapheConnexe.
 *
 * N'ajoute le ::Sommet dans le GrapheConnexe \a g que si le GrapheConnexe reste connexe après l'ajout : n'ajoute le ::Sommet que si \a g est vide ! (On considère qu'un Graphe ayant un seul ::Sommet est connexe.)
 */
GrapheConnexe * gcAjouterSommet(GrapheConnexe * g, const Sommet * s);

/**
 * \brief Ajout d'une arête dans un graphe connexe.
 * \relatesalso Graphe
 * \param g GrapheConnexe où ajouter l'arête.
 * \param a Éxtrémité de l'arête.
 * \param b Éxtrémité de l'arête.
 * \param p Poids de l'arête.
 * \pre gEstVide(g) || gEstConnexe(g)
 * \return GrapheConnexe.
 *
 * N'ajoute l'arête entre les ::Sommet \a a et \a b que si le ::GrapheConnexe \a g reste connexe apprès l'ajout de l'arête :
 * - Si aucun des deux ::Sommet n'existe, \a g reste intact.
 * - Si l'un des deux ::Sommet existe, on peut ajouter l'autre ::Sommet au ::GrapheConnexe avant d'ajouter l'arête.
 * - Si les deux ::Sommet existent, on peut ajouter l'arête.
 */
GrapheConnexe * gcAjouterArete(GrapheConnexe * g, const Sommet * a, const Sommet * b, Ent p);

/**
 * \brief Suppression d'un sommet dans un graphe connexe.
 * \relatesalso Graphe
 * \param g GrapheConnexe où supprimer le sommet.
 * \param s Sommet à supprimer.
 * \pre gEstConnexe(g)
 * \return GrapheConnexe.
 *
 * Supprime le ::Sommet \a s du ::GrapheConnexe \a g, en supprimant toutes les arêtes incidentes à \a s, si et seulement si \a g reste connexe.
 */
GrapheConnexe * gcSupprimerSommet(GrapheConnexe * g, const Sommet * s);

/**
 * \brief suppression d'une arête dans un graphe connexe.
 * \relatesalso Graphe
 * \param g GrapheConnexe où supprimer l'arête.
 * \param a Extrémité de l'arête.
 * \param b Autre extrémité de l'arête.
 * \pre gEstConnexe(g)
 * \return GrapheConnexe.
 *
 * Supprime l'arête entre les ::Sommet \a a et \a b, si et seulement si le ::GrapheConnexe \a g reste connexe.
 */
GrapheConnexe * gcSupprimerArete(GrapheConnexe * g, const Sommet * a, const Sommet * b);

/**
 * \brief Modification d'une arête dans un ::GrapheConnexe
 * \relatesalso Graphe
 * \param g GrapheConnexe où modifier l'arête.
 * \param a Extrémité de l'arête.
 * \param b Autre extrémité de l'arête.
 * \param p Nouveau poids de l'arête.
 * \pre gestconnexe(g)
 * \return grapheconnexe.
 */
GrapheConnexe * gcModifierArete(GrapheConnexe * g, const Sommet * a, const Sommet * b, Ent p);

#endif /* __GRAPHECONNEXE_H */
