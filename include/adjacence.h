/**
 * \file adjacence.h
 * \brief Gestion des listes d'adjacence (header)
 * \author Meyer Jérémy
 */

#ifndef __ADJACENCE_H
#define __ADJACENCE_H

#include "sommet.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

/**
 * \struct ListeAdjacence
 * \brief Structure des listes d'arêtes par rapport à un sommet.
 *
 * Liste d'adjacence d'un ::Sommet donné dans un Graphe :
 * - #v est un voisin de ce ::Sommet
 * - #poids est le poids de l'arête entre ce ::Sommet et #v.
 *
 * Les générateurs sont :
 * - listnouv()
 * - lajar()
 * - lmod()
 * - lcopie()
 *
 * Les destructeurs sont :
 * - lsupar()
 * - lliberer()
 *
 * Les sélécteurs sont :
 * - lest_vide()
 * - lexar()
 * - lpoids()
 * - ltaille()
 * - lega()
 * - lsuiv()
 * - lsommet_tete()
 * - lpoids_tete()
 */
struct ListeAdjacence{
	struct ListeAdjacence * s; /**<- Pointeur sur la structure de liste*/
	Ent poids; /**<- Poids de l'arête*/
	Sommet * v; /**<- Sommet de l'arête*/
};

/**
 * \brief Structure des listes d'arêtes par rapport à un sommet.
 */
typedef struct ListeAdjacence ListeAdjacence;

/**
 * \fn ListeAdjacence * listnouv ()
 * \brief Crée une nouvelle ListeAdjacence vide.
 * \relatesalso ListeAdjacence
 * \return ListeAdjacence vide.
 */
ListeAdjacence * listnouv ();
 
/**
 * \fn ListeAdjacence * lajar (ListeAdjacence * l, const Sommet * s, Ent x)
 * \brief Ajoute une arête à la liste avec son poids.
 * \param l ListeAdjacence.
 * \param s Deuxième ::Sommet.
 * \param x Poids de l'arête.
 * \relatesalso ListeAdjacence
 * \return ListeAdjacence \a l + ::Sommet \a s
 */
ListeAdjacence * lajar (ListeAdjacence * l, const Sommet * s, Ent x);

/**
 * \fn ListeAdjacence * lsupar (ListeAdjacence * l, const Sommet * s)
 * \brief Supprime une arête de la ListeAdjacence \a l 
 * \param l ListeAdjacence.
 * \param s Deuxième ::Sommet de l'arête à supprimer.
 * \relatesalso ListeAdjacence
 * \return \a l sans l'arête \a s
 */
ListeAdjacence * lsupar (ListeAdjacence * l, const Sommet * s);

/**
 * \fn Bool lest_vide (const ListeAdjacence * l)
 * \brief Vérifie si la ListeAdjacence \a l est vide
 * \param l (ListeAdjacence)
 * \relatesalso ListeAdjacence
 * \return \c VRAI si la liste est vide, \c FAUX sinon
 */
Bool lest_vide (const ListeAdjacence * l);

/**
 * \fn Bool lexar (const ListeAdjacence * l, const Sommet * s)
 * \brief Vérifie l'existence d'une arête
 * \param l (ListeAdjacence)
 * \param s (::Sommet)
 * \relatesalso ListeAdjacence
 * \return \c VRAI si l'arête existe, \c FAUX sinon
 */
Bool lexar (const ListeAdjacence * l, const Sommet * s);

/**
 * \fn Ent lpoids (const ListeAdjacence * l, const Sommet * s)
 * \brief Renvoie le poids d'une arête
 * \param l (ListeAdjacence)
 * \param s (::Sommet)
 * \pre poids(l,s) = lexar(l,s)
 * \relatesalso ListeAdjacence
 * \return le poids de l'arête
 */
Ent lpoids (const ListeAdjacence * l, const Sommet * s);

/**
 * \fn Nat ltaille (const ListeAdjacence * l)
 * \brief Retourne le nombre d'arêtes dans la ListeAdjacence \a l
 * \param l (ListeAdjacence)
 * \relatesalso ListeAdjacence
 * \return Nombre d'arêtes de \a l
 */
Nat ltaille (const ListeAdjacence * l);

/**
 * \fn ListeAdjacence lliberer(ListeAdjacence * l)
 * \brief Libérer une liste d'arêtes.
 * \param l (ListeAdjacence)
 * \relatesalso ListeAdjacence
 * \return \c NULL
 */
ListeAdjacence * lliberer(ListeAdjacence * l);

/**
 * \fn ListeAdjacence lcopie(const ListeAdjacence * l)
 * \brief Copier une liste d'arêtes.
 * \param l (ListeAdjacence)
 * \relatesalso ListeAdjacence
 * \return copie de la liste d'arêtes.
 */
ListeAdjacence * lcopie(const ListeAdjacence * l);

/**
 * \fn ListeAdjacence lmod(ListeAdjacence * l, const Sommet * s, Ent x)
 * \brief Modifier le poids d'une arête.
 * \param l (ListeAdjacence)
 * \param s (::Sommet)
 * \param x Nouveau poids.
 * \relatesalso ListeAdjacence
 * \return ListeAdjacence avec l'arête modifiée.
 */
ListeAdjacence * lmod(ListeAdjacence * l, const Sommet * s, Ent x);

/**
 * \fn Bool lega(const ListeAdjacence * l, const ListeAdjacence * m)
 * \brief Teste l'égalité de deux listes d'arêtes
 * \param l (ListeAdjacence)
 * \param m (ListeAdjacence)
 * \relatesalso ListeAdjacence
 * \return \c VRAI si les listes sont égales, \c FAUX sinon.
 */
Bool lega(const ListeAdjacence * l, const ListeAdjacence * m);

/**
 * \fn ListeAdjacence lsuiv(const ListeAdjacence * l)
 * \brief Arête suivante
 * \param l (ListeAdjacence)
 * \relatesalso ListeAdjacence
 * \pre !lest_vide(l)
 */
ListeAdjacence * lsuiv(const ListeAdjacence * l);

/**
 * \fn Sommet lsommet_tete(const ListeAdjacence * l)
 * \brief Extrémité de l'arête en tête de liste.
 * \param l (ListeAdjacence)
 * \pre !lest_vide(l)
 * \relatesalso ListeAdjacence
 * \return ::Sommet
 */
Sommet * lsommet_tete(const ListeAdjacence * l);

/**
 * \fn Ent lpoids_tete(const ListeAdjacence * l)
 * \brief Poids de l'arête en tête de liste.
 * \param l (ListeAdjacence)
 * \pre !lest_vide(l)
 * \relatesalso ListeAdjacence
 * \return Poids de l'arête.
 */
Ent lpoids_tete(const ListeAdjacence * l);

#endif /* __ADJACENCE_H */
