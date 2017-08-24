//
//  taylor.h
//  INF1608
//
//  Created by Lucas Ferraço on 23/08/17.
//  Copyright © 2017 Lucas Ferraço. All rights reserved.
//

#ifndef taylor_h
#define taylor_h

#include <stdio.h>

// Aproxima a funcao f(x) = cos(x) usando o polinomio de
// Taylor de grau 4 com centro em x0 = PI/2.
double fcos (double x);

// Calcula o valor absoluto do residuo maximo da avaliacao
// do polinomio em x, no intervalo [0, PI]
double fcos_erro (double x);

// Aproxima a funcao f(x) = x^(-1/2)
// usando o polinomio de Taylor de grau 3 com centro em x0 = 1
double fsqrt (double x);

// Calcula o valor absoluto do residuo maximo
// da avaliacao do polinomio em x, no intervalo [1, 2]
double fsqrt_erro (double x);

#endif /* taylor_h */
