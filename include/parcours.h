/**
 * \file parcours.h
 * \brief Parcours d'un graphe (header)
 * \author Harenome RAZANAJATO
 */

#ifndef __PARCOURS_H
#define __PARCOURS_H

#include <stdio.h>
#include <stdlib.h>

#include "base.h"
#include "sommet.h"
#include "graphe.h"
#include "coloration.h"

/**
 * \brief Parcours en largeur d'un graphe
 * \param g Graphe.
 * \return Sommets marqués par le parcours.
 */
CouleursGraphe gParcoursLargeur(Graphe g);

/**
 * \brief Test de connexité d'un graphe.
 * \relatesalso Graphe
 * \param g Graphe.
 * \return VRAI si le graphe est connexe, FAUX sinon.
 */
Bool gEstConnexe(Graphe g);

/**
 * \brief Test d'existence de cycles dans un graphe.
 * \relatesalso Graphe
 * \param g Graphe.
 * \return VRAI si le graphe contient des cycles, FAUX sinon.
 */
Bool gACycle(const Graphe g);

#endif /* __PARCOURS_H */
