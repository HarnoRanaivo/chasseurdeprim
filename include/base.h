/**
 * \file base.h
 * \brief Base (header)
 * \author Harenome RAZANAJATO
 * \version 1.3
 */

#ifndef __BASE_H
#define __BASE_H

#include <stdlib.h>
#include <stdio.h>

/**
 * \enum Bool
 * \brief Simulation des booléens.
 */
enum Bool
{
    FAUX,   /**<- Faux. */
    VRAI    /**<- Vrai. */
};

/**
 * \brief Simulation des booléens.
 */
typedef enum Bool Bool;

/**
 * \brief Entiers naturels.
 */
typedef unsigned int Nat;

/**
 * \brief Entiers relatifs.
 */
typedef int Ent;

/**
 * \brief Nombres réels.
 */
typedef float Reel;

/**
 * \brief Nombres rationnels.
 */
typedef float Rat;

/**
 * \brief Caractères.
 */
typedef char Car;

/* Simplement pour différencier un Caractère d'une Chaîne.
 * Pas de pointeur dans le typedef : pouvoir utiliser le mot-clé const correctement.
 */
/**
 * \brief Chaîne de caractères
 */
typedef Car Chaine;

/**
 * \brief Opérations de base pour un type donné.
 * \param T Type.
 */
#define OP(T) \
static inline Bool T ## _eq(T a, T b) { return a == b ? VRAI : FAUX; } \
static inline Bool T ## _neq(T a, T b) { return !T ## _eq(a, b); } \
static inline Bool T ## _inf(T a, T b) { return a < b ? VRAI : FAUX; } \
static inline Bool T ## _supT(T a, T b) { return !T ## _inf(a, b); } \
static inline Bool T ## _infeq(T a, T b) { return a <= b ? VRAI : FAUX; } \
static inline Bool T ## _supeq(T a, T b) { return a >= b ? VRAI : FAUX; } \
static inline T T ## _min(T a, T b) { return a <= b ? a : b; } \
static inline T T ## _max(T a, T b) { return a >= b ? a : b; }

OP(int)
OP(float)
OP(Nat)
OP(Ent)
OP(Reel)
OP(Rat)

#undef OP

/**
 * \brief Allouer de la mémoire.
 * \param P Pointeur.
 */
#define MALLOC(P) malloc(sizeof *(P))

/**
 * \brief Allouer un tableau de taille N.
 * \param P Pointeur.
 * \param N Taille du tableau.
 */
#define MALLOCN(P, N) malloc((N) * sizeof *(P))

/**
 * \brief Allouer un tableau de taille N et l'initialiser à 0.
 * \param P Pointeur.
 * \param N Taille du tableau.
 */
#define CALLOC(P, N) calloc((N), sizeof *(P))

/**
 * \brief Réallouer un tableau.
 * \param P Pointeur.
 * \param N Nouvelle taille du tableau.
 */
#define REALLOC(P, N) realloc((P), (N) * sizeof *(P))

#endif /* __BASE_H */
