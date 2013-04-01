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
	
	Nat tailleg = gNombreSommets(g);
	for (i=0 ; i< tailleg ; i++){ // boucle pour chaque sommet de g
	    ListeArete l = gAdjacenceTete(g);
	    Nat taille = ltaille(l);
		for (j=0 ; j< taillel; j++){ // boucle pour chaque arête dans la liste d'arêtes de g
			fprintf(pfile,"%s\t%d\t%s\n",gSommetTete(g),lpoids_tete(l),lsommet_tete(l));		
			l = lsuiv(l); // on regarde l'arête suivante
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
	
	char buffer1[100]; // sommet de départ de 100 caractères maximum
	Ent poids;
	char buffer2[100]; // sommet d'arrivée de 100 caractères maximum
	
	while (fscanf(pfile,"%s",buffer1) != EOF){ // vérifie si la ligne n'est pas la fin du fichier
		fscanf(pfile,"%d",&poids);
		fscanf(pfile,"%s",buffer2);
		g = gAjouterArete(g,buffer1,buffer2,poids); // ajoute l'arc à partir des valeurs de la ligne
	}
	printf("Fin de lecture.\n\n");
	
	fclose (pfile);
	return g;
}
