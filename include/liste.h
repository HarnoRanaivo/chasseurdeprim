/**
 * \file liste.h
 * \brief Gestion de la sorte Liste (header)
 * \author Meyer Jérémy
 */

#ifndef __LISTE_H
#define __LISTE_H

#include "sommet.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

/**
 * \struct ListeArete
 * \brief Structure des listes d'arêtes par rapport à un sommet
 */
typedef struct sliste{
	struct sliste * s; /**<- Pointeur sur la structure de liste*/
	Ent poids; /**<- Poids de l'arête*/
	Sommet v; /**<- Sommet de l'arête*/
}StrListeArete,*ListeArete;

/**
 * \fn ListeArete listnouv ()
 * \brief Crée une nouvelle liste vide
 * \relatesalso ListeArete
 * \return ListeArete vide
 */
ListeArete listnouv ();
 
/**
 * \fn ListeArete lajar (ListeArete l, Sommet s, Ent x)
 * \brief Ajoute une arête à la liste avec son poids
 * \param l (ListeArete)
 * \param s (Sommet)
 * \param x (Ent = poids)
 * \relatesalso ListeArete
 * \return ListeArete + Sommet s
 */
ListeArete lajar (ListeArete l, const Sommet s, Ent x);

/**
 * \fn ListeArete lsupar (ListeArete l, Sommet s)
 * \brief Supprime une arête de la liste
 * \param l (ListeArete)
 * \param s (Sommet de l'arête à supprimer)
 * \relatesalso ListeArete
 * \return l sans l'arête s
 */
ListeArete lsupar (ListeArete l, const Sommet s);

/**
 * \fn Bool lest_vide (ListeArete l)
 * \brief Vérifie si la liste est vide
 * \param l (ListeArete)
 * \relatesalso ListeArete
 * \return VRAI si la liste est vide, FAUX sinon
 */
Bool lest_vide (ListeArete l);

/**
 * \fn Bool lexar (ListeArete l, Sommet s)
 * \brief Vérifie l'existence d'une arête
 * \param l (ListeArete)
 * \param s (Sommet)
 * \relatesalso ListeArete
 * \return VRAI si l'arête existe, FAUX sinon
 */
Bool lexar (ListeArete l, const Sommet s);

/**
 * \fn Ent lpoids (ListeArete l, Sommet s)
 * \brief Renvoie le poids d'une arête
 * \param l (ListeArete)
 * \param s (Sommet)
 * \pre poids(l,s) = lexar(l,s)
 * \relatesalso ListeArete
 * \return le poids de l'arête
 */
Ent lpoids (ListeArete l, const Sommet s);

/**
 * \fn Nat ltaille (ListeArete l)
 * \brief Retourne le nombre d'arcs dans la liste
 * \param l (ListeArete)
 * \relatesalso ListeArete
 * \return Nombre d'arcs de l
 */
Nat ltaille (ListeArete l);

/**
 * \fn ListeArete lliberer(ListeArete l)
 * \brief Libérer une liste d'arêtes.
 * \param l (ListeArete)
 * \relatesalso ListeArete
 * \return NULL
 */
ListeArete lliberer(ListeArete l);

/**
 * \fn ListeArete lcopie(const ListeArete l)
 * \brief Copier une liste d'arêtes.
 * \param l (ListeArete)
 * \relatesalso ListeArete
 * \return copie de la liste d'arêtes.
 */
ListeArete lcopie(const ListeArete l);

/**
 * \fn ListeArete lmod(ListeArete l, const Sommet s, Ent x)
 * \brief Modifier le poids d'une arête.
 * \param l (ListeArete)
 * \param s (Sommet)
 * \param x Nouveau poids.
 * \return ListeArete avec l'arête modifiée.
 */
ListeArete lmod(ListeArete l, const Sommet s, Ent x);

/**
 * \fn Bool lega(ListeArete l, ListeArete m)
 * \brief Teste l'égalité de deux listes d'arêtes
 * \param l (ListeArete)
 * \param m (ListeArete)
 * \return VRAI si les listes sont égales, FAUX sinon.
 */
Bool lega(ListeArete l, ListeArete m);

/**
 * \fn ListeArete lsuiv(const ListeArete l)
 * \brief Arête suivante
 * \param l (ListeArete)
 * \pre !lest_vide(l)
 */
ListeArete lsuiv(const ListeArete l);

/**
 * \fn Sommet lsommet_tete(const ListeArete l)
 * \brief Extrémité de l'arête en tête de liste
 * \param l (ListeArete)
 * \pre !lest_vide(l)
 * \return Sommet
 */
Sommet lsommet_tete(const ListeArete l);

/**
 * \fn Ent lpoids_tete(const ListeArete l)
 * \brief Poids de l'arête en tête de liste
 * \param l (ListeArete)
 * \pre !lest_vide(l)
 * \return Poids de l'arête
 */
Ent lpoids_tete(const ListeArete l);

#endif /* __LISTE_H */
