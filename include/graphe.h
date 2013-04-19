/* This program is free software. It comes WITHOUT ANY WARRANTY, to
* the extent permitted by applicable law. You can redistribute it
* and/or modify it under the terms of the Do What The Fuck You Want
* To Public License, Version 2, as published by Sam Hocevar. See
* http://wtfpl.net for more details. */
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
#include "adjacence.h"
#include "listearete.h"

/**
 * \struct Graphe
 * \brief Liste de sommets associés à leurs listes d'adjacence.
 *
 * Un Graphe associe un ::Sommet à une ListeAdjacence :
 * - #sommet : ::Sommet.
 * - #listeadjacence : ListeAdjacence correspondant à ce ::Sommet.
 * - #suivant : ::Sommet et ListeAdjacence suivants dans le Graphe.
 *
 * Les générateurs sont :
 * - gNouv()
 * - gAjouterSommet()
 * - gAjouterArete()
 * - gModifierArete()
 * - gCopier()
 *
 * Les destructeurs sont :
 * - gSupprimerSommet()
 * - gSupprimerArete()
 * - gLiberer()
 *
 * Les sélecteurs sont :
 * - gEstVide()
 * - gSuivant()
 * - gSommetTete()
 * - gAdjacenceTete()
 * - gExisteSommet()
 * - gAArete()
 * - gExisteArete()
 * - gAdjacenceSommet()
 * - gNombreSommets()
 * - gNombreAretes()
 * - gPoidsArete()
 * - gNombreVoisins()
 * - gPSommet()
 * - gEgalite()
 * - gAretes()
 *
 * Un type est défini à partir de cette structure : ::GrapheConnexe (voir Grapheconnexe.h), et dispose de générateurs spécifiques :
 * - gcNouv()
 * - gcAjouterSommet()
 * - gcAjouterArete()
 * - gcModifierArete()
 * Ainsi que de destructeurs spécifiques :
 * - gcSupprimerSommet()
 * - gcSupprimerArete()
 *
 * Tous les sélecteurs, ainsi que gCopier() et gLiberer() peuvent être utilisés indifférement avec un Graphe ou un ::GrapheConnexe.
 */
struct Graphe 
{
    Sommet * sommet;                     /**<- Sommet. */
    ListeAdjacence * listeadjacence;     /**<- Liste d'adjacence du sommet. */
    struct Graphe * suivant;             /**<- Sommet suivant. */
};

/**
 * \brief Graphe.
 */
typedef struct Graphe Graphe;

/**
 * \brief Nouveau Graphe.
 * \relatesalso Graphe
 * \return NULL
 */
Graphe * gNouv(void);

/**
 * \brief Ajout d'un sommet dans un Graphe.
 * \relatesalso Graphe
 * \param g Graphe où ajouter le sommet.
 * \param s ::Sommet à ajouter.
 * \return Graphe
 *
 * Ajout du ::Sommet \a s dans le Graphe \a g. Si le ::Sommet existe déjà, ou bien en cas d'erreur lors de l'ajout, le Graphe reste intact.
 */
Graphe * gAjouterSommet(Graphe * g, const Sommet * s);

/**
 * \brief Ajout d'une arête dans un Graphe.
 * \relatesalso Graphe
 * \param g Graphe où ajouter l'arête.
 * \param a Éxtrémité de l'arête.
 * \param b Éxtrémité de l'arête.
 * \param p Poids de l'arête.
 * \return Graphe
 *
 * Ajout d'une arête dans le Graphe \a g. Si l'un des ::Sommet n'existe pas encore, il est ajouté avant d'ajouter l'arête. Si l'arête entre \a a et \a b existe déjà, ou bien en cas d'erreur lors de l'ajout, le Graphe reste intact.
 */
Graphe * gAjouterArete(Graphe * g, const Sommet * a, const Sommet * b, Ent p);

