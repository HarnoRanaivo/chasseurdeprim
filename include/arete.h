/**
 * \file arete.h
 * \brief Arete (header)
 * \author Harenome RAZANAJATO
 */
#ifndef __ARETE_H
#define __ARETE_H

#include <stdlib.h>
#include <stdio.h>

#include "base.h"
#include "sommet.h"

/**
 * \struct Arete
 * \brief Arête d'extrémités a et b et de poids p.
 */
/**
 * \typedef Arete
 * \brief Arête d'extrémités a et b et de poids p.
 */
typedef struct Arete
{
    Sommet a;   /**<- Extrémité a de l'arête. */
    Sommet b;   /**<- Extrémité b de l'arête. */
    Ent poids;  /**<- Poids de l'arête. */
} *Arete;

/**
 * \brief Nouvelle arête.
 * \relatesalso Arete
 * \param a Extrémité a de l'arête.
 * \param b Extrémité b de l'arête.
 * \param poids Poids de l'arête.
 * \return (pointeur vers) Nouvelle arête (a, b) de poids poids.
 */
Arete aNouv(const Sommet a, const Sommet b, Ent poids);

/**
 * \brief Extrémité a de l'arête.
 * \relatesalso Arete
 * \param a Arete.
 * \return Sommet à l'extrémité a de l'arête.
 */
Sommet aA(const Arete a);

/**
 * \brief Extrémité b de l'arête.
 * \relatesalso Arete
 * \param a Arete.
 * \return Sommet b l'extrémité a de l'arête.
 */
Sommet aB(const Arete a);

/**
 * \brief Poids de l'arête.
 * \relatesalso Arete
 * \param a Arete.
 * \return Poids de l'arête.
 */
Ent aPoids(const Arete a);

/**
 * \brief Test d'égalité de deux arêtes, sans se préoccuper du poids.
 * \relatesalso Arete
 * \param a Arete.
 * \param s Extrémité.
 * \param t Autre extrémité.
 * \return VRAI si les extrémités de a correspondent à s et t, FAUX sinon.
 */
Bool aAreteEgaleS(const Arete a, const Sommet s, const Sommet t);

/**
 * \brief Test d'égalité de deux arêtes, sans se préoccuper du poids.
 * \relatesalso Arete
 * \param a Arete.
 * \param b Arete.
 * \return VRAI si les extrémités de a et b sont identiques, FAUX sinon.
 */
Bool aAreteEgaleS2(const Arete a, const Arete b);

/**
 * \brief Test d'égalité de deux arêtes, sensible au poids.
 * \relatesalso Arete
 * \param a Arete.
 * \param s Extrémité.
 * \param t Autre extrémité.
 * \param poids Poids.
 * \return VRAI si les extrémités de a correspondent à s et t et si le poids est le même, FAUX sinon.
 */
Bool aAreteEgaleP(const Arete a, const Sommet s, const Sommet t, Ent poids);

/**
 * \brief Test d'égalité de deux arêtes, sans se préoccuper du poids.
 * \relatesalso Arete
 * \param a Arete.
 * \param b Arete.
 * \return VRAI si les extrémités et les poids de a et b sont identiques, FAUX sinon.
 */
Bool aAreteEgaleP2(const Arete a, const Arete b);

/**
 * \brief Libérer une arête.
 * \relatesalso Arete
 * \param a Arete à libérer.
 * \return NULL
 */
Arete aLiberer(Arete a);

#endif /* __ARETE_H */
