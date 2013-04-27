/* This program is free software. It comes WITHOUT ANY WARRANTY, to
* the extent permitted by applicable law. You can redistribute it
* and/or modify it under the terms of the Do What The Fuck You Want
* To Public License, Version 2, as published by Sam Hocevar. See
* http://wtfpl.net for more details. */
/**
 * \file grapheconnexe.c
 * \brief GrapheConnexes (code)
 * \author Harenome RAZANAJATO
 */
#include "grapheconnexe.h"

GrapheConnexe * gcNouv(void)
{
    return gNouv();
}

GrapheConnexe * gcAjouterSommet(GrapheConnexe * g, const Sommet * s)
{
    if (gEstVide(g))
        return gAjouterSommet(g, s);
    else
        return g;
}

GrapheConnexe * gcAjouterArete(GrapheConnexe * g, const Sommet * a, const Sommet * b, Ent p)
{
    if (gEstVide(g) || gExisteSommet(g, a) || gExisteSommet(g, b))
        g = gAjouterArete(g, a, b, p);

    return g;
}

GrapheConnexe * gcSupprimerSommet(GrapheConnexe * g, const Sommet * s)
{
    GrapheConnexe * g0 = gSupprimerSommet(gCopier(g), s);

    if (gEstConnexe(g0))
    {
        g = gLiberer(g);

        return g0;
    }
    else
    {
        g0 = gLiberer(g0);

        return g;
    }
}

GrapheConnexe * gcSupprimerArete(GrapheConnexe * g, const Sommet * a, const Sommet * b)
{
    Ent p = gPoidsArete(g, a, b);
    g = gSupprimerArete(g, a, b);

    if (gEstConnexe(g))
        return g;
    else
        return gAjouterArete(g, a, b, p);
}

GrapheConnexe * gcModifierArete(GrapheConnexe * g, const Sommet * a, const Sommet * b, Ent p)
{
    return gModifierArete(g, a, b, p);
}
