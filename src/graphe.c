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

Graphe gAjoutSommet(Graphe g, const Sommet s)
{
    if (!gExisteSommet(g, s))
    {
        Graphe g0 = NULL;
        g0 = MALLOC(g0);
        if (g0 != NULL)
        {
            g0->sommet = copieSommet(s);
            g0->listeadjacence = listnouv();
            g0->suivant = g;
            g = g0;
        }
    }

    return g;
}

Graphe gAjoutArete(Graphe g, const Sommet a, const Sommet b, Ent p)
{
    Graphe ga, gb;

    if (!gExisteSommet(g, a))
        g = gAjoutSommet(g, a);
    if (!gExisteSommet(g, b))
        g = gAjoutSommet(g, b);

    ga = gPSommet(g, a);
    ga->listeadjacence = lajar(ga->listeadjacence, b, p);
    gb = gPSommet(g, b);
    gb->listeadjacence = lajar(gb->listeadjacence, a, p);

    return g;
}

static Graphe gPrecedent(const Graphe g, const Sommet s)
{
    if (gEstVide(g)) return NULL;
    else if (gEstVide(g->suivant)) return NULL;
    else if (egalSom(g->suivant->sommet, s)) return g;
    else return gPrecedent(g->suivant, s);
}

Graphe gSupprimerSommet(Graphe g, const Sommet s)
{
    if (!gEstVide(g) && gExisteSommet(g, s) && !gAArete(g, s))
    {
        Graphe gp = gPrecedent(g, s);

        if (gp == NULL)
        {
            g->sommet = libererSommet(s);
            free(g);
            g = NULL;
        }
        else
        {
            Graphe gps = g->suivant->suivant;

            gp->suivant->sommet = libererSommet(gp->suivant->sommet);
            free(gp->suivant);
            gp->suivant = gps;
        }
    }

    return g;
}

Graphe gSupprimerArete(Graphe g, const Sommet a, const Sommet b)
{
    if (gExisteSommet(g, a) && gExisteSommet(g, b))
    {
        Graphe ga = gPSommet(g, a);
        Graphe gb = gPSommet(g, b);

        ga->listeadjacence = lsupar(ga->listeadjacence, b);
        gb->listeadjacence = lsupar(gb->listeadjacence, a);
    }

    return g;
}

Graphe gModifierArete(Graphe g, const Sommet a, const Sommet b, Ent p)
{
    if (!gExisteSommet(g, a))
        g = gAjoutSommet(g, a);
    if (!gExisteSommet(g, b))
        g = gAjoutSommet(g, b);

    if (!gExisteArete(g, a, b))
        gAjoutArete(g, a, b, p);
    else
    {
        Graphe ga = gPSommet(g, a);
        Graphe gb = gPSommet(g, b);

        ga->listeadjacence = lmod(gAdjacenceSommet(g, a), b, p);
        gb->listeadjacence = lmod(gAdjacenceSommet(g, b), a, p);
    }

    return g;
}

Bool gEstVide(const Graphe g)
{
    return g == NULL;
}

Bool gExisteSommet(const Graphe g, const Sommet s)
{
    if (gEstVide(g)) return FAUX;
    else if (egalSom(g->sommet, s)) return VRAI;
    else return gExisteSommet(g->suivant, s);
}

Bool gAArete(const Graphe g, const Sommet s)
{
    return !lest_vide(gAdjacenceSommet(g, s));
}

Bool gExisteArete(const Graphe g, const Sommet a, const Sommet b)
{
    return lexar(gAdjacenceSommet(g, a), b);
}

ListeArete gAdjacenceSommet(const Graphe g, const Sommet s)
{
    Graphe g0 = gPSommet(g, s);

    if (g0 != NULL)
        return g0->listeadjacence;
    else
        return NULL;
}

/* Fonction auxiliaire pour que la récursivité soit terminale. */
static Nat gNombreSommetsAux(const Graphe g, Nat n)
{
    if (gEstVide(g)) return n;
    else return gNombreSommetsAux(g->suivant, n+1);
}

Nat gNombreSommets(const Graphe g)
{
    return gNombreSommetsAux(g, 0);
}

/* Fonction auxiliaire pour que la récursivité soit terminale. */
static Nat gNombreAretesAux(const Graphe g, Nat n)
{
    if (gEstVide(g)) return n;
    else return gNombreAretesAux(g->suivant, n + ltaille(g->listeadjacence));
}

Nat gNombreAretes(const Graphe g)
{
    return gNombreAretesAux(g, 0) / 2;
}

Nat gNombreVoisins(const Graphe g, const Sommet s)
{
    ListeArete adjacence = gAdjacenceSommet(g, s);
    if (lexar(adjacence, s))
        return ltaille(gAdjacenceSommet(g, s)) - 1;
    else
        return ltaille(gAdjacenceSommet(g, s));
}

Ent gPoidsArete(const Graphe g, const Sommet a, const Sommet b)
{
    return lpoids(gAdjacenceSommet(g, a), b);
}

Graphe gPSommet(const Graphe g, const Sommet s)
{
    if (gEstVide(g)) return NULL;
    else if (egalSom(g->sommet, s)) return g;
    else return gPSommet(g->suivant, s);
}

static Bool gEgaliteAux(const Graphe g, const Graphe h)
{
    if (g == NULL) return VRAI;
    else if (!gExisteSommet(h, g->sommet)) return FAUX;
    else if (!lega(gAdjacenceSommet(h, g->sommet), g->listeadjacence)) return FAUX;
    else return gEgaliteAux(g->suivant, h);
}

Bool gEgalite(const Graphe g, const Graphe h)
{
    if (gNombreSommets(g) != gNombreSommets(h) || gNombreAretes(g) != gNombreAretes(h))
        return FAUX;
    else
        return gEgaliteAux(g, h);
}

static Graphe gCopieSommets(Graphe copie, Graphe g)
{
    if (g == NULL) return copie;
    else return gCopieSommets(gAjoutSommet(copie, g->sommet), g->suivant);
}

static Graphe gCopieAretes(Graphe copie, Graphe g)
{
    Graphe c = NULL;

    while (g != NULL)
    {
        c = gPSommet(copie, g->sommet);
        c->listeadjacence = lcopie(g->listeadjacence);
        g = g->suivant;
    }

    return copie;
}

Graphe gCopie(const Graphe g)
{
    return gCopieAretes(gCopieSommets(gNouv(), g), g);
}

Graphe gLiberer(Graphe g)
{
    if (g == NULL)
        return NULL;
    else
    {
        Graphe g0 = g->suivant;
        g->sommet = libererSommet(g->sommet);
        g->listeadjacence = lliberer(g->listeadjacence);
        free(g);

        return gLiberer(g0);
    }
}
