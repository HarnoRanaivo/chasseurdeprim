/* This program is free software. It comes WITHOUT ANY WARRANTY, to
* the extent permitted by applicable law. You can redistribute it
* and/or modify it under the terms of the Do What The Fuck You Want
* To Public License, Version 2, as published by Sam Hocevar. See
* http://wtfpl.net for more details. */
/**
 * \file io.c
 * \brief Entrées/Sorties (code source)
 * \author Meyer Jérémy
 */
 
#include "io.h"

void sauvegarder_graphe (const Graphe * g, const char* destination){
	FILE * pfile = NULL;
	pfile = fopen(destination, "w"); // crée le fichier destination s'il n'existe pas sinon le réécrit

	if (pfile != NULL)
    {
        for (const ListeArete * l = gAretes(g); !larEstVide(l); l = larSuivante(l))
        {
            const Arete * const a = larAreteTete(l);
            fprintf(pfile, "%s\t%d\t%s\n", aA(a), aPoids(a), aB(a));
        }

        fclose (pfile); // ferme le fichier
    }

	return;
}

Graphe * charger_graphe (const char* source){
	FILE * pfile = NULL;
	pfile = fopen(source, "r"); // lit le fichier source

	Graphe * g = gNouv();
	
    if (pfile != NULL)
    {
        int retourFs;
        char buffer1[100]; // sommet de départ de 100 caractères maximum
        Ent poids;
        char buffer2[100]; // sommet d'arrivée de 100 caractères maximum
        Bool erreurs = FAUX;
        
        while ((retourFs = fscanf(pfile,"%99s\t%d\t%99s",buffer1,&poids,buffer2)) != EOF){ // vérifie si la ligne n'est pas la fin du fichier
            if (retourFs == 3)
                g = gAjouterArete(g,buffer1,buffer2,poids); // ajoute l'arc à partir des valeurs de la ligne
            else // cas où la lecture a raté
                erreurs = VRAI;
        }

        if (erreurs)
            fprintf(stderr, "Le fichier semble contenir des erreurs.\n");
        
        fclose (pfile);
    }

	return g;
}
