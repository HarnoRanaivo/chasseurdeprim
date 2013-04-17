/**
 * \file generation.h
 * \brief Generation d'un fichier latex (header)
 * \author Harenome RAZANAJATO
 */
#ifndef __GENERATION_H
#define __GENERATION_H

#include <stdio.h>
#include <stdlib.h>

#include "base.h"
#include "graphe.h"
#include "listearete.h"
#include "arete.h"

/**
 * \brief Générer un fichier latex représentant le Graphe \a g à l'aide de TikZ.
 * \relatesalso Graphe
 * \param g Graphe à représenter.
 * \param destination Chemin vers le fichier de destination.
 * \return \a 0 en cas de succès, une valeur négative en cas d'erreur.
 * 
 * Erreurs :
 * - \a -1 : Le fichier de destination n'a pas pu être ouvert.
 * - \a -2 : Il y a eu une erreur lors de l'écriture.
 */
int gGenererLatex(const Graphe * g, const char * destination);

#endif /* __GENERATION_H */
