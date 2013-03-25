/**
 * \file coloration.c
 * \brief Coloration d'un graphe (code)
 * \author Harenome RAZANAJATO
 */

#include "coloration.h"

CouleursGraphe cgNouv(void)
{
    return NULL;
}

CouleursGraphe cgAjouterSommet(CouleursGraphe cg, const Sommet s, Couleur c)
{
    CouleursGraphe cg0 = NULL;

    cg0 = MALLOC(cg0);
    if (cg0 != NULL)
    {
        cg0->sommet = copieSommet(s);
        cg0->couleur = c;
        cg0->suivant = cg;
        cg = cg0;
    }

    return cg;
}

CouleursGraphe cgSupprimerTete(CouleursGraphe cg)
{
    CouleursGraphe cg0 = cg->suivant;
    cg->sommet = libererSommet(cg->sommet);
    free(cg);

    return cg0;
}

static CouleursGraphe cgPrecedent(const CouleursGraphe cg, const Sommet s)
{
    if (cgEstVide(cg)) return NULL;
    else if (cgEstVide(cgSuivant(cg))) return NULL;
    else if (egalSom(cgSommetTete(cgSuivant(cg)), s)) return cg;
    else return cgPrecedent(cgSuivant(cg), s);
}

CouleursGraphe cgSupprimerSommet(CouleursGraphe cg, const Sommet s)
{
    CouleursGraphe cgp = cgPrecedent(cg, s);

    if (cgp != NULL)
    {
        cgp->suivant = cgSupprimerTete(cgSuivant(cgp));
    }

    return cg;
}

CouleursGraphe cgModifierSommet(CouleursGraphe cg, const Sommet s, Couleur c)
{
    CouleursGraphe cg0 = cgPSommet(cg, s);

    if (cg0 != NULL)
        cg0->couleur = c;

    return cg;
}

static CouleursGraphe cgInitAux(CouleursGraphe cg, Graphe g)
{
    if (gEstVide(g)) return cg;
    else return cgInitAux(cgAjouterSommet(cg, gSommetTete(g), BLANC), gSuivant(g));
}

CouleursGraphe cgInit(const Graphe g)
{
    return cgInitAux(cgNouv(), g);
}

Bool cgEstVide(const CouleursGraphe cg)
{
    return cg == NULL;
}

CouleursGraphe cgSuivant(const CouleursGraphe cg)
{
    if (cgEstVide(cg))
        return NULL;
    else
        return cg->suivant;
}

Sommet cgSommetTete(const CouleursGraphe cg)
{
    return cg->sommet;
}

Couleur cgCouleurTete(const CouleursGraphe cg)
{
    return cg->couleur;
}

Couleur cgCouleurSommet(const CouleursGraphe cg, const Sommet s)
{
    return cgCouleurTete(cgPSommet(cg, s));
}

static Sommet cgPremierSommetCouleur(const CouleursGraphe cg, Couleur c)
{
    if (cgEstVide(cg)) return NULL;
    else if (cgCouleurTete(cg) == c) return cgSommetTete(cg);
    else return cgPremierSommetCouleur(cgSuivant(cg), c);
}

Sommet cgPremierSommetNoir(const CouleursGraphe cg)
{
    return cgPremierSommetCouleur(cg, NOIR);
}

Sommet cgPremierSommetGris(const CouleursGraphe cg)
{
    return cgPremierSommetCouleur(cg, GRIS);
}

Sommet cgPremierSommetBlanc(const CouleursGraphe cg)
{
    return cgPremierSommetCouleur(cg, BLANC);
}

static Nat cgNombreSommetsCouleur(const CouleursGraphe cg, Couleur c, Nat n)
{
    if (cgEstVide(cg)) return n;
    else if (cgCouleurTete(cg) == c) return cgNombreSommetsCouleur(cgSuivant(cg), c, n+1);
    else return cgNombreSommetsCouleur(cgSuivant(cg), c, n);
}

Nat cgNombreSommetsNoirs(const CouleursGraphe cg)
{
    return cgNombreSommetsCouleur(cg, NOIR, 0);
}

Nat cgNombreSommetsGris(const CouleursGraphe cg)
{
    return cgNombreSommetsCouleur(cg, GRIS, 0);
}

Nat cgNombreSommetsBlancs(const CouleursGraphe cg)
{
    return cgNombreSommetsCouleur(cg, BLANC, 0);
}

CouleursGraphe cgPSommet(const CouleursGraphe cg, const Sommet s)
{
    if (cgEstVide(cg)) return NULL;
    else if (egalSom(cgSommetTete(cg), s)) return cg;
    else return cgPSommet(cgSuivant(cg), s);
}

CouleursGraphe cgLiberer(CouleursGraphe cg)
{
    if (cgEstVide(cg)) return NULL;
    else return cgLiberer(cgSupprimerTete(cg));
}

