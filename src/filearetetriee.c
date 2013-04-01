/**
 * \file filearetetriee.c
 * \brief File triée d'arêtes (code)
 * \author Harenome RAZANAJATO
 */

#include "filearetetriee.h"

FileAreteTriee * ftNouv(void)
{
    return NULL;
}

FileAreteTriee * ftAjouterArete(FileAreteTriee * f, const Sommet * s, const Sommet * t, Ent poids)
{
    if (!larExisteArete(f, s, t))
    {
        if (larEstVide(f) || aPoids(larAreteTete(f)) >= poids)
        {
            f = larAjouterAreteTete(f, s, t, poids);
        }
        else
        {
            FileAreteTriee * fs = f;

            while (!larEstVide(larSuivante(fs)) && aPoids(larAreteTete(larSuivante(fs))) < poids)
                fs = larSuivante(fs);
            fs->suivante = larAjouterAreteTete(larSuivante(fs), s, t, poids);
        }
    }

    return f;
}
