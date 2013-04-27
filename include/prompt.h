/* This program is free software. It comes WITHOUT ANY WARRANTY, to
* the extent permitted by applicable law. You can redistribute it
* and/or modify it under the terms of the Do What The Fuck You Want
* To Public License, Version 2, as published by Sam Hocevar. See
* http://wtfpl.net for more details. */
/**
 * \file prompt.h
 * \brief Prompt (header)
 * \author Harenome RAZANAJATO
 */
#ifndef __PROMPT_H
#define __PROMPT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sysexits.h>

#include "base.h"
#include "graphe.h"
#include "grapheconnexe.h"
#include "io.h"
#include "prim.h"
#include "generation.h"

typedef enum
{
    MC_INCONNU,
    MC_CHG,
    MC_SAV,
    MC_MOD,
    MC_AJAR,
    MC_SUPAR,
    MC_SUPSOM,
    MC_CAL,
    MC_AFF,
    MC_AIDE,
    MC_QUIT
} MenuCommande;

typedef struct
{
    Graphe * graphe;
    Graphe * arbre;
    Bool sauvegarde;
} Donnees;

void prompt(void);

#endif /* __PROMPT_H */
