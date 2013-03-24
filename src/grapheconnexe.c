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
        GrapheConnexe ga, gb;

        if (!gExisteSommet(g, a))
            g = gAjouterSommet(g, a);
        else if (!gExisteSommet(g, b))
            g = gAjouterSommet(g, b);

        ga = gPSommet(g, a);
        ga->listeadjacence = lajar(ga->listeadjacence, b, p);
        gb = gPSommet(g, b);
        gb->listeadjacence = lajar(gb->listeadjacence, a, p);
    }

    return g;
}

/* TODO. */
GrapheConnexe gcSupprimerSommet(GrapheConnexe g, const Sommet s);

/* TODO. */
GrapheConnexe gcSupprimerArete(GrapheConnexe g, const Sommet a, const Sommet b);

GrapheConnexe gcModifierArete(GrapheConnexe g, const Sommet a, const Sommet b, Ent p)
{
    return gModifierArete(g, a, b, p);
}
