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

typedef enum
{
    NOIR,
    GRIS,
    BLANC
} Couleur;

typedef struct couleurgraphe
{
    Sommet sommet;
    Couleur couleur;
    struct couleurgraphe * suivant;
} StrCouleursGraphe, *CouleursGraphe;

CouleursGraphe cgNouv(void);

CouleursGraphe cgAjouterSommet(CouleursGraphe cg, const Sommet s, Couleur c);

CouleursGraphe cgSupprimerTete(CouleursGraphe cg);

CouleursGraphe cgSupprimerSommet(CouleursGraphe cg, const Sommet s);

CouleursGraphe cgModifierSommet(CouleursGraphe cg, const Sommet s, Couleur c);

CouleursGraphe cgInit(const Graphe g);

Bool cgEstVide(const CouleursGraphe cg);

CouleursGraphe cgSuivant(const CouleursGraphe cg);

Sommet cgSommetTete(const CouleursGraphe cg);

Couleur cgCouleurTete(const CouleursGraphe cg);

Couleur cgCouleurSommet(const CouleursGraphe cg, const Sommet s);

Sommet cgPremierSommetNoir(const CouleursGraphe cg);

Sommet cgPremierSommetGris(const CouleursGraphe cg);

Sommet cgPremierSommetBlanc(const CouleursGraphe cg);

Nat cgNombreSommetsNoirs(const CouleursGraphe cg);

Nat cgNombreSommetsGris(const CouleursGraphe cg);

Nat cgNombreSommetsBlancs(const CouleursGraphe cg);

CouleursGraphe cgPSommet(const CouleursGraphe cg, const Sommet s);

CouleursGraphe cgLiberer(CouleursGraphe cg);

#endif /* __COLORATION_H */
