/**
 * \file liste.h
 * \brief Gestion de la sorte Liste (code source)
 * \author Meyer Jérémy
 */

#include "liste.h"

ListeArete listnouv(){
	return (ListeArete)NULL;
}

ListeArete lajar (ListeArete l, Sommet s, Ent x){
    ListeArete l1 = NULL;
	l1 = (ListeArete)MALLOC(l1);
	l1->poids = x;
	l1->v = copieSommet(s);
	l1->s = l;
	
	return l1;
}

ListeArete lsupar (ListeArete l, Sommet s){
	if (!lest_vide(l)){
		ListeArete ln = l;
		ListeArete ls;
		
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

Bool lest_vide (ListeArete l){ return l==NULL; }

Bool lexar (ListeArete l, Sommet s){
	while (!lest_vide(l)){
		if (egalSom(l->v, s))
			return VRAI;
		else
			l = l->s;
	}
	return FAUX;
}

Ent lpoids(ListeArete l, Sommet s){
	while (!egalSom(l->v, s))
		l = l->s;
	return l->poids;
}

Nat ltaille (ListeArete l){
	Nat cmpt = 0;
	
	while (!lest_vide(l)){
		cmpt++;
		l = l->s;
	}
	
	return cmpt;
}
