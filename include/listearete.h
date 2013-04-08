/**
 * \file listearete.h
 * \brief Liste d'arêtes (header)
 * \author Harenome RAZANAJATO
 */
#ifndef __LISTEARETE_H
#define __LISTEARETE_H

#include <stdlib.h>
#include <stdio.h>

#include "base.h"
#include "sommet.h"
#include "arete.h"

/**
 * \struct ListeArete
 * \brief Liste d'arêtes.
 *
 * Liste d'Arete.
 *
 * Les générateurs sont :
 * - larNouv()
 * - larAjouterAreteTete()
 *
 * Les destructeurs sont :
 * - larSupprimerTete()
 * - larSupprimerArete()
 * - larLiberer()
 *
 * Les sélecteurs sont :
 * larEstVide()
 * larExisteArete()
 * larNombreAretes()
 * larAreteTete()
 * larPArete()
 * larSuivante()
 *
 * Un type est défini à partir de ListeArete : ::FileAreteTriee (voir filearetetriee.h), et dispose de générateurs spécifiques :
 * - ftNouv()
 * - ftAjouterArete()
 *
 * Les sélecteurs et destructeurs peuvent être utilisés indifféremnt sur les ListeArete et ::FileAreteTriee.
 */
struct ListeArete
{
    Arete * arete;                  /**<- Arête. */
    struct ListeArete * suivante;    /**<- Arête suivante dans la file. */
};

/**
 * \brief Liste d'arêtes.
 */
typedef struct ListeArete ListeArete;

/**
 * \brief Nouvelle liste d'arêtes.
 * \relatesalso ListeArete
 * \return NULL
 */
ListeArete * larNouv(void);

/**
 * \brief Ajouter une arête dans la file liste.
 * \relatesalso ListeArete
 * \param l ListeArete.
 * \param a Extrémité \a a de l'arête.
 * \param b Extrémité \a t de l'arête.
 * \param poids Poids de l'arête.
 * \return (pointeur vers) ListeArete.
 *
 * Ajoute une Arete dans la liste \a l. S'il existe déjà une Arete entre \a et \b dans la liste, ou bien en cas d'erreur lors de l'ajout, \a l reste intacte.
 */
ListeArete * larAjouterAreteTete(ListeArete * l, const Sommet * a, const Sommet * b, Ent poids);

/**
 * \brief Supprimer l'arête en tête de liste.
 * \relatesalso ListeArete
 * \param l ListeArete.
 * \return (pointeur vers) ListeArete.
 *
 * Suppression de l'Arete en tête de liste, si celle-ci y existe. Sinon, \a l reste intacte.
 */
ListeArete * larSupprimerTete(ListeArete * l);

/**
 * \brief Supprimer une arête dans la liste.
 * \relatesalso ListeArete
 * \param l ListeArete.
 * \param a Extrémité de l'arête à supprimer.
 * \param b Autre extrémité de l'arête à supprimer.
 * \return (pointeur vers) ListeArete.
 *
 * Suppression de la liste de l'Arete entre \a a et \a b, si celle-ci y existe. Sinon, \a l reste intacte.
 */
ListeArete * larSupprimerArete(ListeArete * l, const Sommet * a, const Sommet * b);

/**
 * \brief Test de vacuité d'une liste d'arêtes.
 * \relatesalso ListeArete
 * \param l ListeArete.
 * \return VRAI si la file est vide, FAUX sinon.
 *
 * La ListeArete est vide si \a l pointe vers \a NULL.
 */
Bool larEstVide(const ListeArete * l);

/**
 * \brief Test d'existence d'une arête.
 * \relatesalso ListeArete
 * \param l ListeArete.
 * \param a Extrémité de l'arête.
 * \param b Autre extrémité de l'arête.
 * \return VRAI si l'arête existe, FAUX sinon.
 */
Bool larExisteArete(const ListeArete * l, const Sommet * a, const Sommet * b);

/**
 * \brief Nombre d'arêtes dans la liste.
 * \relatesalso ListeArete
 * \param l ListeArete.
 * \return Nombre d'arêtes.
 */
Nat larNombreAretes(const ListeArete * l);

/**
 * \brief Arête en tête de liste.
 * \relatesalso ListeArete
 * \param l ListeArete.
 * \pre !larEstVide(f)
 * \return Arête.
 *
 * Retourne un pointeur vers l'Arete se trouvant en tête de la ListeArete \a l.
 */
Arete * larAreteTete(const ListeArete * l);

/**
 * \brief Pointeur vers la sous-liste commençant par l'arête a,b
 * \relatesalso ListeArete
 * \param l ListeArete.
 * \param a Extrémité de l'arête.
 * \param b Autre extrémité de l'arête.
 * \return (pointeur vers) Sous-liste commençant par (a, b)
 *
 * Retourne un pointeur vers la sous-liste de \a l qui commence par l'Arete entre \a a et \a b. Retourne \a NULL si l'Arete n'est pas présente dans \a l.
 */
ListeArete * larPArete(const ListeArete *l, const Sommet * a, const Sommet *b);

/**
 * \brief Arête suivante dans la liste.
 * \relatesalso ListeArete
 * \param l ListeArete.
 * \return (pointeur vers) Arête suivante.
 *
 * Retourne un pointeur vers la sous-liste de \a l privée de la tête de \a l. Peut retourner une liste vide si \a l ne contient qu'un seul élément.
 */
ListeArete * larSuivante(const ListeArete * l);

/**
 * \brief Libérer une liste d'arêtes.
 * \relatesalso ListeArete
 * \param l ListeArete.
 * \return NULL
 *
 * Libère la mémoire occuppée par une ListeArete : libère aussi les Arete contenues dans la ListeArete.
 */
ListeArete * larLiberer(ListeArete * l);

#endif /* __LISTEARETE_H */
