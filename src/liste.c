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
	ListeArete l1 = (ListeArete)MALLOC(l1);
	l1->poids = x;
	l1->v = s;
	l1->s = l;
	
	return l1;
}

ListeArete lsupar (ListeArete l, Sommet s){
	if (!lest_vide(l)){
		ListeArete ln = l;
		ListeArete ls;
		
		if (ln->v == s){
			l = l->s;
			free(ln);
		}
		else{
			while (!lest_vide(ln->s) || ln->s->v != s){
				ln = ln->s;
			}
		
			if (ln->s->v == s){	
				ls = ln->s;	
				ln->s = ln->s->s;
				free(ls);
			}
		
		}
	}
	return l;
}

Bool lest_vide (ListeArete l){ return l==NULL; }

Bool lexar (ListeArete l, Sommet s){
	while (!lest_vide(l)){
		if (l->v)
			return VRAI;
		else
			l = l->s;
	}
	return FAUX;
}

Ent lpoids(ListeArete l, Sommet s){
	while (l->v != s)
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
