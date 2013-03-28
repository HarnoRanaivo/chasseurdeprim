/**
 * \file base.h
 * \brief Base (header)
 * \author Harenome RAZANAJATO
 * \version 1.2
 */

#ifndef __BASE_H
#define __BASE_H

#include <stdlib.h>
#include <stdio.h>

/**
 * \enum Bool
 * \brief Simulation des booléens.
 */
typedef enum
{
    FAUX,   /** Faux. */
    VRAI    /** Vrai. */
} Bool;

/*
 * Types de base.
 */
typedef unsigned int Nat;
typedef int Ent;
typedef float Reel;
typedef float Rat;
typedef char Car;
typedef Car * Chaine;

/**
 * \def OP(T)
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

#define MALLOC(P) malloc(sizeof *(P))
#define MALLOCN(P, N) malloc((N) * sizeof *(P))
//static inline void* MALLOC (void * p) { return malloc(sizeof(*p)) ; }
//static inline void* MALLOCN (void * p, Nat n) { return malloc(n*sizeof(*p)) ; }

#endif /* __BASE_H */
