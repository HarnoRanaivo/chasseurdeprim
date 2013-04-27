/* This program is free software. It comes WITHOUT ANY WARRANTY, to
* the extent permitted by applicable law. You can redistribute it
* and/or modify it under the terms of the Do What The Fuck You Want
* To Public License, Version 2, as published by Sam Hocevar. See
* http://wtfpl.net for more details. */
/**
 * \file arete.c
 * \brief Aretes (code)
 * \author Harenome RAZANAJATO
 */

#include "arete.h"

Arete * aNouv(const Sommet * a, const Sommet * b, Ent poids)
{
    Arete * const a0 = MALLOC(a0);

    if (a0 != NULL && a != NULL && b != NULL)
    {
        a0->a = copieSommet(a);
        a0->b = copieSommet(b);
        a0->poids = poids;
    }

    return a0;
}

Sommet * aA(const Arete * a)
{
    return a->a;
}

Sommet * aB(const Arete * a)
{
    return a->b;
}

Ent aPoids(const Arete * a)
{
    return a->poids;
}

Bool aAreteEgaleS2(const Arete * a, const Arete * b)
{
    if (a == NULL && b == NULL) return VRAI;
    else if (a == NULL || b == NULL) return FAUX;
    else return aAreteEgaleS(a, aA(b), aB(b));
}

Bool aAreteEgaleP(const Arete * a, const Sommet * s, const Sommet * t, Ent poids)
{
    if (a == NULL && s == NULL && t == NULL && poids == 0) return VRAI;
    else if (a == NULL) return FAUX;
    return aAreteEgaleS(a, s, t) && (aPoids(a) == poids);
}

Bool aAreteEgaleP2(const Arete * a, const Arete * b)
{
    if (a == NULL && b == NULL) return VRAI;
    else if (a == NULL || b == NULL) return FAUX;
    else return aAreteEgaleP(a, aA(b), aB(b), aPoids(b));
}

Bool aAreteEgaleS(const Arete * a, const Sommet * s, const Sommet * t)
{
    if (a == NULL && s == NULL && t == NULL) return VRAI;
    else if (a == NULL) return FAUX;
    else return (egalSom(aA(a), s) && egalSom(aB(a), t)) || (egalSom(aA(a), t) && egalSom(aB(a), s));
}

Arete * aLiberer(Arete * a)
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
