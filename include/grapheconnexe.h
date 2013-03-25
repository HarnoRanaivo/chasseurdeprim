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
#include "liste.h"
#include "graphe.h"
#include "parcours.h"

/**
 * \typedef GrapheConnexe
 * \brief GrapheConnexe
 */
typedef Graphe GrapheConnexe;

/**
 * \brief Nouveau graphe.
 * \relatesalso graphe
 * \return NULL
 */
GrapheConnexe gcNouv(void);

/**
 * \brief Ajout d'un sommet dans un graphe.
 * \relatesalso GrapheConnexe
 * \param g GrapheConnexe où ajouter le sommet.
 * \param s Sommet à ajouter.
 * \return GrapheConnexe
 */
GrapheConnexe gcAjouterSommet(GrapheConnexe g, const Sommet s);

/**
 * \brief Ajout d'une arête dans un graphe.
 * \relatesalso GrapheConnexe
 * \param g GrapheConnexe où ajouter l'arête.
 * \param a Éxtrémité de l'arête.
 * \param b Éxtrémité de l'arête.
 * \param p Poids de l'arête.
 * \return GrapheConnexe
 */
GrapheConnexe gcAjouterArete(GrapheConnexe g, const Sommet a, const Sommet b, Ent p);

/**
 * \brief Suppression d'un sommet dans un graphe.
 * \relatesalso GrapheConnexe
 * \param g GrapheConnexe où supprimer le sommet.
 * \param s Sommet à supprimer.
 * \pre !gAArete(g, s).
 * \return GrapheConnexe
 */
GrapheConnexe gcSupprimerSommet(GrapheConnexe g, const Sommet s);

/**
 * \brief Suppression d'une arête dans un graphe.
 * \relatesalso GrapheConnexe
 * \param g GrapheConnexe où supprimer l'arête.
 * \param a Éxtrémité de l'arête.
 * \param b Éxtrémité de l'arête.
 * \return GrapheConnexe
 */
GrapheConnexe gcSupprimerArete(GrapheConnexe g, const Sommet a, const Sommet b);

/**
 * \brief Modification d'une arête dans un graphe.
 * \relatesalso GrapheConnexe
 * \param g GrapheConnexe où modifier l'arête.
 * \param a Éxtrémité de l'arête.
 * \param b Éxtrémité de l'arête.
 * \param p Nouveau poids de l'arête.
 * \return GrapheConnexe
 */
GrapheConnexe gcModifierArete(GrapheConnexe g, const Sommet a, const Sommet b, Ent p);

#endif /* __GRAPHECONNEXE_H */
