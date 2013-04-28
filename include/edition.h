/* This program is free software. It comes WITHOUT ANY WARRANTY, to
* the extent permitted by applicable law. You can redistribute it
* and/or modify it under the terms of the Do What The Fuck You Want
* To Public License, Version 2, as published by Sam Hocevar. See
* http://wtfpl.net for more details. */
/**
 * \file edition.h
 * \brief Prompt mode édition (header)
 * \author Harenome RAZANAJATO
 */
#ifndef __EDITION_H
#define __EDITION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "base.h"
#include "graphe.h"
#include "io.h"
#include "parcours.h"

typedef enum EditCommande
{
    ED_NOUV,
    ED_AJS,
    ED_AJAR,
    ED_MOD,
    ED_SUPS,
    ED_SUPAR,
    ED_LSV,
    ED_LSI,
    ED_LSS,
    ED_LSA,
    ED_AIDE,
    ED_QUIT,
    ED_INCONNU
} EditCommande;

void afficherAideEditCommande(EditCommande ec);

void afficherAideEdition(void);

EditCommande rechercherEditCommande(const char * ligne);

Graphe * traiterLigneEdition(const char * ligne, EditCommande ec, Graphe * g);

Graphe * modeEdition(Graphe * g);

#endif /* __EDITION_H */
