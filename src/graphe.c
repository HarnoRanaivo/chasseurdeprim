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

Graphe gAjoutSommet(Graphe g, Sommet s)
{
    if (!gExisteSommet(g, s))
    {
        Graphe g0 = NULL;
        g0 = MALLOC(g0);
        if (g0 != NULL)
        {
            g0->sommet = s;
            g0->listeadjacence = listnouv();
            g0->suivant = g;
            g = g0;
        }
    }

    return g;
}

Graphe gAjoutArete(Graphe g, Sommet a, Sommet b, Ent p)
{
    if (!gExisteArete(g, a, b))
    {
        Graphe ga, gb;

        if (!gExisteSommet(g, a) && gExisteSommet(g, b))
            g = gAjoutSommet(g, a);
        else if (!gExisteSommet(g, b) && gExisteSommet(g, b))
            g = gAjoutSommet(g, b);

        ga = gPSommet(g, a);
        ga->listeadjacence = lajar(ga->listeadjacence, b, p);
        gb = gPSommet(g, b);
        gb->listeadjacence = lajar(gb->listeadjacence, a, p);
    }

    return g;
}

static Graphe gPrecedent(Graphe g, Sommet s)
{
    if (gEstVide(g)) return NULL;
    else if (gEstVide(g->suivant)) return NULL;
    else if (egalSom(g->suivant->sommet, s)) return g;
    else return gPrecedent(g->suivant, s);
}

/* TODO. */
Graphe gSupprimerSommet(Graphe g, Sommet s);

Graphe gSupprimerArete(Graphe g, Sommet a, Sommet b)
{
    Graphe ga = gPSommet(g, a);
    Graphe gb = gPSommet(g, b);

    ga->listeadjacence = lsupar(ga->listeadjacence, b);
    gb->listeadjacence = lsupar(gb->listeadjacence, a);

    return g;
}

/* TODO. */
Graphe gModifierArete(Graphe g, Sommet a, Sommet b, Ent p);

Bool gEstVide(Graphe g)
{
    return g == NULL;
}

Bool gExisteSommet(Graphe g, Sommet s)
{
    if (gEstVide(g)) return FAUX;
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
    else return gNombreAretesAux(g->suivant, n + ltaille(g->listeadjacence));
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
