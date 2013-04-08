/**
 * \file filearetetriee.h
 * \brief File triée d'arêtes (header)
 * \author Harenome RAZANAJATO
 */
#ifndef __FILEARETETRIEE_H
#define __FILEARETETRIEE_H

#include <stdlib.h>
#include <stdio.h>

#include "base.h"
#include "sommet.h"
#include "arete.h"
#include "listearete.h"

/**
 * \brief File triée par ordre croissant d'arêtes.
 */
typedef ListeArete FileAreteTriee;

/**
 * \brief Nouvelle file triée.
 * \relatesalso ListeArete
 * \return NULL
 */
FileAreteTriee * ftNouv(void);

/**
 * \brief Ajouter une arête dans la file triée.
 * \relatesalso ListeArete
 * \param f FileAreteTriee.
 * \param s Extrémité a de l'arête.
 * \param t Extrémité t de l'arête.
 * \param poids Poids de l'arête.
 * \return (pointeur vers) FileAreteTriee.
 *
 * Ajoute l'Arete entre \a s et \a t dans la ::FileAreteTriee \a f en gardant \a f triée selon les poids.
 */
FileAreteTriee * ftAjouterArete(FileAreteTriee * f, const Sommet * s, const Sommet * t, Ent poids);

#endif /* __FILEARETETRIEE_H */
