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
Bool egalSom (Sommet a, Sommet b);

/**
 * \brief Retourne une copie de s, allouée dynamiquement.
 * \param s Sommet à copier.
 * \relatesalso Sommet
 * \return (pointeur vers) la copie de s, NULL en cas d'erreur.
 */
Sommet copieSommet(Sommet s);

#endif /* __SOMMET_H */
