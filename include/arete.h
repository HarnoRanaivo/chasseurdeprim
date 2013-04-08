/**
 * \file arete.h
 * \brief Arêtes (header)
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
struct Arete
{
    Sommet * a;   /**<- Extrémité a de l'Arete. */
    Sommet * b;   /**<- Extrémité b de l'Arete. */
    Ent poids;    /**<- Poids de l'Arete. */
};

/**
 * \brief Arête d'extrémités a et b et de poids p.
 */
typedef struct Arete Arete;

/**
 * \brief Nouvelle Arete.
 * \relatesalso Arete
 * \param a Extrémité a de l'Arete.
 * \param b Extrémité b de l'Arete.
 * \param poids Poids de l'Arete.
 * \return (pointeur vers) Nouvelle Arete (\a a, \a b) de poids \a poids.
 */
Arete * aNouv(const Sommet * a, const Sommet * b, Ent poids);

/**
 * \brief Extrémité a de l'Arete.
 * \relatesalso Arete
 * \param a Arete.
 * \return ::Sommet à l'extrémité \a a de l'Arete \a a.
 */
Sommet * aA(const Arete * a);

/**
 * \brief Extrémité b de l'Arete.
 * \relatesalso Arete
 * \param a Arete.
 * \return ::Sommet à l'extrémité \a b de l'Arete \a a.
 */
Sommet * aB(const Arete * a);

/**
 * \brief Poids de l'Arete.
 * \relatesalso Arete
 * \param a Arete.
 * \return Poids de l'Arete \a a.
 */
Ent aPoids(const Arete * a);

/**
 * \brief Test d'égalité de deux Aretes, sans se préoccuper du poids.
 * \relatesalso Arete
 * \param a Arete.
 * \param s Extrémité.
 * \param t Autre extrémité.
 * \return #VRAI si les extrémités de l'Arete \a a correspondent à \a s et \a t, FAUX sinon.
 *
 * Le poids de l'Arete n'a pas d'importance. Compare les extrémités de \a a à \a s et \a t.
 */
Bool aAreteEgaleS(const Arete * a, const Sommet * s, const Sommet * t);

/**
 * \brief Test d'égalité de deux Aretes, sans se préoccuper du poids.
 * \relatesalso Arete
 * \param a Arete.
 * \param b Arete.
 * \return VRAI si les extrémités de a et b sont identiques, FAUX sinon.
 *
 * Les poids des Arete n'importent pas, on ne compare que les extrémités des Arete \a a et \a b. L'ordre des extrémités n'importe pas non plus.
 */
Bool aAreteEgaleS2(const Arete * a, const Arete * b);

/**
 * \brief Test d'égalité de deux Aretes, sensible au poids.
 * \relatesalso Arete
 * \param a Arete.
 * \param s Extrémité.
 * \param t Autre extrémité.
 * \param poids Poids.
 * \return VRAI si les extrémités de a correspondent à s et t et si le poids est le même, FAUX sinon.
 *
 * Compare les extrémités de l'Arete \a a à \a s et \a t et le poids de l'Arete à \a poids.
 */
Bool aAreteEgaleP(const Arete * a, const Sommet * s, const Sommet * t, Ent poids);

/**
 * \brief Test d'égalité de deux Aretes, sans se préoccuper du poids.
 * \relatesalso Arete
 * \param a Arete.
 * \param b Arete.
 * \return VRAI si les extrémités et les poids de a et b sont identiques, FAUX sinon.
 *
 * Compare les extrémités et les poids des Arete \a a et \a b.
 */
Bool aAreteEgaleP2(const Arete * a, const Arete * b);

/**
 * \brief Libérer une Arete.
 * \relatesalso Arete
 * \param a Arete à libérer.
 * \return NULL
 *
 * Libère la mémoire occupée par l'Arete a : libère aussi la mémoire occupée par les ::Sommet extrémités de \a a.
 */
Arete * aLiberer(Arete * a);

#endif /* __ARETE_H */
