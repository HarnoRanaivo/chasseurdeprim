/**
 * \file parcours.c
 * \brief Parcours d'un graphe (code)
 * \author Harenome RAZANAJATO
 */

#include "parcours.h"

CouleursGraphe gParcoursLargeur(const Graphe g)
{
    Sommet s1;
    CouleursGraphe cg = cgInit(g);

    cg = cgModifierSommet(cg, gSommetTete(g), GRIS);

    while((s1 = cgPremierSommetGris(cg)) != NULL)
    {
        ListeArete l;
        while(!lest_vide((l = gAdjacenceSommet(g, s1))))
        {
            Sommet s2 = lsommet_tete(l);
            if (cgCouleurSommet(cg, s2) == BLANC)
                cg = cgModifierSommet(cg, s2, GRIS);
            l = lsuiv(l);
        }
        cg = cgModifierSommet(cg, s1, NOIR);
    }

    return cg;
}

Bool gEstConnexe(const Graphe g)
{
    int n;
    CouleursGraphe cg;

    cg = gParcoursLargeur(g);
    n = cgNombreSommetsNoirs(cg);
    cg = cgLiberer(cg);

    return gNombreSommets(g) == n;
}
