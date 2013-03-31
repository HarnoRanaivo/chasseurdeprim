/**
 * \file filetriee.h
 * \brief File triée d'arêtes (header)
 * \author Harenome RAZANAJATO
 */
#ifndef __FILETRIEE_H
#define __FILETRIEE_H

#include <stdlib.h>
#include <stdio.h>

#include "base.h"
#include "sommet.h"
#include "arete.h"

/**
 * \struct FileTriee
 * \brief File triée par ordre croissant d'arêtes.
 */
/**
 * \typedef FileTriee
 * \brief File triée par ordre croissant d'arêtes.
 */
typedef struct FileTriee
{
    Arete arete;                    /**<- Arête. */
    struct FileTriee * suivante;    /**<- Arête suivante dans la file. */
} *FileTriee;

/**
 * \brief Nouvelle file triée.
 * \relatesalso FileTriee
 * \return NULL
 */
FileTriee ftNouv(void);

/**
 * \brief Ajouter une arête dans la file triée.
 * \relatesalso FileTriee
 * \param f FileTriee.
 * \param s Extrémité a de l'arête.
 * \param t Extrémité t de l'arête.
 * \param poids Poids de l'arête.
 * \return (pointeur vers) FileTriee.
 */
FileTriee ftAjouterArete(FileTriee f, const Sommet s, const Sommet t, Ent poids);

/**
 * \brief Supprimer l'arête en tête de file.
 * \relatesalso FileTriee
 * \param f FileTriee.
 * \return (pointeur vers) FileTriee.
 */
FileTriee ftSupprimerTete(FileTriee f);

/**
 * \brief Supprimer une arête dans la file.
 * \relatesalso FileTriee
 * \param f FileTriee.
 * \param a Extrémité de l'arête à supprimer.
 * \param b Autre extrémité de l'arête à supprimer.
 * \return (pointeur vers) FileTriee.
 */
FileTriee ftSupprimerArete(FileTriee f, const Sommet a, const Sommet b);

/**
 * \brief Test de vacuité d'une file triée d'arêtes.
 * \relatesalso FileTriee
 * \param f FileTriee.
 * \return VRAI si la file est vide, FAUX sinon.
 */
Bool ftEstVide(const FileTriee f);

/**
 * \brief Test d'existence d'une arête.
 * \relatesalso FileTriee
 * \param f FileTriee.
 * \param a Extrémité de l'arête.
 * \param b Autre extrémité de l'arête.
 * \return VRAI si l'arête existe, FAUX sinon.
 */
Bool ftExisteArete(const FileTriee f, const Sommet a, const Sommet b);

/**
 * \brief Nombre d'arêtes dans la file.
 * \relatesalso FileTriee
 * \param f FileTriee.
 * \return Nombre d'arêtes.
 */
Nat ftNombreAretes(const FileTriee f);

/**
 * \brief Arête en tête de file.
 * \relatesalso FileTriee
 * \param f FileTriee.
 * \pre !ftEstVide(f)
 * \return Arête.
 */
Arete ftAreteTete(const FileTriee f);

/**
 * \brief Arête suivante dans la file.
 * \relatesalso FileTriee
 * \param f FileTriee.
 * \return (pointeur vers) Arête suivante.
 */
FileTriee ftSuivante(const FileTriee f);

/**
 * \brief Libérer une file triée d'arêtes.
 * \relatesalso FileTriee
 * \param f FileTriee.
 * \return NULL
 */
FileTriee ftLiberer(FileTriee f);

#endif /* __FILETRIEE_H */
