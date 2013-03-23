/**
 * \file sommet.c
 * \brief Gestion de la sorte Sommet (code source)
 * \author Meyer Jérémy
 */

#include "sommet.h"

Bool egalSom (Sommet a, Sommet b){
	if (strcmp(a,b) == 0)
		return VRAI;
	else
		return FAUX;
}

Sommet copieSommet(Sommet s)
{
    Sommet copie = NULL;

    copie = MALLOCN(copie, strlen(s) + 1);
    if (copie != NULL)
        copie = strcpy(copie, s);

    return copie;
}
