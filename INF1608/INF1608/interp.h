//
//  interp.h
//  INF1608
//
//  Created by Lucas Ferraço on 20/09/17.
//  Copyright © 2017 Lucas Ferraço. All rights reserved.
//

#ifndef interp_h
#define interp_h

#include <stdio.h>

// Retorna as n amostras de Chebyshev para a aproximacao
// de uma funcao qualquer, dentro do intervalo [a, b].
double * Chebyshev (int n, double a, double b);

// Calcula os n coeficientes bi
// Receber as abscissas das amostras xi e a funcao que se deseja interpolar,
// e retorna o vetor dos coeficientes alocado dinamicamente.
double * NewtonCoef (int n, double * xi, double (*f) (double));

// Avalia o polinomio interpolante de Newton em um ponto x dado.
// A funcao recebe como parametros as amostras xi, os coeficientes bi
// e o valor x onde o polinomio deve ser avaliado.
double NewtonAval (int n, double * xi, double * bi, double x);

#endif /* interp_h */
