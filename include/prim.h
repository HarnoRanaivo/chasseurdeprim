/**
 * \file prim.h
 * \brief Algorithme de Prim (header)
 * \author Harenome RAZANAJATO
 */
#ifndef __PRIM_H
#define __PRIM_H

#include <stdlib.h>
#include <stdio.h>

#include "base.h"
#include "sommet.h"
#include "graphe.h"
#include "coloration.h"
#include "filetriee.h"
#include "arete.h"

FileTriee pAjouterAretesIncidentes(FileTriee ft, const Graphe g, const CouleursGraphe cg, const Sommet s);

Graphe pArbreCouvrantMinimum(const Graphe g, const Sommet s);

#endif /* __PRIM_H */
