/**
 * \file arete.c
 * \brief Aretes (code)
 * \author Harenome RAZANAJATO
 */

#include "arete.h"

Arete aNouv(const Sommet a, const Sommet b, Ent poids)
{
    Arete a0 = MALLOC(a0);

    if (a0 != NULL)
    {
        a0->a = copieSommet(a);
        a0->b = copieSommet(b);
        a0->poids = poids;
    }

    return a0;
}

Sommet aA(const Arete a)
{
    return a->a;
}

Sommet aB(const Arete a)
{
    return a->b;
}

Ent aPoids(const Arete a)
{
    return a->poids;
}

Bool aAreteEgaleS2(const Arete a, const Arete b)
{
    return aAreteEgaleS(a, aA(b), aB(b));
}

Bool aAreteEgaleP(const Arete a, const Arete b)
{
    return aAreteEgaleS2(a, b) && (aPoids(a) == aPoids(b));
}

Bool aAreteEgaleS(const Arete a, const Sommet s, const Sommet t)
{
    return (egalSom(aA(a), s) && egalSom(aB(a), t)) || (egalSom(aA(a), t) && egalSom(aB(a), s));
}

Arete aLiberer(Arete a)
{
    if (a != NULL)
    {
        a->a = libererSommet(aA(a));
        a->b = libererSommet(aB(a));
        free(a);
        a = NULL;
    }

    return a;
}
