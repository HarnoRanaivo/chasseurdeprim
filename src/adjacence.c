/* This program is free software. It comes WITHOUT ANY WARRANTY, to
* the extent permitted by applicable law. You can redistribute it
* and/or modify it under the terms of the Do What The Fuck You Want
* To Public License, Version 2, as published by Sam Hocevar. See
* http://wtfpl.net for more details. */
/**
 * \file adjacence.c
 * \brief Gestion des listes d'adjacence (code source)
 * \author Meyer Jérémy
 */

#include "adjacence.h"

ListeAdjacence * listnouv(){
	return (ListeAdjacence *)NULL;
}

ListeAdjacence * lajar (ListeAdjacence * l, const Sommet * s, Ent x){
    ListeAdjacence * l1 = NULL;
	l1 = (ListeAdjacence *)MALLOC(l1);
	l1->poids = x;
	l1->v = copieSommet(s);
	l1->s = l;
	
	return l1;
}

ListeAdjacence * lsupar (ListeAdjacence * l, const Sommet * s){
	if (!lest_vide(l)){
		ListeAdjacence * ln = l;
		ListeAdjacence * ls;
		
		if (egalSom(ln->v, s)){
			l = l->s;
			ln->v = libererSommet(ln->v);
			free(ln);
		}
		else{
			while (!lest_vide(ln->s) && !egalSom(ln->s->v, s)){
				ln = ln->s;
			}
		
			if (!lest_vide(ln->s) && egalSom(ln->s->v, s)){	
				ls = ln->s;	
				ln->s = ln->s->s;
				ls->v = libererSommet(ls->v);
				free(ls);
			}
		
		}
	}
	return l;
}

Bool lest_vide (const ListeAdjacence * l){ return l==NULL; }

Bool lexar (const ListeAdjacence * l, const Sommet * s){
	while (!lest_vide(l)){
		if (egalSom(l->v, s))
			return VRAI;
		else
			l = l->s;
	}
	return FAUX;
}

Ent lpoids(const ListeAdjacence * l, const Sommet * s){
	while (!egalSom(l->v, s))
		l = l->s;
	return l->poids;
}

Nat ltaille (const ListeAdjacence * l){
	Nat cmpt = 0;
	
	while (!lest_vide(l)){
		cmpt++;
		l = l->s;
	}
	
	return cmpt;
}

ListeAdjacence * lliberer(ListeAdjacence * l){
    ListeAdjacence * l0 = NULL;

    while (l != NULL){
        l0 = l->s;
        l->v = libererSommet(l->v);
        free(l);
        l = l0;
    }

    return l;
}

ListeAdjacence * lcopie(const ListeAdjacence * l){
    ListeAdjacence * copie = listnouv();

    while (l != NULL){
        copie = lajar(copie, l->v, l->poids);
        l = l->s;
    }

    return copie;

}

ListeAdjacence * lmod(ListeAdjacence * l, const Sommet * s, Ent x){
    ListeAdjacence * l0 = l;

    while (l0 != NULL && !egalSom(l0->v, s))
        l0 = l0->s;
    
    if (egalSom(l0->v, s))
        l0->poids = x;

    return l;
}

Bool lega(const ListeAdjacence * l, const ListeAdjacence * m){
    if (ltaille(l) != ltaille(m))
        return FAUX;
    else{
        while (m != NULL){
            if (!lexar(l, m->v) || lpoids(l, m->v) != m->poids)
                return FAUX;
            else
                m = m->s;
        }

        return VRAI;
    }
}

ListeAdjacence * lsuiv(const ListeAdjacence * l){
    if (!lest_vide(l))
        return l->s;
    else
        return NULL;
}

Sommet * lsommet_tete(const ListeAdjacence * l){
    return l->v;
}

Ent lpoids_tete(const ListeAdjacence * l){
    return l->poids;
}
