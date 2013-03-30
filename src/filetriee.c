/**
 * \file filetriee.c
 * \brief File triée d'arêtes (code)
 * \author Harenome RAZANAJATO
 */

#include "filetriee.h"

FileTriee ftNouv(void)
{
    return NULL;
}

FileTriee ftAjouterArete(FileTriee f, const Sommet s, const Sommet t, Ent poids)
{
    FileTriee f0 = MALLOC(f0);
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
        FileTriee fs = f;
        while (!ftEstVide(ftSuivante(fs)) && aPoids(ftAreteTete(ftSuivante(fs))) < poids)
            fs = ftSuivante(f);
        f0->suivante = fs->suivante;
        fs->suivante = f0;
    }

    return f;
}

FileTriee ftSupprimerTete(FileTriee f)
{
    if (!ftEstVide(f))
    {
        FileTriee fs = ftSuivante(f);
        f->arete = aLiberer(ftAreteTete(f));
        free(f);
        f = fs;
    }

    return f;
}

static FileTriee ftPrecedente(FileTriee f, const Sommet a, const Sommet b)
{
    if (ftEstVide(f)) return NULL;
    else if (ftEstVide(ftSuivante(f))) return NULL;
    else if (aAreteEgaleS(ftAreteTete(ftSuivante(f)), a, b)) return f;
    else return ftPrecedente(ftSuivante(f), a, b);
}

FileTriee ftSupprimerArete(FileTriee f, const Sommet a, const Sommet b)
{
    if (!ftEstVide(f))
    {
        if (aAreteEgaleS(ftAreteTete(f), a, b))
            f = ftSupprimerTete(f);
        else
        {
            FileTriee fp = ftPrecedente(f, a, b);

            if (fp != NULL)
                fp->suivante = ftSupprimerTete(ftSuivante(fp));
        }
    }

    return f;
}

Bool ftEstVide(const FileTriee f)
{
    return f == NULL;
}

Bool ftExisteArete(const FileTriee f, const Sommet a, const Sommet b)
{
    if (ftEstVide(f)) return FAUX;
    else if (aAreteEgaleS(ftAreteTete(f), a, b)) return VRAI;
    else return ftExisteArete(ftSuivante(f), a, b);
}

static Nat ftNombreAretesAux(const FileTriee f, Nat n)
{
    if (ftEstVide(f)) return n;
    else return ftNombreAretesAux(ftSuivante(f), n+1);
}

Nat ftNombreAretes(const FileTriee f)
{
    return ftNombreAretesAux(f, 0);
}

Arete ftAreteTete(const FileTriee f)
{
    return f->arete;
}

FileTriee ftSuivante(const FileTriee f)
{
    if (!ftEstVide(f))
        return f->suivante;
    else
        return NULL;
}

FileTriee ftLiberer(FileTriee f)
{
    if (ftEstVide(f))
        return NULL;
    else
    {
        FileTriee fs = ftSuivante(f);
        f->arete = aLiberer(ftAreteTete(f));
        free(f);

        return ftLiberer(fs);
    }
}
