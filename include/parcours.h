/* This program is free software. It comes WITHOUT ANY WARRANTY, to
* the extent permitted by applicable law. You can redistribute it
* and/or modify it under the terms of the Do What The Fuck You Want
* To Public License, Version 2, as published by Sam Hocevar. See
* http://wtfpl.net for more details. */
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
 * \return Liste des ::Sommet marqués par le parcours.
 */
CouleursGraphe * gParcoursLargeur(const Graphe * g);

/**
 * \brief Test de connexité d'un graphe.
 * \relatesalso Graphe
 * \param g Graphe.
 * \return #VRAI si le Graphe est connexe, #FAUX sinon.
 */
Bool gEstConnexe(const Graphe * g);

/**
 * \brief Test d'existence de cycles dans un graphe.
 * \relatesalso Graphe
 * \param g Graphe.
 * \return #VRAI si le Graphe contient des cycles, #FAUX sinon.
 */
Bool gACycle(const Graphe * g);

#endif /* __PARCOURS_H */
