/**
 * \file arete.h
 * \brief Arete (header)
 * \author Harenome RAZANAJATO
 */
#ifndef __ARETE_H
#define __ARETE_H

#include <stdlib.h>
#include <stdio.h>

#include "base.h"
#include "sommet.h"

typedef struct
{
    Sommet a;
    Sommet b;
    Ent poids;
} StrArete, *Arete;

Arete aNouv(const Sommet a, const Sommet b, Ent poids);

Sommet aA(const Arete a);

Sommet aB(const Arete a);

Ent aPoids(const Arete a);

Bool aAreteEgaleS2(const Arete a, const Arete b);

Bool aAreteEgaleP(const Arete a, const Sommet s, const Sommet t, Ent poids);

Bool aAreteEgaleP2(const Arete a, const Arete b);

Bool aAreteEgaleS(const Arete a, const Sommet s, const Sommet t);

Arete aLiberer(Arete a);

#endif /* __ARETE_H */
