/**
 * \file grapheconnexe.c
 * \brief GrapheConnexes (code)
 * \author Harenome RAZANAJATO
 */
#include "grapheconnexe.h"

GrapheConnexe gcNouv(void)
{
    return gNouv();
}

GrapheConnexe gcAjouterSommet(GrapheConnexe g, const Sommet s)
{
    if (gEstVide(g))
        return gAjouterSommet(g, s);
    else
        return g;
}

GrapheConnexe gcAjouterArete(GrapheConnexe g, const Sommet a, const Sommet b, Ent p)
{
    if (!gExisteArete(g, a, b) && (gExisteSommet(g, a) || gExisteSommet(g, b)))
    {
        if (!gExisteSommet(g, a))
            g = gAjouterSommet(g, a);
        else if (!gExisteSommet(g, b))
            g = gAjouterSommet(g, b);

        g = gModifierArete(g, a, b, p);
    }

    return g;
}

GrapheConnexe gcSupprimerSommet(GrapheConnexe g, const Sommet s)
{
    GrapheConnexe g0 = gSupprimerSommet(gCopier(g), s);

    if (gEstConnexe(g0))
    {
        g = gLiberer(g);

        return g0;
    }
    else
    {
        g0 = gLiberer(g);

        return g;
    }
}

GrapheConnexe gcSupprimerArete(GrapheConnexe g, const Sommet a, const Sommet b)
{
    Ent p = gPoidsArete(g, a, b);
    g = gSupprimerArete(g, a, b);

    if (gEstConnexe(g))
        return g;
    else
        return gAjouterArete(g, a, b, p);
}

GrapheConnexe gcModifierArete(GrapheConnexe g, const Sommet a, const Sommet b, Ent p)
{
    return gModifierArete(g, a, b, p);
}
