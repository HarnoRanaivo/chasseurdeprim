/**
 * \file liste.h
 * \brief Gestion de la sorte Liste (code source)
 * \author Meyer Jérémy
 */

#include "liste.h"

ListeArete listnouv(){
	return (ListeArete)NULL;
}

ListeArete lajar (ListeArete l, const Sommet s, Ent x){
    ListeArete l1 = NULL;
	l1 = (ListeArete)MALLOC(l1);
	l1->poids = x;
	l1->v = copieSommet(s);
	l1->s = l;
	
	return l1;
}

ListeArete lsupar (ListeArete l, const Sommet s){
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

Bool lexar (ListeArete l, const Sommet s){
	while (!lest_vide(l)){
		if (egalSom(l->v, s))
			return VRAI;
		else
			l = l->s;
	}
	return FAUX;
}

Ent lpoids(ListeArete l, const Sommet s){
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

ListeArete lliberer(ListeArete l)
{
    ListeArete l0 = NULL;

    while (l != NULL)
    {
        l0 = l->s;
        l->v = libererSommet(l->v);
        free(l);
        l = l0;
    }

    return l;
}

ListeArete lcopie(const ListeArete l)
{
    ListeArete l0 = l;
    ListeArete copie = listnouv();

    while (l0 != NULL)
    {
        copie = lajar(copie, l0->v, l0->poids);
        l0 = l0->s;
    }

    return copie;

}

ListeArete lmod(ListeArete l, const Sommet s, Ent x)
{
    ListeArete l0 = l;

    while (l0 != NULL && !egalSom(l0->v, s))
        l0 = l0->s;
    
    if (egalSom(l0->v, s))
        l0->poids = x;

    return l;
}

Bool lega(ListeArete l, ListeArete m)
{
    if (ltaille(l) != ltaille(m))
        return FAUX;
    else
    {
        while (m != NULL)
        {
            if (!lexar(l, m->v) || lpoids(l, m->v) != m->poids)
                return FAUX;
            else
                m = m->s;
        }

        return VRAI;
    }
}
