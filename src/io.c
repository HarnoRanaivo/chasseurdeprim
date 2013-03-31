/**
 * \file io.h
 * \brief Entrées/Sorties (code source)
 * \author Meyer Jérémy
 */
 
#include "io.h"

void sauvegarder_graphe (Graphe g, char* destination){
	FILE * pfile = NULL;
	pfile = fopen(destination, "w"); // crée le fichier destination s'il n'existe pas sinon le réécrit
	assert (pfile != NULL);
	
	Nat i, j;
	char buffer[100]; // limite la chaine de caractères à 100 (donc 96 caractères possibles pour les deux sommets)
	for (i=0 ; i< (gNombreSommets(g)) ; i++){ // boucle pour chaque sommet de g
		for (j=0 ; j< (ltaille(g->listeadjacence)) ; j++){ // boucle pour chaque arête dans la liste d'arêtes de g
			sprintf(buffer,"%s\t%d\t%s\n",g->sommet,g->listeadjacence->poids,g->listeadjacence->v);		
			fputs(buffer, pfile);
			g->listeadjacence = lsuiv(g->listeadjacence); // on regarde l'arête suivante
		}
		g = gSuivant(g); // on regarde le sommet suivant
	}
	
	fclose (pfile); // ferme le fichier
	return;
}

Graphe charger_graphe (char* source){
	FILE * pfile = NULL;
	pfile = fopen(source, "r"); // lit le fichier source
	assert (pfile != NULL);
	Graphe g = gNouv();
	
	char line [205]; // ligne de caractères
	char buffer1[100]; // sommet de départ de 100 caractères maximum
	Ent poids;
	char buffer2[100]; // sommet d'arrivée de 100 caractères maximum
	
	while (fscanf(source,"%s",&buffer1) != EOF){ // vérifie si la ligne n'est pas la fin du fichier
		fscanf(source,"%d",&poids);
		fscanf(source,"%s",&buffer2);
		g = gAjouterSommet(g,buffer1); // ajoute le sommet de début de ligne
		g = gAjouterArete(g,buffer1,buffer2,poids); // ajoute l'arc à partir des valeurs de la ligne
	}
	printf("Fin de lecture.\n\n");
	
	fclose (pfile);
	return g;
}