/**
 * \brief Suppression d'un sommet dans un Graphe.
 * \relatesalso Graphe
 * \param g Graphe où supprimer le sommet.
 * \param s ::Sommet à supprimer.
 * \return Graphe
 *
 * Suppression du ::Sommet \a s dans le Graphe \a g. La suppression du ::Sommet \a s implique la suppression de toutes les arêtes incidentes à \a s.
 */
Graphe * gSupprimerSommet(Graphe * g, const Sommet * s);

/**
 * \brief Suppression d'une arête dans un Graphe.
 * \relatesalso Graphe
 * \param g Graphe où supprimer l'arête.
 * \param a Extrémité de l'arête.
 * \param b Autre extrémité de l'arête.
 * \return Graphe
 *
 * Suppression de l'arête entre \a a \a b dans le Graphe \a g. Si l'arête ou au moins l'un des ::Sommet n'existe pas, le Graphe reste intact.
 */
Graphe * gSupprimerArete(Graphe * g, const Sommet * a, const Sommet * b);

/**
 * \brief Modification d'une arête dans un Graphe.
 * \relatesalso Graphe
 * \param g Graphe où modifier l'arête.
 * \param a Extrémité de l'arête.
 * \param b Autre extrémité de l'arête.
 * \param p Nouveau poids de l'arête.
 * \return Graphe
 *
 * Modification du poids de l'arête entre \a a et \a b. Si l'arête ou au moins l'un des ::Sommet n'exsite pas, le Graphe reste intact.
 */
Graphe * gModifierArete(Graphe * g, const Sommet * a, const Sommet * b, Ent p);

/**
 * \brief Test de vacuité d'un Graphe.
 * \relatesalso Graphe
 * \param g Graphe.
 * \return (booléen) #VRAI si le Graphe est vide, #FAUX sinon.
 *
 * Le Graphe est vide si \a g pointe vers \a NULL.
 */
Bool gEstVide(const Graphe * g);

/**
 * \brief Sommet suivant dans le Graphe.
 * \relatesalso Graphe
 * \param g Graphe.
 * \return (pointeur vers) Élément suivant dans le Graphe.
 *
 * Pointeur vers l'élément suivant dans le Graphe. S'il n'y a plus de Sommet, retourne \a NULL.
 */
Graphe * gSuivant(const Graphe * g);

/**
 * \brief Premier ::Sommet dans la liste de sommets.
 * \relatesalso Graphe
 * \param g Graphe.
 * \pre !gEstVide(g)
 * \return ::Sommet.
 */
Sommet * gSommetTete(const Graphe * g);

/**
 * \brief Liste d'adjacence du sommet en tête de liste.
 * \relatesalso Graphe
 * \relatesalso ListeAdjacence
 * \param g Graphe.
 * \pre !gEstVide(g)
 * \return Liste d'ajacence de la tête.
 *
 * Retourne la ListeAdjacence associée au ::Sommet en tête de liste. Attention : si ce ::Sommet n'a pas de voisins, la ListeAdjacence sera vide.
 */
ListeAdjacence * gAdjacenceTete(const Graphe * g);

/**
 * \brief Test d'existence d'un ::Sommet dans un Graphe.
 * \relatesalso Graphe
 * \param g Graphe.
 * \param s ::Sommet.
 * \return (booléen) #VRAI si le ::Sommet est dans le Graphe, #FAUX sinon.
 */
Bool gExisteSommet(const Graphe * g, const Sommet * s);

/**
 * \brief Test d'existence de voisins d'un ::Sommet dans un Graphe.
 * \relatesalso Graphe
 * \param g Graphe.
 * \param s ::Sommet.
 * \return (booléen) #VRAI si le sommet existe et a des voisins dans le Graphe, #FAUX sinon.
 */
Bool gAArete(const Graphe * g, const Sommet * s);

