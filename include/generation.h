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

int gGenererLatex(const Graphe * g, const char * destination);

#endif /* __GENERATION_H */
