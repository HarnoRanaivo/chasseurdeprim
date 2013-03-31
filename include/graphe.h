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
 * \struct Graphe
 * \brief Graphe.
 */
/**
 * \typedef Graphe
 * \brief Graphe.
 */
typedef struct Graphe 
{
    Sommet sommet;                  /**<- Sommet. */
    ListeArete listeadjacence;      /**<- Liste d'adjacence du sommet. */
    struct Graphe * suivant;     /**<- Sommet suivant. */
} *Graphe;

/**
 * \brief Nouveau graphe.
 * \relatesalso Graphe
 * \return NULL
 */
Graphe gNouv(void);

/**
 * \brief Ajout d'un sommet dans un graphe.
 * \relatesalso Graphe
 * \param g Graphe où ajouter le sommet.
 * \param s Sommet à ajouter.
 * \return Graphe
 */
Graphe gAjouterSommet(Graphe g, const Sommet s);

/**
 * \brief Ajout d'une arête dans un graphe.
 * \relatesalso Graphe
 * \param g Graphe où ajouter l'arête.
 * \param a Éxtrémité de l'arête.
 * \param b Éxtrémité de l'arête.
 * \param p Poids de l'arête.
 * \return Graphe
 */
Graphe gAjouterArete(Graphe g, const Sommet a, const Sommet b, Ent p);

/**
 * \brief Suppression d'un sommet dans un graphe.
 * \relatesalso Graphe
 * \param g Graphe où supprimer le sommet.
 * \param s Sommet à supprimer.
 * \return Graphe
 */
Graphe gSupprimerSommet(Graphe g, const Sommet s);

/**
 * \brief Suppression d'une arête dans un graphe.
 * \relatesalso Graphe
 * \param g Graphe où supprimer l'arête.
 * \param a Éxtrémité de l'arête.
 * \param b Éxtrémité de l'arête.
 * \return Graphe
 */
Graphe gSupprimerArete(Graphe g, const Sommet a, const Sommet b);

/**
 * \brief Modification d'une arête dans un graphe.
 * \relatesalso Graphe
 * \param g Graphe où modifier l'arête.
 * \param a Éxtrémité de l'arête.
 * \param b Éxtrémité de l'arête.
 * \param p Nouveau poids de l'arête.
 * \return Graphe
 */
Graphe gModifierArete(Graphe g, const Sommet a, const Sommet b, Ent p);

/**
 * \brief Test de vacuité d'un graphe.
 * \relatesalso Graphe
 * \param g Graphe.
 * \return (booléen) VRAI si le graphe est vide, FAUX sinon.
 */
Bool gEstVide(const Graphe g);

/**
 * \brief Sommet suivant dans le graphe.
 * \relatesalso Graphe
 * \param g Graphe.
 * \return (pointeur vers) Sommet suivant dans le graphe.
 */
Graphe gSuivant(const Graphe g);

/**
 * \brief Premier sommet dans la liste de sommets.
 * \relatesalso Graphe
 * \param g Graphe.
 * \pre !gEstVide(g)
 * \return Sommet.
 */
Sommet gSommetTete(const Graphe g);

/**
 * \brief Liste d'adjacence du sommet en tête de liste.
 * \relatesalso Graphe
 * \relatesalso ListeArete
 * \param g Graphe.
 * \pre !gEstVide(g)
 * \return Liste d'ajacence de la tête.
 */
ListeArete gAdjacenceTete(const Graphe g);

/**
 * \brief Test d'existence d'un sommet dans un graphe.
 * \relatesalso Graphe
 * \param g Graphe.
 * \param s Sommet.
 * \return (booléen) VRAI si le sommet est dans le graphe, FAUX sinon.
 */
Bool gExisteSommet(const Graphe g, const Sommet s);

/**
 * \brief Test d'existence de voisins d'un sommet dans un graphe.
 * \relatesalso Graphe
 * \param g Graphe.
 * \param s Sommet.
 * \return (booléen) VRAI si le sommet existe et a des voisins dans le graphe, FAUX sinon.
 */
Bool gAArete(const Graphe g, const Sommet s);

/**
 * \brief Test d'existence d'une arete dans un graphe.
 * \relatesalso Graphe
 * \param g Graphe.
 * \param a Sommet.
 * \param b Sommet.
 * \return (booléen) VRAI si l'arête est dans le graphe, FAUX sinon.
 */
Bool gExisteArete(const Graphe g, const Sommet a, const Sommet b);

/**
 * \brief Liste d'adjacence d'un sommet.
 * \relatesalso Graphe
 * \relatesalso ListeArete
 * \param g Graphe.
 * \param s Sommet.
 * \return Liste d'adjacence du sommet, s'il existe.
 */
ListeArete gAdjacenceSommet(const Graphe g, const Sommet s);

/**
 * \brief Nombre de sommets dans un graphe.
 * \relatesalso Graphe
 * \param g Graphe.
 * \return Nombre de sommets dans un graphe.
 */
Nat gNombreSommets(const Graphe g);

/**
 * \brief Nombre d'arêtes dans un graphe.
 * \relatesalso Graphe
 * \param g Graphe.
 * \return Nombre d'arêtes dans un graphe.
 */
Nat gNombreAretes(const Graphe g);

/**
 * \brief Poids d'une arête.
 * \relatesalso Graphe
 * \param g Grape.
 * \param a Extrémité de l'arête.
 * \param b Extrémité de l'arête.
 * \pre gExisteArete(g, a, b)
 * \return Poids de l'arête (a, b).
 */
Ent gPoidsArete(const Graphe g, const Sommet a, const Sommet b);

/**
 * \brief Nombre de voisins d'un sommet.
 * \relatesalso Graphe
 * \param g Graphe.
 * \param s Sommet.
 * \return Nombre de voisins d'un sommet. Retournera 0 si le sommet n'existe pas.
 */
Nat gNombreVoisins(const Graphe g, const Sommet s);

/**
 * \brief Obtenir Un sommet d'un graphe.
 * \relatesalso Graphe
 * \param g Graphe.
 * \param s Sommet.
 * \return (pointeur vers) Sommet s dans le graphe.
 */
Graphe gPSommet(const Graphe g, const Sommet s);

/**
 * \brief Égalité de deux graphes.
 * \param g Graphe.
 * \param h Graphe.
 * \return VRAI si les graphes sont identiques, à l'ordre des sommets près, FAUX sinon.
 */
Bool gEgalite(const Graphe g, const Graphe h);

/**
 * \brief Copie d'un graphe.
 * \relatesalso Graphe
 * \param g Graphe.
 * \return Copie du graphe.
 */
Graphe gCopier(const Graphe g);

/**
 * \brief Libération d'un graphe.
 * \relatesalso Graphe
 * \param g Graphe.
 * \return NULL
 */
Graphe gLiberer(Graphe g);

#endif /* __GRAPHE_H */
