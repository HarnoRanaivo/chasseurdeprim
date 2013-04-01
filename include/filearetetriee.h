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

/**
 * \struct FileAreteTriee
 * \brief File triée par ordre croissant d'arêtes.
 */
/**
 * \typedef FileAreteTriee
 * \brief File triée par ordre croissant d'arêtes.
 */
typedef struct FileAreteTriee
{
    Arete * arete;                  /**<- Arête. */
    struct FileAreteTriee * suivante;    /**<- Arête suivante dans la file. */
} FileAreteTriee;

/**
 * \brief Nouvelle file triée.
 * \relatesalso FileAreteTriee
 * \return NULL
 */
FileAreteTriee * ftNouv(void);

/**
 * \brief Ajouter une arête dans la file triée.
 * \relatesalso FileAreteTriee
 * \param f FileAreteTriee.
 * \param s Extrémité a de l'arête.
 * \param t Extrémité t de l'arête.
 * \param poids Poids de l'arête.
 * \return (pointeur vers) FileAreteTriee.
 */
FileAreteTriee * ftAjouterArete(FileAreteTriee * f, const Sommet * s, const Sommet * t, Ent poids);

/**
 * \brief Supprimer l'arête en tête de file.
 * \relatesalso FileAreteTriee
 * \param f FileAreteTriee.
 * \return (pointeur vers) FileAreteTriee.
 */
FileAreteTriee * ftSupprimerTete(FileAreteTriee * f);

/**
 * \brief Supprimer une arête dans la file.
 * \relatesalso FileAreteTriee
 * \param f FileAreteTriee.
 * \param a Extrémité de l'arête à supprimer.
 * \param b Autre extrémité de l'arête à supprimer.
 * \return (pointeur vers) FileAreteTriee.
 */
FileAreteTriee * ftSupprimerArete(FileAreteTriee * f, const Sommet * a, const Sommet * b);

/**
 * \brief Test de vacuité d'une file triée d'arêtes.
 * \relatesalso FileAreteTriee
 * \param f FileAreteTriee.
 * \return VRAI si la file est vide, FAUX sinon.
 */
Bool ftEstVide(const FileAreteTriee * f);

/**
 * \brief Test d'existence d'une arête.
 * \relatesalso FileAreteTriee
 * \param f FileAreteTriee.
 * \param a Extrémité de l'arête.
 * \param b Autre extrémité de l'arête.
 * \return VRAI si l'arête existe, FAUX sinon.
 */
Bool ftExisteArete(const FileAreteTriee * f, const Sommet * a, const Sommet * b);

/**
 * \brief Nombre d'arêtes dans la file.
 * \relatesalso FileAreteTriee
 * \param f FileAreteTriee.
 * \return Nombre d'arêtes.
 */
Nat ftNombreAretes(const FileAreteTriee * f);

/**
 * \brief Arête en tête de file.
 * \relatesalso FileAreteTriee
 * \param f FileAreteTriee.
 * \pre !ftEstVide(f)
 * \return Arête.
 */
Arete * ftAreteTete(const FileAreteTriee * f);

/**
 * \brief Arête suivante dans la file.
 * \relatesalso FileAreteTriee
 * \param f FileAreteTriee.
 * \return (pointeur vers) Arête suivante.
 */
FileAreteTriee * ftSuivante(const FileAreteTriee * f);

/**
 * \brief Libérer une file triée d'arêtes.
 * \relatesalso FileAreteTriee
 * \param f FileAreteTriee.
 * \return NULL
 */
FileAreteTriee * ftLiberer(FileAreteTriee * f);

#endif /* __FILEARETETRIEE_H */
