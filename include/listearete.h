/**
 * \file listearete.h
 * \brief Liste d'arêtes (header)
 * \author Harenome RAZANAJATO
 */
#ifndef __LISTEARETE_H
#define __LISTEARETE_H

#include <stdlib.h>
#include <stdio.h>

#include "base.h"
#include "sommet.h"
#include "arete.h"

/**
 * \struct ListeArete
 * \brief Liste d'arêtes.
 */
/**
 * \typedef ListeArete 
 * \brief Liste d'arêtes.
 */
typedef struct ListeArete
{
    Arete * arete;                  /**<- Arête. */
    struct ListeArete * suivante;    /**<- Arête suivante dans la file. */
} ListeArete;

/**
 * \brief Nouvelle liste d'arêtes.
 * \relatesalso ListeArete
 * \return NULL
 */
ListeArete * larNouv(void);

/**
 * \brief Ajouter une arête dans la file liste.
 * \relatesalso ListeArete
 * \param f ListeArete.
 * \param s Extrémité a de l'arête.
 * \param t Extrémité t de l'arête.
 * \param poids Poids de l'arête.
 * \return (pointeur vers) ListeArete.
 */
ListeArete * larAjouterAreteTete(ListeArete * l, const Sommet * a, const Sommet * b, Ent poids);

/**
 * \brief Supprimer l'arête en tête de liste.
 * \relatesalso ListeArete
 * \param f ListeArete.
 * \return (pointeur vers) ListeArete.
 */
ListeArete * larSupprimerTete(ListeArete * l);

/**
 * \brief Supprimer une arête dans la liste.
 * \relatesalso ListeArete
 * \param f ListeArete.
 * \param a Extrémité de l'arête à supprimer.
 * \param b Autre extrémité de l'arête à supprimer.
 * \return (pointeur vers) ListeArete.
 */
ListeArete * larSupprimerArete(ListeArete * l, const Sommet * a, const Sommet * b);

/**
 * \brief Test de vacuité d'une liste d'arêtes.
 * \relatesalso ListeArete
 * \param f ListeArete.
 * \return VRAI si la file est vide, FAUX sinon.
 */
Bool larEstVide(const ListeArete * l);

/**
 * \brief Test d'existence d'une arête.
 * \relatesalso ListeArete
 * \param f ListeArete.
 * \param a Extrémité de l'arête.
 * \param b Autre extrémité de l'arête.
 * \return VRAI si l'arête existe, FAUX sinon.
 */
Bool larExisteArete(const ListeArete * l, const Sommet * a, const Sommet * b);

/**
 * \brief Nombre d'arêtes dans la liste.
 * \relatesalso ListeArete
 * \param f ListeArete.
 * \return Nombre d'arêtes.
 */
Nat larNombreAretes(const ListeArete * l);

/**
 * \brief Arête en tête de liste.
 * \relatesalso ListeArete
 * \param f ListeArete.
 * \pre !larEstVide(f)
 * \return Arête.
 */
Arete * larAreteTete(const ListeArete * l);

/**
 * \brief Pointeur vers la sous-liste commençant par l'arête a,b
 * \relatesalso ListeArete
 * \param f ListeArete.
 * \return (pointeur vers) Sous-liste commençant par (a, b)
 */
ListeArete * larPArete(const ListeArete *l, const Sommet * a, const Sommet *b);

/**
 * \brief Arête suivante dans la liste.
 * \relatesalso ListeArete
 * \param f ListeArete.
 * \return (pointeur vers) Arête suivante.
 */
ListeArete * larSuivante(const ListeArete * l);

/**
 * \brief Libérer une liste d'arêtes.
 * \relatesalso ListeArete
 * \param f ListeArete.
 * \return NULL
 */
ListeArete * larLiberer(ListeArete * l);

#endif /* __LISTEARETE_H */
