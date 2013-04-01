/**
 * \file io.h
 * \brief Entrées/Sorties (header)
 * \author Meyer Jérémy
 */
 
#ifndef __IO_H
#define __IO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "base.h"
#include "sommet.h"
#include "adjacence.h"
#include "graphe.h"

/**
 * \fn void sauvegarder_graphe (const Graphe * g, const char* destination)
 * \brief Permet de sauvegarder le graphe dans un fichier passé en argument
 * \param g (Graphe)
 * \param destination (fichier de sauvegarde)
 * \relatesalso Graphe
 * \return \b void
 */
void sauvegarder_graphe (const Graphe * g, const char* destination);

/**
 * \fn Graphe * charger_graphe (const char* source)
 * \brief Permet de charger un graphe dans un fichier texte
 * \param source (fichier de chargement)
 * \relatesalso Graphe
 * \return Graphe du fichier
 */
Graphe * charger_graphe (const char* source);


#endif /* __IO_H */