/**
 * \brief Test d'existence d'une arete dans un Graphe.
 * \relatesalso Graphe
 * \param g Graphe.
 * \param a Extrémité de l'arête.
 * \param b Autre extrémité de l'arête.
 * \return (booléen) #VRAI si l'arête est dans le Graphe, #FAUX sinon.
 */
Bool gExisteArete(const Graphe * g, const Sommet * a, const Sommet  *b);

/**
 * \brief Liste d'adjacence d'un sommet.
 * \relatesalso Graphe
 * \param g Graphe.
 * \param s ::Sommet.
 * \return Liste d'adjacence du sommet, s'il existe.
 *
 * Retourne la ListeAdjacence associée au ::Sommet \a s. Attention : si ce ::Sommet n'a pas de voisins, la ListeAdjacence sera vide.
 */
ListeAdjacence * gAdjacenceSommet(const Graphe * g, const Sommet * s);

/**
 * \brief Nombre de sommets dans un Graphe.
 * \relatesalso Graphe
 * \param g Graphe.
 * \return Nombre de sommets dans un Graphe.
 */
Nat gNombreSommets(const Graphe * g);

/**
 * \brief Nombre d'arêtes dans un Graphe.
 * \relatesalso Graphe
 * \param g Graphe.
 * \return Nombre d'arêtes dans un Graphe.
 */
Nat gNombreAretes(const Graphe * g);

/**
 * \brief Poids d'une arête.
 * \relatesalso Graphe
 * \param g Grape.
 * \param a Extrémité de l'arête.
 * \param b Extrémité de l'arête.
 * \pre gExisteArete(g, a, b)
 * \return Poids de l'arête (a, b).
 */
Ent gPoidsArete(const Graphe * g, const Sommet * a, const Sommet * b);

/**
 * \brief Nombre de voisins d'un sommet.
 * \relatesalso Graphe
 * \param g Graphe.
 * \param s Sommet.
 * \pre gExisteSommet(g, s)
 * \return Nombre de voisins d'un sommet.
 */
Nat gNombreVoisins(const Graphe * g, const Sommet * s);

/**
 * \brief Obtenir Un sommet d'un Graphe.
 * \relatesalso Graphe
 * \param g Graphe.
 * \param s Sommet.
 * \return (pointeur vers) Sommet s dans le Graphe.
 *
 * Pointeur vers l'élément de la liste correspondant au ::Sommet \a s. Retourne \a NULL si \a s n'existe pas.
 */
Graphe * gPSommet(const Graphe * g, const Sommet * s);

/**
 * \brief Égalité de deux Graphes.
 * \param g Graphe.
 * \param h Graphe.
 * \return #VRAI si les Graphes sont identiques, à l'ordre des sommets près, #FAUX sinon.
 *
 * Deux Graphes sont considérés égaux s'ils ont le même nombre de sommets, le même nombre d'arêtes, les mêmes ::Sommet et les mêmes arêtes. L'ordre dans lequel sont ordonnés les ::Sommet ou les arêtes n'a pas d'importance.
 */
Bool gEgalite(const Graphe * g, const Graphe * h);

/**
 * \brief Copie d'un Graphe.
 * \relatesalso Graphe
 * \param g Graphe.
 * \return Copie du Graphe.
 *
 * Retourne un nouveau Graphe égal au Graphe \a g.
 */
Graphe * gCopier(const Graphe * g);

/**
 * \brief Liste des arêtes d'un Graphe.
 * \relatesalso Graphe
 * \param g Graphe.
 * \return Liste des arêtes.
 *
 * Retourne une ListeArete des arêtes d'un Graphe.
 */
ListeArete * gAretes(const Graphe * g);

/**
 * \brief Libération d'un Graphe.
 * \relatesalso Graphe
 * \param g Graphe.
 * \return NULL
 *
 * Libère la mémoire occupée par un Graphe : libère tous les ::Sommet ansi que leurs ListeAdjacence.
 */
Graphe * gLiberer(Graphe * g);

#endif /* __GRAPHE_H */
