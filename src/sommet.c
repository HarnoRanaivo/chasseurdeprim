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
