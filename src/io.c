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
        ListeArete * liste = gAretes(g);
        for (const ListeArete * l = liste; !larEstVide(l); l = larSuivante(l))
        {
            const Arete * const a = larAreteTete(l);
            fprintf(pfile, "%s\t%d\t%s\n", aA(a), aPoids(a), aB(a));
        }
        liste = larLiberer(liste);

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

static inline void afficherArete(const Arete * a)
{
    printf("(%s, %s, %d) ", aA(a), aB(a), aPoids(a));
}

static inline void afficherListeArete(const ListeArete * lar)
{
    for (const ListeArete * l = lar; !larEstVide(l); l = larSuivante(l))
        afficherArete(larAreteTete(l));
    printf("\n");
}

void afficherAretesGraphe(const Graphe * g)
{
    ListeArete * liste = gAretes(g);

    afficherListeArete(liste);

    liste = larLiberer(liste);
}

void afficherListeSommets(const Graphe * g)
{
    for (g = g; !gEstVide(g); g = gSuivant(g))
        printf("\"%s\" ", gSommetTete(g));
    printf("\n");
}

void afficherAdjacence(const Graphe * g, const Sommet * s)
{
    for (const ListeAdjacence * l = gAdjacenceSommet(g, s); !lest_vide(l); l = lsuiv(l))
        printf("(%s, %s, %d) ", s, lsommet_tete(l), lpoids_tete(l));
    printf("\n");
}

void afficherVoisins(const Graphe * g, const Sommet * s)
{
    for (const ListeAdjacence * l = gAdjacenceSommet(g, s); !lest_vide(l); l = lsuiv(l))
        printf("\"%s\" ", lsommet_tete(l));
    printf("\n");
}

Bool verifier(const char * chaine)
{
    char buffer[8] = { '\0' };

    printf("Êtes-vous sûr %s?\n? ", chaine);
    fflush(stdout);
    scanf("%7s%*[^\n]", buffer);
    getchar();

    chaineEnMinuscules(buffer);

    if (strcmp(buffer, "o") == 0 || strcmp(buffer, "oui") == 0)
        return VRAI;
    else
        return FAUX;
}

Bool existeFichier(const char * nomfichier)
{
    struct stat buffer;
    return (stat (nomfichier, &buffer) == 0);
}
