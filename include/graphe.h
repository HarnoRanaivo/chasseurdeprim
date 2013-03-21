/**
 * \file graphe.h
 * \brief Graphes (header)
 * \author Harenome RAZANAJATO
 */
#ifndef __GRAPHE_H
#define __GRAPHE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "base.h"
#include "sommet.h"
#include "liste.h"

/**
 * \struct graphe
 * \brief Graphe
 */
typedef struct strgraphe
{
    Sommet sommet;                  /** Sommet. */
    ListeArete listeadjacence;      /** Liste d'adjacence du sommet. */
    struct strgraphe * suivant;     /** Sommet suivant. */
} StrGraphe, *Graphe;

/**
 * \brief Nouveau graphe.
 * \relatesalso graphe
 * \return NULL
 */
Graphe gNouv(void);

/**
 * \brief Ajout d'un sommet dans un graphe.
 * \relatesalso Graphe
 * \param g Graphe où ajouter le sommet.
 * \param s Sommet à ajouter.
 * \pre !gExisteSommet(g, s).
 * \return Graphe
 */
Graphe gAjoutSommet(Graphe g, Sommet s);

/**
 * \brief Ajout d'une arête dans un graphe.
 * \relatesalso Graphe
 * \param g Graphe où ajouter l'arête.
 * \param a Éxtrémité de l'arête.
 * \param b Éxtrémité de l'arête.
 * \param p Poids de l'arête.
 * \pre gExisteSommet(g, a) || gExisteSommet(g, b).
 * \return Graphe
 */
Graphe gAjoutArete(Graphe g, Sommet a, Sommet b, Ent p);

/**
 * \brief Suppression d'un sommet dans un graphe.
 * \relatesalso Graphe
 * \param g Graphe où supprimer le sommet.
 * \param s Sommet à supprimer.
 * \pre !gAArete(g, s).
 * \return Graphe
 */
Graphe gSupprimerSommet(Graphe g, Sommet s);

/**
 * \brief Suppression d'une arête dans un graphe.
 * \relatesalso Graphe
 * \param g Graphe où supprimer l'arête.
 * \param a Éxtrémité de l'arête.
 * \param b Éxtrémité de l'arête.
 * \pre gExisteSommet(g, a) && gExisteSommet(g, b).
 * \return Graphe
 */
Graphe gSupprimerArete(Graphe g, Sommet a, Sommet b);

/**
 * \brief Modification d'une arête dans un graphe.
 * \relatesalso Graphe
 * \param g Graphe où modifier l'arête.
 * \param a Éxtrémité de l'arête.
 * \param b Éxtrémité de l'arête.
 * \param p Nouveau poids de l'arête.
 * \pre gExisteSommet(g, a) && gExisteSommet(g, b).
 * \return Graphe
 */
Graphe gModifierArete(Graphe g, Sommet a, Sommet b, Ent p);

/**
 * \brief Test de vacuité d'un graphe.
 * \relatesalso Graphe
 * \param g Graphe.
 * \return (booléen) VRAI si le graphe est vide, FAUX sinon.
 */
Bool gEstVide(Graphe g);

/**
 * \brief Test d'existence d'un sommet dans un graphe.
 * \relatesalso Graphe
 * \param g Graphe.
 * \param s Sommet.
 * \return (booléen) VRAI si le sommet est dans le graphe, FAUX sinon.
 */
Bool gExisteSommet(Graphe g, Sommet s);

/**
 * \brief Test d'existence d'un sommet dans un graphe.
 * \relatesalso Graphe
 * \param g Graphe.
 * \param s Sommet.
 * \return (booléen) VRAI si le sommet est dans le graphe, FAUX sinon.
 */
Bool gAArete(Graphe g, Sommet s);

/**
 * \brief Test d'existence d'une arete dans un graphe.
 * \relatesalso Graphe
 * \param g Graphe.
 * \param a Sommet.
 * \param b Sommet.
 * \return (booléen) VRAI si l'arête est dans le graphe, FAUX sinon.
 */
Bool gExisteArete(Graphe g, Sommet a, Sommet b);

/**
 * \brief Liste d'adjacence d'un sommet.
 * \relatesalso Graphe
 * \relatesalso ListeArete
 * \param g Graphe.
 * \param s Sommet.
 * \return (booléen) VRAI si le sommet est dans le graphe, FAUX sinon.
 */
ListeArete gAdjacenceSommet(Graphe g, Sommet s);

/**
 * \brief Nombre de sommets dans un graphe.
 * \relatesalso Graphe
 * \param g Graphe.
 * \return Nombre de sommets dans un graphe.
 */
Nat gNombreSommets(Graphe g);

/**
 * \brief Nombre d'arêtes dans un graphe.
 * \relatesalso Graphe
 * \param g Graphe.
 * \return Nombre d'arêtes dans un graphe.
 */
Nat gNombreAretes(Graphe g);

/**
 * \brief Nombre de voisins d'un sommet.
 * \relatesalso Graphe
 * \param g Graphe.
 * \return Nombre de voisins d'un sommet.
 */
Nat gNombreVoisins(Graphe g, Sommet s);

/**
 * \brief Obtenir Un sommet d'un graphe.
 * \relatesalso Graphe
 * \param g Graphe.
 * \return (pointeur vers) Sommet s dans le graphe.
 */
Graphe gPSommet(Graphe g, Sommet s);

#endif /* __GRAPHE_H */
