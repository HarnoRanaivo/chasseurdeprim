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
 *
 * Permet de marquer un ::Sommet selon qu'il a déjà été visité (#NOIR), qu'il est en cours de visite (#GRIS), ou qu'il n'a pas encore été visité (#BLANC).
 */
enum Couleur
{
    NOIR,   /**<- Sommet visité */
    GRIS,   /**<- Sommet en cours de visite */
    BLANC   /**<- Sommet non visité */
};

/**
 * \brief Coloration des sommets d'un graphe.
 */
typedef enum Couleur Couleur;

/**
 * \struct CouleursGraphe
 * \brief Liste des couleurs des sommets d'un graphe.
 *
 * Liste d'associations de #Couleur à un ::Sommet d'un Graphe.
 */
struct CouleursGraphe
{
    Sommet * sommet;                     /**<- ::Sommet */
    Couleur couleur;                     /**<- #Couleur du ::Sommet */
    struct CouleursGraphe * suivant;     /**<- Élément suivant */
};

/**
 * \brief Liste des couleurs des sommets d'un graphe.
 */
typedef struct CouleursGraphe CouleursGraphe;

/**
 * \brief Nouvelle liste.
 * \relatesalso Graphe
 * \return \a NULL
 */
CouleursGraphe * cgNouv(void);

/**
 * \brief Ajouter un ::Sommet à la liste.
 * \relatesalso CouleursGraphe
 * \param cg CouleursGraphe.
 * \param s ::Sommet.
 * \param c #Couleur du ::Sommet.
 * \return (pointeur vers) CouleursGraphe.
 *
 * Ajoute un ::Sommet à la liste. N'ajoute pas le ::Sommet s'il y est déjà présent.
 */
CouleursGraphe * cgAjouterSommet(CouleursGraphe * cg, const Sommet * s, Couleur c);

/**
 * \brief Supprimer la tête de liste.
 * \relatesalso CouleursGraphe
 * \param cg Liste.
 * \return (pointeur vers) CouleursGraphe.
 *
 * Supprime la tête de liste, si celle-ci n'est pas vide. Ne fait rien si la liste est déjà vide.
 */
CouleursGraphe * cgSupprimerTete(CouleursGraphe * cg);

/**
 * \brief Supprimer un sommet de la liste.
 * \relatesalso Graphe
 * \param cg CouleursGraphe.
 * \param s Sommet.
 * \return (pointeur vers) CouleursGraphe.
 *
 * Supprime le ::Sommet \a s, si celui-ci existe. Si le ::Sommet \a s n'existe pas, \a cg reste intact.
 */
CouleursGraphe * cgSupprimerSommet(CouleursGraphe * cg, const Sommet * s);

/**
 * \brief Modifier un sommet de la liste.
 * \relatesalso Graphe
 * \param cg CouleursGraphe.
 * \param s Sommet.
 * \param c Couleur.
 * \return (pointeur vers) CouleursGraphe.
 *
 * Modifie la #Couleur du ::Sommet \a s par \a c, si le ::Sommet existe dans \a cg.
 */
CouleursGraphe * cgModifierSommet(CouleursGraphe * cg, const Sommet * s, Couleur c);

/**
 * \brief Initialiser les couleurs des sommets d'un graphe à BLANC.
 * \relatesalso CouleursGraphe
 * \param g Graphe.
 * \return (pointeur vers) CouleursGraphe.
 *
 * Retourne une liste CouleursGraphe contenant tous les ::Sommet du Graphe \a g, et initialisés à #BLANC.
 */
CouleursGraphe * cgInit(const Graphe * g);

/**
 * \brief Test de vacuité d'une liste de couleurs.
 * \relatesalso CouleursGraphe
 * \param cg CouleursGraphe.
 * \return #VRAI si la liste est vide, #FAUX sinon.
 *
 * Une liste CouleursGraphe \a cg est vide si \a cg pointe vers \a NULL.
 */
Bool cgEstVide(const CouleursGraphe * cg);

/**
 * \brief Test d'existence d'un sommet.
 * \relatesalso CouleursGraphe
 * \param cg CouleursGraphe.
 * \param s Sommet.
 * \return VRAI si le sommet existe, FAUX sinon.
 */
Bool cgExisteSommmet(const CouleursGraphe * cg, const Sommet * s);

/**
 * \brief Sommet suivant dans la liste.
 * \relatesalso CouleursGraphe
 * \param cg CouleursGraphe.
 * \return (pointeur vers) le sommet suivant dans la liste.
 *
 * Retourne un pointeur vers l'élément suivant dans la liste \a cg. Peut retourner une liste CouleursGraphe vide.
 */
CouleursGraphe * cgSuivant(const CouleursGraphe * cg);

/**
 * \brief ::Sommet en tête de liste.
 * \relatesalso CouleursGraphe
 * \param cg CouleursGraphe.
 * \pre !cgEstVide(cg)
 * \return Sommet.
 */
Sommet * cgSommetTete(const CouleursGraphe * cg);

/**
 * \brief #Couleur du ::Sommet en tête de liste.
 * \relatesalso CouleursGraphe
 * \param cg CouleursGraphe.
 * \pre !cgEstVide(cg)
 * \return Couleur.
 */
Couleur cgCouleurTete(const CouleursGraphe * cg);

/**
 * \brief #Couleur du Sommet \a s.
 * \relatesalso CouleursGraphe
 * \param cg CouleursGraphe.
 * \param s ::Sommet.
 * \pre cgExisteSommmet(cg)
 * \return #Couleur de \a s.
 */
Couleur cgCouleurSommet(const CouleursGraphe * cg, const Sommet * s);

/**
 * \brief Premier ::Sommet #NOIR dans \a cg.
 * \relatesalso CouleursGraphe
 * \param cg CouleursGraphe.
 * \return Premier ::Sommet #NOIR, \a NULL s'il n'y en a pas.
 */
Sommet * cgPremierSommetNoir(const CouleursGraphe * cg);

/**
 * \brief Premier ::Sommet #GRIS dans \a cg.
 * \relatesalso CouleursGraphe
 * \param cg CouleursGraphe.
 * \return Premier ::Sommet #GRIS, \a NULL s'il n'y en a pas.
 */
Sommet * cgPremierSommetGris(const CouleursGraphe * cg);

/**
 * \brief Premier ::Sommet #BLANC dans \a cg.
 * \relatesalso CouleursGraphe
 * \param cg CouleursGraphe.
 * \return Premier ::Sommet #BLANC, \a NULL s'il n'y en a pas.
 */
Sommet * cgPremierSommetBlanc(const CouleursGraphe * cg);

/**
 * \brief Nombre de ::Sommet dans \a cg.
 * \relatesalso CouleursGraphe
 * \param cg CouleursGraphe.
 * \return Nombre de ::Sommet.
 */
Nat cgNombreSommets(const CouleursGraphe * cg);

/**
 * \brief Nombre de ::Sommet #NOIR dans \a cg.
 * \relatesalso CouleursGraphe
 * \param cg CouleursGraphe.
 * \return Nombre de ::Sommet #NOIR.
 */
Nat cgNombreSommetsNoirs(const CouleursGraphe * cg);

/**
 * \brief Nombre de ::Sommet #GRIS dans \a cg.
 * \relatesalso CouleursGraphe
 * \param cg CouleursGraphe.
 * \return Nombre de ::Sommet #GRIS.
 */
Nat cgNombreSommetsGris(const CouleursGraphe * cg);

/**
 * \brief Nombre de ::Sommet #BLANC dans \a cg.
 * \relatesalso CouleursGraphe
 * \param cg CouleursGraphe.
 * \return Nombre de ::Sommet #BLANC.
ommets blancs.
 */
Nat cgNombreSommetsBlancs(const CouleursGraphe * cg);

/**
 * \brief Pointeur vers le sommet \a s.
 * \relatesalso CouleursGraphe
 * \param cg CouleursGraphe
 * \param s ::Sommet
 * \return (pointeur vers) le sommet dans la liste, \a NULL s'il n'existe pas.
 */
CouleursGraphe * cgPSommet(const CouleursGraphe * cg, const Sommet * s);

/**
 * \brief Libérer une liste de couleurs.
 * \relatesalso CouleursGraphe
 * \param cg CouleursGraphe.
 * \return \a NULL
 */
CouleursGraphe * cgLiberer(CouleursGraphe * cg);

#endif /* __COLORATION_H */
