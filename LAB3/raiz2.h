#ifndef raiz2_h
#define raiz2_h

#include <stdio.h>

// Implementa o metodo da secante para determinacao de raizes de funcoes.
int secante (double x0, double x1, int p, double (*f) (double x), double* r);

// Calcula a raiz de uma funcao segundo o metodo IQI
int IQI (double x0, double x1, double x2, int p, double (*f) (double x), double* r);

#endif /* raiz2_h */
