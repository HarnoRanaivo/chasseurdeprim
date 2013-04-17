/**
 * \file listearete.c
 * \brief Liste d'arêtes (header)
 * \author Harenome RAZANAJATO
 */
#include "listearete.h"

ListeArete * larNouv(void)
{
    return NULL;
}

ListeArete * larAjouterAreteTete(ListeArete * l, const Sommet * a, const Sommet * b, Ent poids)
{
    if (!larExisteArete(l, a, b))
    {
        ListeArete * const l0 = MALLOC(l0);

        if (l0 != NULL)
        {
            l0->arete = aNouv(a, b, poids);
            l0->suivante = l;
            l = l0;
        }
    }
    return l;
}

ListeArete * larSupprimerTete(ListeArete * l)
{
    if (!larEstVide(l))
    {
        ListeArete * ls = larSuivante(l);
        l->arete = aLiberer(larAreteTete(l));
        free(l);
        l = ls;
    }

    return l;
}

static ListeArete * larPrecedente(const ListeArete * l, const Sommet * a, const Sommet * b)
{
    if (larEstVide(l)) return NULL;
    else if (larEstVide(larSuivante(l))) return NULL;
    else if (aAreteEgaleS(larAreteTete(larSuivante(l)), a, b)) return (ListeArete *)l;
    else return larPrecedente(larSuivante(l), a, b);
}

ListeArete * larSupprimerArete(ListeArete * l, const Sommet * a, const Sommet * b)
{
    if (!larEstVide(l))
    {
        if (aAreteEgaleS(larAreteTete(l), a, b))
            l = larSupprimerTete(l);
        else
        {
            ListeArete * lp = larPrecedente(l, a, b);

            if (lp != NULL)
                lp->suivante = larSupprimerTete(larSuivante(lp));
        }
    }

    return l;
}

Bool larEstVide(const ListeArete * l)
{
    return l == NULL;
}

Bool larExisteArete(const ListeArete * l, const Sommet * a, const Sommet * b)
{
    if (larEstVide(l)) return FAUX;
    else if (aAreteEgaleS(larAreteTete(l), a, b)) return VRAI;
    else return larExisteArete(larSuivante(l), a, b);
}

static Nat larNombreAretesAux(const ListeArete * l, Nat n)
{
    if (larEstVide(l)) return n;
    else return larNombreAretesAux(larSuivante(l), n+1);
}

Nat larNombreAretes(const ListeArete * l)
{
    return larNombreAretesAux(l, 0);
}

Arete * larAreteTete(const ListeArete * l)
{
    return l->arete;
}

ListeArete * larSuivante(const ListeArete * l)
{
    if (!larEstVide(l))
        return l->suivante;
    else
        return NULL;
}

ListeArete * larPArete(const ListeArete * l, const Sommet * a, const Sommet * b)
{
    if (larEstVide(l)) return NULL;
    else if (aAreteEgaleS(larAreteTete(l), a, b)) return (ListeArete *)l;
    else return larPArete(larSuivante(l), a, b);
}


ListeArete * larLiberer(ListeArete * l)
{
    while (!larEstVide(l))
        l = larSupprimerTete(l);

    return l;
}
