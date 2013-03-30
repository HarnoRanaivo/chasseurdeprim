/**
 * \file filetriee.h
 * \brief File triée d'arêtes (header)
 * \author Harenome RAZANAJATO
 */
#ifndef __FILETRIEE_H
#define __FILETRIEE_H

#include <stdlib.h>
#include <stdio.h>

#include "base.h"
#include "sommet.h"
#include "arete.h"

typedef struct filetriee
{
    Arete arete;
    struct filetriee * suivante;
} StrFileTriee, *FileTriee;

FileTriee ftNouv(void);

FileTriee ftAjouterArete(FileTriee f, const Sommet s, const Sommet t, Ent poids);

FileTriee ftSupprimerTete(FileTriee f);

FileTriee ftSupprimerArete(FileTriee f, const Sommet a, const Sommet b);

Bool ftEstVide(const FileTriee f);

Bool ftExisteArete(const FileTriee f, const Sommet a, const Sommet b);

Nat ftNombreAretes(const FileTriee f);

Arete ftAreteTete(const FileTriee f);

FileTriee ftSuivante(const FileTriee f);

FileTriee ftLiberer(FileTriee f);

#endif /* __FILETRIEE_H */
