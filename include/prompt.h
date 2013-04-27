/* This program is free software. It comes WITHOUT ANY WARRANTY, to
* the extent permitted by applicable law. You can redistribute it
* and/or modify it under the terms of the Do What The Fuck You Want
* To Public License, Version 2, as published by Sam Hocevar. See
* http://wtfpl.net for more details. */
/**
 * \file menu.h
 * \brief Menu (header)
 * \author Harenome RAZANAJATO
 */
#ifndef __MENU_H
#define __MENU_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "base.h"
#include "graphe.h"

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
    MC_QUIT
} MenuCommande;

void prompt(void);

#endif /* __MENU_H */
