/* This program is free software. It comes WITHOUT ANY WARRANTY, to
* the extent permitted by applicable law. You can redistribute it
* and/or modify it under the terms of the Do What The Fuck You Want
* To Public License, Version 2, as published by Sam Hocevar. See
* http://wtfpl.net for more details. */
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
#include "filearetetriee.h"
#include "arete.h"

/**
 * \brief Ajouter les arêtes incidentes à un sommet.
 * \relatesalso ListeArete
 * \param ft FileAreteTriee.
 * \param g Graphe.
 * \param cg Marquage des sommets.
 * \param s  Sommet.
 * \return FileAreteTriee.
 *
 * Ajouter les Arete incidentes à un ::Sommet \a s dans un Graphe \a g à la ::FileAreteTriee \a ft, en ne prenant que les Arete d'extrémités \a s et \a t pour tout sommet \a t n'étant pas marqué comme visité dans la CouleursGraphe \a cg.
 */
FileAreteTriee * ftAjouterAretesIncidentes(FileAreteTriee * ft, const Graphe * g, const CouleursGraphe * cg, const Sommet * s);

/**
 * \brief Calcul de l'arbre couvrant minimum d'un graphe connexe en partant d'un sommet.
 * \relatesalso Graphe
 * \param g Graphe.
 * \param s Sommet.
 * \return Arbre Couvrant Minimum
 */
Graphe * gArbreCouvrantMinimum(const Graphe * g, const Sommet * s);

#endif /* __PRIM_H */
