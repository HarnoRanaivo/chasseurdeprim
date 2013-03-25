/**
 * \file sommet.c
 * \brief Gestion de la sorte Sommet (code source)
 * \author Meyer Jérémy
 */

#include "sommet.h"

Bool egalSom (const Sommet a, const Sommet b){
    if (a == NULL && b == NULL)
        return VRAI;
    else if (a == NULL || b == NULL)
        return FAUX;
    else if (strcmp(a,b) == 0)
		return VRAI;
	else
		return FAUX;
}

Sommet copieSommet(const Sommet s)
{
    Sommet copie = NULL;

    copie = MALLOCN(copie, strlen(s) + 1);
    if (copie != NULL)
        copie = strcpy(copie, s);

    return copie;
}

Sommet libererSommet(Sommet s)
{
    free(s);
    return NULL;
}

Sommet modSommet(Sommet s, const Sommet t)
{
    Sommet nouveau = NULL;

    nouveau = copieSommet(t);
    if (nouveau != NULL)
    {
        libererSommet(s);
        nouveau = copieSommet(t);
    }

    return nouveau;
}
