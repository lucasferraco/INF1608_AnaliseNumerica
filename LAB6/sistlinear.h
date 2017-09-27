#ifndef sistlinear_h
#define sistlinear_h

#include <stdio.h>
#include "matriz.h"

// Faz a fatoracao A = LU.
// As matrizes L e U devem ser armazenadas no espaco de memoria da matriz A,
// sobrescrevendo os valores dos elementos de A.
// A diagonal da matriz L (com valores iguais a 1) nao e armazenada.
// A funcao deve retornar o vetor de permutacao p alocado dinamicamente.
int * fatoracao (int n, double ** A);


// Recebe como entrada a matriz A fatorada (isto e, a matriz LU),
// o vetor de permutacao p e um vetor independente b,
// e retorne um vetor solucao x alocado dinamicamente.
// Lembre-se que a matriz fatorada deve operar
// sobre o vetor independente permutado, isto e, b[p[i]].
double * substituicao (int n, double ** A, int * p, double * b);


#endif /* sistlinear_h */
