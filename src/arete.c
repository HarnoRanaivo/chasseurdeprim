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
