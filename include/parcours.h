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

CouleursGraphe gParcoursLargeur(Graphe g);

Bool gEstConnexe(Graphe g);

Bool gACycle(const Graphe g);

#endif /* __PARCOURS_H */
