/* This program is free software. It comes WITHOUT ANY WARRANTY, to
* the extent permitted by applicable law. You can redistribute it
* and/or modify it under the terms of the Do What The Fuck You Want
* To Public License, Version 2, as published by Sam Hocevar. See
* http://wtfpl.net for more details. */
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
 * \brief Générer un fichier latex représentant les Graphe \a g et \a a à l'aide de Latex et TikZ.
 * \relatesalso Graphe
 * \param g Graphe à représenter.
 * \param a Second Graphe à représenter;
 * \param destination Chemin vers le fichier de destination.
 * \return \a 0 en cas de succès, une valeur négative en cas d'erreur.
 *
 * \a g doit être renseigné, \a a est optionnel (utiliser NULL).
 *
 * Erreurs :
 * - \a -1 : Le fichier de destination n'a pas pu être ouvert.
 * - \a -2 : Il y a eu une erreur lors de l'écriture.
 */
int gGenererLatex(const Graphe * g, const Graphe * a, const char * destination);

#endif /* __GENERATION_H */
