/**
 * \file sommet.h
 * \brief Gestion de la sorte Sommet (header)
 * \author Meyer Jérémy
 */


#ifndef __SOMMET_H
#define __SOMMET_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "base.h"

/**
 * \typedef Sommet
 * \brief Sommet (chaîne de caractères.)
 */
typedef Chaine Sommet;

/**
 * \fn Bool egalSom (Sommet a, Sommet b)
 * \brief Teste l'égalité entre deux sommets.
 * \param a (Sommet)
 * \param b (Sommet)
 * \relatesalso Sommet
 * \return VRAI si les sommets sont égaux, FAUX sinon
 */
Bool egalSom (const Sommet * a, const Sommet * b);

/**
 * \brief Retourne une copie de s, allouée dynamiquement.
 * \param s Sommet à copier.
 * \relatesalso Sommet
 * \return (pointeur vers) la copie de s, NULL en cas d'erreur.
 */
Sommet * copieSommet(const Sommet * s);

/**
 * \brief Libérer un sommet qui avait été alloué dynamiquement.
 * \param s Sommet à libérer.
 * \relatesalso Sommet
 * \return NULL
 */
Sommet * libererSommet(Sommet * s);

/**
 * \brief Modifier un sommet
 * \param s Sommet à modifier.
 * \param t Nouveau sommet.
 * \relatesalso Sommet
 * \return (pointeur vers) le nouveau sommet, s sera libéré. En cas d'erreur, NULL (il ne faut pas écraser s directement).
 */
Sommet * modSommet(Sommet * s, const Sommet * t);

#endif /* __SOMMET_H */
