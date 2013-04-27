/* This program is free software. It comes WITHOUT ANY WARRANTY, to
* the extent permitted by applicable law. You can redistribute it
* and/or modify it under the terms of the Do What The Fuck You Want
* To Public License, Version 2, as published by Sam Hocevar. See
* http://wtfpl.net for more details. */
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
 * \brief Sommet dans un Graphe (chaîne de caractères.)
 *
 * Un ::Sommet valide est une chaîne de caractères valide (donc terminée par '\\0').
 * Un ::Sommet vide est un (::Sommet *) égal à \c NULL.
 */
typedef Chaine Sommet;

/**
 * \brief Teste l'égalité entre deux ::Sommet.
 * \param a (::Sommet)
 * \param b (::Sommet)
 * \return \c VRAI si les ::Sommet sont égaux, \c FAUX sinon
 *
 * La fonction gère les ::Sommet vides.
 */
Bool egalSom (const Sommet * a, const Sommet * b);

/**
 * \brief Retourne une copie de \a s, allouée dynamiquement.
 * \param s ::Sommet à copier.
 * \return (pointeur vers) la copie de \a s, \c NULL en cas d'erreur.
 *
 * La fonction alloue de la mémoire et fait une copie du ::Sommet \a s. En cas d'erreur, un ::Sommet vide est retourné.
 */
Sommet * copieSommet(const Sommet * s);

/**
 * \brief Libérer un ::Sommet qui avait été alloué dynamiquement.
 * \param s ::Sommet à libérer.
 * \return \c NULL
 *
 * Libère la mémoire occupée par un ::Sommet et retourne \c NULL. Comportement similaire à free : gère les ::Sommet vides, mais pas les ::Sommet déjà libérés.
 * Il faut donc toujours affecter le retour à l'ancien pointeur du ::Sommet qu'on cherche à libérer.
 */
Sommet * libererSommet(Sommet * s);

/**
 * \brief Modifier un ::Sommet
 * \param s ::Sommet à modifier.
 * \param t Nouveau ::Sommet.
 * \return (pointeur vers) le nouveau ::Sommet. En cas d'erreur, \c NULL.
 *
 * Comportement similaire à realloc : Si la modification du ::Sommet s a fonctionné, le ::Sommet \a s sera libéré. Sinon, la fonction retourne un ::Sommet vide, et \a s reste intact.
 */
Sommet * modSommet(Sommet * s, const Sommet * t);

#endif /* __SOMMET_H */
