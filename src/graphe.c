/**
 * \file graphe.c
 * \brief Graphes (code)
 * \author Harenome RAZANAJATO
 */
#include "graphe.h"

Graphe * gNouv(void)
{
    return NULL;
}

Graphe * gAjouterSommet(Graphe * g, const Sommet * s)
{
    if (!gExisteSommet(g, s))
    {
        Graphe * const g0 = MALLOC(g0);
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

Graphe * gAjouterArete(Graphe * g, const Sommet * a, const Sommet * b, Ent p)
{
    if (!gExisteArete(g, a, b))
    {
        if (!gExisteSommet(g, a))
            g = gAjouterSommet(g, a);
        if (!gExisteSommet(g, b))
            g = gAjouterSommet(g, b);

        if (gExisteSommet(g, a) && gExisteSommet(g, b))
        {
            Graphe * const ga = gPSommet(g, a);
            Graphe * const gb = gPSommet(g, b);

            ga->listeadjacence = lajar(gAdjacenceTete(ga), b, p);
            gb->listeadjacence = lajar(gAdjacenceTete(gb), a, p);
        }
    }

    return g;
}

static Graphe * gPrecedent(const Graphe * g, const Sommet * s)
{
    if (gEstVide(g)) return NULL;
    else if (gEstVide(gSuivant(g))) return NULL;
    else if (egalSom(gSommetTete(gSuivant(g)), s)) return (Graphe *)g;
    else return gPrecedent(gSuivant(g), s);
}

Graphe * gSupprimerSommet(Graphe * g, const Sommet * s)
{
    if (!gEstVide(g) && gExisteSommet(g, s))
    {
        if (egalSom(gSommetTete(g), s))
        {
            Graphe * const gs = gSuivant(g);
            while (!lest_vide(gAdjacenceTete(g)))
                g = gSupprimerArete(g, s, lsommet_tete(gAdjacenceTete(g)));
            g->sommet = libererSommet(gSommetTete(g));
            free(g);
            g = gs;
        }
        else
        {
            Graphe * const gp = gPrecedent(g, s);
            Graphe * const gps = gSuivant(gSuivant(gp));

            while (!lest_vide(gAdjacenceTete(gSuivant(gp))))
                g = gSupprimerArete(g, s, lsommet_tete(gAdjacenceTete(gSuivant(gp))));
            gp->suivant->sommet = libererSommet(gSommetTete(gSuivant(gp)));
            free(gSuivant(gp));
            gp->suivant = gps;
        }
    }

    return g;
}

Graphe * gSupprimerArete(Graphe * g, const Sommet * a, const Sommet * b)
{
    if (gExisteSommet(g, a) && gExisteSommet(g, b))
    {
        Graphe * const ga = gPSommet(g, a);
        Graphe * const gb = gPSommet(g, b);

        ga->listeadjacence = lsupar(gAdjacenceTete(ga), b);
        gb->listeadjacence = lsupar(gAdjacenceTete(gb), a);
    }

    return g;
}

Graphe * gModifierArete(Graphe * g, const Sommet * a, const Sommet * b, Ent p)
{
    if (gExisteArete(g, a, b))
    {
        Graphe * const ga = gPSommet(g, a);
        Graphe * const gb = gPSommet(g, b);

        ga->listeadjacence = lmod(gAdjacenceTete(ga), b, p);
        gb->listeadjacence = lmod(gAdjacenceTete(gb), a, p);
    }

    return g;
}

Bool gEstVide(const Graphe * g)
{
    return g == NULL;
}

Graphe * gSuivant(const Graphe * g)
{
    if (!gEstVide(g))
        return g->suivant;
    else
        return NULL;
}

Sommet * gSommetTete(const Graphe * g)
{
    return g->sommet;
}

ListeAdjacence * gAdjacenceTete(const Graphe * g)
{
    return g->listeadjacence;
}

Bool gExisteSommet(const Graphe * g, const Sommet * s)
{
    if (gEstVide(g)) return FAUX;
    else if (egalSom(gSommetTete(g), s)) return VRAI;
    else return gExisteSommet(gSuivant(g), s);
}

Bool gAArete(const Graphe * g, const Sommet * s)
{
    return !lest_vide(gAdjacenceSommet(g, s));
}

Bool gExisteArete(const Graphe * g, const Sommet * a, const Sommet * b)
{
    return lexar(gAdjacenceSommet(g, a), b);
}

ListeAdjacence * gAdjacenceSommet(const Graphe * g, const Sommet * s)
{
    Graphe * const g0 = gPSommet(g, s);

    if (g0 != NULL)
        return g0->listeadjacence;
    else
        return NULL;
}

/* Fonction auxiliaire pour que la récursivité soit terminale. */
static Nat gNombreSommetsAux(const Graphe * g, Nat n)
{
    if (gEstVide(g)) return n;
    else return gNombreSommetsAux(gSuivant(g), n+1);
}

Nat gNombreSommets(const Graphe * g)
{
    return gNombreSommetsAux(g, 0);
}

/* Fonction auxiliaire pour que la récursivité soit terminale. */
static Nat gNombreAretesAux(const Graphe * g, Nat n)
{
    if (gEstVide(g)) return n;
    else return gNombreAretesAux(gSuivant(g), n + ltaille(gAdjacenceTete(g)));
}

Nat gNombreAretes(const Graphe * g)
{
    return gNombreAretesAux(g, 0) / 2;
}

Nat gNombreVoisins(const Graphe * g, const Sommet * s)
{
    const ListeAdjacence * const adjacence = gAdjacenceSommet(g, s);

    if (lexar(adjacence, s))
        return ltaille(adjacence) - 1;
    else
        return ltaille(adjacence);
}

Ent gPoidsArete(const Graphe * g, const Sommet * a, const Sommet * b)
{
    return lpoids(gAdjacenceSommet(g, a), b);
}

Graphe * gPSommet(const Graphe * g, const Sommet * s)
{
    if (gEstVide(g)) return NULL;
    else if (egalSom(gSommetTete(g), s)) return (Graphe *)g;
    else return gPSommet(gSuivant(g), s);
}

static Bool gEgaliteAux(const Graphe * g, const Graphe * h)
{
    if (g == NULL) return VRAI;
    else if (!gExisteSommet(h, gSommetTete(g))) return FAUX;
    else if (!lega(gAdjacenceSommet(h, gSommetTete(g)), gAdjacenceTete(g))) return FAUX;
    else return gEgaliteAux(gSuivant(g), h);
}

Bool gEgalite(const Graphe * g, const Graphe * h)
{
    if (gNombreSommets(g) != gNombreSommets(h) || gNombreAretes(g) != gNombreAretes(h))
        return FAUX;
    else
        return gEgaliteAux(g, h);
}

Graphe * gCopier(const Graphe * g)
{
    Graphe * copie = gNouv();

    for (g = g; !gEstVide(g); g = gSuivant(g))
    {
        ListeAdjacence * l;

        Sommet * s = gSommetTete(g);
        copie = gAjouterSommet(copie, s);

        for (l = gAdjacenceTete(g); !lest_vide(l); l = lsuiv(l))
            copie = gAjouterArete(copie, s, lsommet_tete(l), lpoids_tete(l));
    }

    return copie;
}

ListeArete * gAretes(const Graphe * g)
{
    ListeArete * aretes = larNouv();

    for (g = g; !gEstVide(g); g = gSuivant(g))
    {
        for (const ListeAdjacence * l = gAdjacenceTete(g); !lest_vide(l); l = lsuiv(l))
            aretes = larAjouterAreteTete(aretes, gSommetTete(g), lsommet_tete(l), lpoids_tete(l));
    }

    return aretes;
}

Graphe * gLiberer(Graphe * g)
{
    if (g == NULL)
        return NULL;
    else
    {
        Graphe * g0 = gSuivant(g);
        g->sommet = libererSommet(gSommetTete(g));
        g->listeadjacence = lliberer(gAdjacenceTete(g));
        free(g);

        return gLiberer(g0);
    }
}
