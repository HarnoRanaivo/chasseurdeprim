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
    if (!ftExisteArete(f, s, t))
    {
        FileAreteTriee * f0 = MALLOC(f0);
        f0->arete = aNouv(s, t, poids);

        if (ftEstVide(f))
        {
            f0->suivante = NULL;
            f = f0;
        }
        else if (aPoids(ftAreteTete(f)) >= poids)
        {
            f0->suivante = f;
            f = f0;
        }
        else
        {
            FileAreteTriee * fs = f;
            while (!ftEstVide(ftSuivante(fs)) && aPoids(ftAreteTete(ftSuivante(fs))) < poids)
                fs = ftSuivante(fs);
            f0->suivante = fs->suivante;
            fs->suivante = f0;
        }
    }

    return f;
}

FileAreteTriee * ftSupprimerTete(FileAreteTriee * f)
{
    if (!ftEstVide(f))
    {
        FileAreteTriee * fs = ftSuivante(f);
        f->arete = aLiberer(ftAreteTete(f));
        free(f);
        f = fs;
    }

    return f;
}

static FileAreteTriee * ftPrecedente(FileAreteTriee * f, const Sommet * a, const Sommet * b)
{
    if (ftEstVide(f)) return NULL;
    else if (ftEstVide(ftSuivante(f))) return NULL;
    else if (aAreteEgaleS(ftAreteTete(ftSuivante(f)), a, b)) return f;
    else return ftPrecedente(ftSuivante(f), a, b);
}

FileAreteTriee * ftSupprimerArete(FileAreteTriee * f, const Sommet * a, const Sommet * b)
{
    if (!ftEstVide(f))
    {
        if (aAreteEgaleS(ftAreteTete(f), a, b))
            f = ftSupprimerTete(f);
        else
        {
            FileAreteTriee * fp = ftPrecedente(f, a, b);

            if (fp != NULL)
                fp->suivante = ftSupprimerTete(ftSuivante(fp));
        }
    }

    return f;
}

Bool ftEstVide(const FileAreteTriee * f)
{
    return f == NULL;
}

Bool ftExisteArete(const FileAreteTriee * f, const Sommet * a, const Sommet * b)
{
    if (ftEstVide(f)) return FAUX;
    else if (aAreteEgaleS(ftAreteTete(f), a, b)) return VRAI;
    else return ftExisteArete(ftSuivante(f), a, b);
}

static Nat ftNombreAretesAux(const FileAreteTriee * f, Nat n)
{
    if (ftEstVide(f)) return n;
    else return ftNombreAretesAux(ftSuivante(f), n+1);
}

Nat ftNombreAretes(const FileAreteTriee * f)
{
    return ftNombreAretesAux(f, 0);
}

Arete * ftAreteTete(const FileAreteTriee * f)
{
    return f->arete;
}

FileAreteTriee * ftSuivante(const FileAreteTriee * f)
{
    if (!ftEstVide(f))
        return f->suivante;
    else
        return NULL;
}

FileAreteTriee * ftLiberer(FileAreteTriee * f)
{
    if (ftEstVide(f))
        return NULL;
    else
    {
        FileAreteTriee * fs = ftSuivante(f);
        f->arete = aLiberer(ftAreteTete(f));
        free(f);

        return ftLiberer(fs);
    }
}
