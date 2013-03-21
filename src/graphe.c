/**
 * \file graphe.c
 * \brief Graphes (code)
 * \author Harenome RAZANAJATO
 */
#include "graphe.h"

Graphe gNouv(void)
{
    return NULL;
}

Graphe gAjoutSommet(Graphe g, Sommet s);
Graphe gAjoutArete(Graphe g, Sommet a, Sommet b, Ent p);
Graphe gSupprimerSommet(Graphe g, Sommet s);
Graphe gSupprimerArete(Graphe g, Sommet a, Sommet b);
Graphe gModifierArete(Graphe g, Sommet a, Sommet b, Ent p);

Bool gEstVide(Graphe g)
{
    return g == NULL;
}

Bool gExisteSommet(Graphe g, Sommet s)
{
    if (gEstVide(g)) return NULL;
    else if (egalSom(g->sommet, s)) return VRAI;
    else return gExisteSommet(g->suivant, s);
}

Bool gAArete(Graphe g, Sommet s)
{
    return !lest_vide(gAdjacenceSommet(g, s));
}

Bool gExisteArete(Graphe g, Sommet a, Sommet b)
{
    return lexar(gAdjacenceSommet(g, a), b);
}

ListeArete gAdjacenceSommet(Graphe g, Sommet s)
{
    Graphe g0 = gPSommet(g, s);
    return g0->listeadjacence;
}

/* Fonction auxiliaire pour que la récursivité soit terminale. */
static Nat gNombreSommetsAux(Graphe g, Nat n)
{
    if (gEstVide(g)) return n;
    else return gNombreSommetsAux(g->suivant, n+1);
}

Nat gNombreSommets(Graphe g)
{
    return gNombreSommetsAux(g, 0);
}

/* Fonction auxiliaire pour que la récursivité soit terminale. */
static Nat gNombreAretesAux(Graphe g, Nat n)
{
    if (gEstVide(g)) return n;
    else return gNombreAretesAux(g->suivant, n + ltaille(g->sommet));
}

Nat gNombreAretes(Graphe g)
{
    return gNombreAretesAux(g, 0) / 2;
}

Nat gNombreVoisins(Graphe g, Sommet s)
{
    return ltaille(gAdjacenceSommet(g, s));
}

Graphe gPSommet(Graphe g, Sommet s)
{
    if (gEstVide(g))
        return NULL;
    else if (egalSom(g->sommet, s))
        return g;
    else
        return gPSommet(g->suivant, s);
}
