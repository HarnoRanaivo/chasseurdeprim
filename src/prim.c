/**
 * \file prim.c
 * \brief Algorithme de Prim (code)
 * \author Harenome RAZANAJATO
 */

#include "prim.h"

FileAreteTriee * ftAjouterAretesIncidentes(FileAreteTriee * ft, const Graphe * g, const CouleursGraphe * cg, const Sommet * s)
{
    ListeAdjacence * adjacence = gAdjacenceSommet(g, s);

    while (!lest_vide(adjacence))
    {
        Sommet * t = lsommet_tete(adjacence);
        if (cgCouleurSommet(cg, t) == BLANC)
            ft = ftAjouterArete(ft, s, t, lpoids_tete(adjacence));
        adjacence = lsuiv(adjacence);
    }

    return ft;
}

Graphe * gArbreCouvrantMinimum(const Graphe * g, const Sommet * s)
{
    Nat aretes = 0;
    Nat n = gNombreSommets(g);
    CouleursGraphe * cg = cgModifierSommet(cgInit(g), s, NOIR);
    FileAreteTriee * ft = ftAjouterAretesIncidentes(ftNouv(), g, cg, s);

    Graphe * arbre = gAjouterSommet(gNouv(), s);

    while (aretes < n -1 && !ftEstVide(ft))
    {
        Arete * tete = ftAreteTete(ft);
        Sommet * a = aA(tete);
        Sommet * b = aB(tete);

        if (cgCouleurSommet(cg, a) == BLANC || cgCouleurSommet(cg, b) == BLANC)
        {
            aretes++;
            arbre = gAjouterArete(arbre, a, b, aPoids(tete));

            if (cgCouleurSommet(cg, a) == BLANC)
            {
                ft = ftAjouterAretesIncidentes(ft, g, cg, a);
                cg = cgModifierSommet(cg, a, NOIR);
            }
            else
            {
                ft = ftAjouterAretesIncidentes(ft, g, cg, b);
                cg = cgModifierSommet(cg, b, NOIR);
            }
        }
        ft = ftSupprimerArete(ft, a, b);
    }
    
    cg = cgLiberer(cg);
    ft = ftLiberer(ft);

    return arbre;
}

