#ifndef integral_h
#define integral_h

#include <stdio.h>

// Retorna o valor da derivada numerica de segunda ordem da funcao f no ponto x.
double derivada (double (*f) (double x), double h, double x);

// Regra de Simpson
// Calcula a integral composta do intervalo de a a b considerando n passos de integracao,
// isto e, considerando h = (b − a)/n.
double simpson (double (*f) (double), double a, double b, int n);

// Regra do ponto medio
// Calcula a integral composta de a a b com n passos de integracao, isto e, considerando h = (b − a)/n.
double pontomedio (double (*f) (double), double a, double b, int n);

#endif /* integral_h */
