/**
 * \file coloration.h
 * \brief Coloration d'un graphe (header)
 * \author Harenome RAZANAJATO
 */

#ifndef __COLORATION_H
#define __COLORATION_H

#include <stdio.h>
#include <stdlib.h>

#include "base.h"
#include "sommet.h"
#include "graphe.h"

/**
 * \enum Couleur
 * \brief Coloration des sommets d'un graphe.
 */
typedef enum
{
    NOIR,   /** Sommet visité */
    GRIS,   /** Sommet en cours de visite */
    BLANC   /** Sommet non visité */
} Couleur;

/**
 * \struct CouleurGraphe
 * \brief Liste des couleurs des sommets d'un graphe.
 */
typedef struct couleurgraphe
{
    Sommet sommet;                      /** Sommet */
    Couleur couleur;                    /** Couleur du sommet */
    struct couleurgraphe * suivant;     /** Sommet suivant */
} StrCouleursGraphe, *CouleursGraphe;

/**
 * \brief Nouvelle liste.
 * \relatesalso CouleursGraphe
 * \return NULL
 */
CouleursGraphe cgNouv(void);

/**
 * \brief Ajouter un sommet à la liste.
 * \relatesalso CouleursGraphe
 * \relatesalso Sommet
 * \relatesalso Couleur
 * \param cg Liste;
 * \param s Sommet.
 * \param c Couleur du sommet.
 * \pre !cgExisteSommmet(cg, s)
 * \return (pointeur vers) CouleursGraphe.
 */
CouleursGraphe cgAjouterSommet(CouleursGraphe cg, const Sommet s, Couleur c);

/**
 * \brief Supprimer la tête de liste.
 * \relatesalso CouleursGraphe
 * \param cg Liste.
 * \return (pointeur vers) CouleursGraphe.
 */
CouleursGraphe cgSupprimerTete(CouleursGraphe cg);

/**
 * \brief Supprimer un sommet de la liste.
 * \relatesalso CouleursGraphe
 * \relatesalso Sommet
 * \param cg CouleursGraphe.
 * \param s Sommet.
 * \return (pointeur vers) CouleursGraphe.
 */
CouleursGraphe cgSupprimerSommet(CouleursGraphe cg, const Sommet s);

/**
 * \brief Modifier un sommet de la liste.
 * \relatesalso CouleursGraphe
 * \relatesalso Sommet
 * \relatesalso Couleur
 * \param cg CouleursGraphe.
 * \param s Sommet.
 * \param c Couleur.
 * \return (pointeur vers) CouleursGraphe.
 */
CouleursGraphe cgModifierSommet(CouleursGraphe cg, const Sommet s, Couleur c);

/**
 * \brief Initialiser les couleurs des sommets d'un graphe à BLANC.
 * \relatesalso CouleursGraphe
 * \relatesalso Graphe
 * \param g Graphe.
 * \return (pointeur vers) CouleursGraphe.
 */
CouleursGraphe cgInit(const Graphe g);

/**
 * \brief Test de vacuité d'une liste de couleurs.
 * \relatesalso CouleursGraphe
 * \param cg CouleursGraphe.
 * \return VRAI si la liste est vide, FAUX sinon.
 */
Bool cgEstVide(const CouleursGraphe cg);

/**
 * \brief Test d'existence d'un sommet.
 * \relatesalso CouleursGraphe
 * \relatesalso Sommet
 * \param cg CouleursGraphe.
 * \param s Sommet.
 * \return VRAI si le sommet existe, FAUX sinon.
 */
Bool cgExisteSommmet(const CouleursGraphe cg, const Sommet s);

/**
 * \brief Sommet suivant dans la liste.
 * \relatesalso CouleursGraphe
 * \param cg CouleursGraphe.
 * \return (pointeur vers) le sommet suivant dans la liste.
 */
CouleursGraphe cgSuivant(const CouleursGraphe cg);

/**
 * \brief Sommet en tête de liste.
 * \relatesalso CouleursGraphe
 * \param cg CouleursGraphe.
 * \pre !cgEstVidet(cg)
 * \return Sommet.
 */
Sommet cgSommetTete(const CouleursGraphe cg);

/**
 * \brief Couleur du sommet en tête de liste.
 * \relatesalso CouleursGraphe
 * \param cg CouleursGraphe.
 * \pre !cgEstVidet(cg)
 * \return Couleur.
 */
Couleur cgCouleurTete(const CouleursGraphe cg);

/**
 * \brief Couleur du sommet.
 * \relatesalso CouleursGraphe
 * \relatesalso Sommet
 * \param cg CouleursGraphe.
 * \param s Sommet.
 * \pre !cgExisteSommmet(cg)
 * \return Couleur.
 */
Couleur cgCouleurSommet(const CouleursGraphe cg, const Sommet s);

/**
 * \brief Premier sommet noir dans la liste.
 * \relatesalso CouleursGraphe
 * \param cg CouleursGraphe.
 * \return Premier sommet noir, NULL s'il n'y en a pas.
 */
Sommet cgPremierSommetNoir(const CouleursGraphe cg);

/**
 * \brief Premier sommet gris dans la liste.
 * \relatesalso CouleursGraphe
 * \param cg CouleursGraphe.
 * \return Premier sommet gris, NULL s'il n'y en a pas.
 */
Sommet cgPremierSommetGris(const CouleursGraphe cg);

/**
 * \brief Premier sommet blanc dans la liste.
 * \relatesalso CouleursGraphe
 * \param cg CouleursGraphe.
 * \return Premier sommet blanc, NULL s'il n'y en a pas.
 */
Sommet cgPremierSommetBlanc(const CouleursGraphe cg);

/**
 * \brief Nombre de sommets dans la liste.
 * \relatesalso CouleursGraphe
 * \param cg CouleursGraphe.
 * \return Nombre de sommets.
 */
Nat cgNombreSommets(const CouleursGraphe cg);

/**
 * \brief Nombre de sommets noirs dans la liste.
 * \relatesalso CouleursGraphe
 * \param cg CouleursGraphe.
 * \return Nombre de sommets noirs.
 */
Nat cgNombreSommetsNoirs(const CouleursGraphe cg);

/**
 * \brief Nombre de sommets gris dans la liste.
 * \relatesalso CouleursGraphe
 * \param cg CouleursGraphe.
 * \return Nombre de sommets gris.
 */
Nat cgNombreSommetsGris(const CouleursGraphe cg);

/**
 * \brief Nombre de sommets blancs dans la liste.
 * \relatesalso CouleursGraphe
 * \param cg CouleursGraphe.
 * \return Nombre de sommets blancs.
 */
Nat cgNombreSommetsBlancs(const CouleursGraphe cg);

/**
 * \brief Pointeur vers le sommet.
 * \relatesalso CouleursGraphe
 * \relatesalso Sommet
 * \param cg CouleursGraphe
 * \param s Sommet
 * \return (pointeur vers) le sommet dans la liste.
 */
CouleursGraphe cgPSommet(const CouleursGraphe cg, const Sommet s);

/**
 * \brief Libérer une liste de couleurs.
 * \relatesalso CouleursGraphe
 * \param cg CouleursGraphe.
 * \return NULL
 */
CouleursGraphe cgLiberer(CouleursGraphe cg);

#endif /* __COLORATION_H */
