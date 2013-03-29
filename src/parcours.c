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

    if (!gEstVide(g))
    {
        cg = cgModifierSommet(cg, gSommetTete(g), GRIS);

        while((s1 = cgPremierSommetGris(cg)) != NULL)
        {
            ListeArete l = gAdjacenceSommet(g, s1);
            while(!lest_vide(l))
            {
                Sommet s2 = lsommet_tete(l);
                if (cgCouleurSommet(cg, s2) == BLANC)
                    cg = cgModifierSommet(cg, s2, GRIS);
                l = lsuiv(l);
            }
            cg = cgModifierSommet(cg, s1, NOIR);
        }
    }

    return cg;
}

Bool gEstConnexe(const Graphe g)
{
    int n = gNombreSommets(g);

    if (n == 0)
        return FAUX;
    else if (n == 1)
    {
        return gExisteArete(g, gSommetTete(g), gSommetTete(g));
    }
    else
    {
        int noirs;
        CouleursGraphe cg;

        cg = gParcoursLargeur(g);
        noirs = cgNombreSommetsNoirs(cg);
        cg = cgLiberer(cg);

        return gNombreSommets(g) == noirs;
    }
}

Bool gACycle(const Graphe g)
{
    int n = gNombreSommets(g);

    if (n == 0)
        return FAUX;
    else if (n == 1)
    {
        return gExisteArete(g, gSommetTete(g), gSommetTete(g));
    }
    else
    {
        Sommet s1;
        CouleursGraphe cg = cgInit(g);

        cg = cgModifierSommet(cg, gSommetTete(g), GRIS);

        while((s1 = cgPremierSommetGris(cg)) != NULL)
        {
            ListeArete l = gAdjacenceSommet(g, s1);
            while(!lest_vide(l))
            {
                Sommet s2 = lsommet_tete(l);
                if (cgCouleurSommet(cg, s2) == BLANC)
                    cg = cgModifierSommet(cg, s2, GRIS);
                else if (cgCouleurSommet(cg, s2) == GRIS)
                    return VRAI;
                l = lsuiv(l);
            }
            cg = cgModifierSommet(cg, s1, NOIR);
        }

        cg = cgLiberer(cg);

        return FAUX;
    }

}
