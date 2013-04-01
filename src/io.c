/**
 * \file io.c
 * \brief Entrées/Sorties (code source)
 * \author Meyer Jérémy
 */
 
#include "io.h"

void sauvegarder_graphe (const Graphe * g, const char* destination){
	FILE * pfile = NULL;
	pfile = fopen(destination, "w"); // crée le fichier destination s'il n'existe pas sinon le réécrit
	assert (pfile != NULL);
	
	Nat i, j;
	
	Nat tailleg = gNombreSommets(g);
	for (i=0 ; i< tailleg ; i++){ // boucle pour chaque sommet de g
	    ListeArete * l = gAretes(g);
	    Nat taillel = larNombreAretes(l);
		for (j=0 ; j< taillel; j++){ // boucle pour chaque arête dans la liste d'arêtes de g
			fprintf(pfile,"%s\t%d\t%s\n",gSommetTete(g),lpoids_tete(l),lsommet_tete(l));		
			l = lsuiv(l); // on regarde l'arête suivante
		}
		g = gSuivant(g); // on regarde le sommet suivant
	}
	
	fclose (pfile); // ferme le fichier
	return;
}

Graphe * charger_graphe (const char* source){
	FILE * pfile = NULL;
	pfile = fopen(source, "r"); // lit le fichier source
	assert (pfile != NULL);
	Graphe * g = gNouv();
	
	int retourFs;
	char buffer1[100]; // sommet de départ de 100 caractères maximum
	Ent poids;
	char buffer2[100]; // sommet d'arrivée de 100 caractères maximum
	
	while ((retourFs = fscanf(pfile,"%99s\t%d\t%99s",buffer1,&poids,buffer2)) != EOF){ // vérifie si la ligne n'est pas la fin du fichier
		if (retourFs == 3)
			g = gAjouterArete(g,buffer1,buffer2,poids); // ajoute l'arc à partir des valeurs de la ligne
		else // cas où la lecture a raté
			fprintf(stderr,"Le fichier a mal été écrit, veuillez s'il vous plait respecter le code d'écriture qui :\nSommet d'entrée \\t Poids \\t Sommet d'arrivée\\n\n");
			// à méditer si l'on quitte le prog ou pas
	}
	printf("Fin de lecture.\n\n");
	
	fclose (pfile);
	return g;
}
