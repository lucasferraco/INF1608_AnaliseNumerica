//
//  simpson.h
//  INF1608
//
//  Created by Lucas Ferraço on 13/10/17.
//  Copyright © 2017 Lucas Ferraço. All rights reserved.
//

#ifndef simpson_h
#define simpson_h

#include <stdio.h>

// Calcula o valor da integral adotando um passo e dois semi-
// -passos de integracao, usando a Regra de Simpson.
// Retorna o erro avaliado por  S[a,b] − S[a,c] − S[c,b]  dividido por 15,
// isto e, o valor de E[a,b]/16.
// Preenche o valor da integral S[a,c] + S[c,b] + E[a,b]/16 no endereco de memoria v passado.

double DoubleSimpson (double a, double b, double (*f) (double x), double * v);

// Funcao recursiva que implementa a Integracao por Simpson Adaptativa, usando a funcao DoubleSimpson.
// Recebe o intervalo de integracao, a funcao e a tolerancia de erro desejada,
// e retorna o valor total da derivada no intervalo dentro da tolerancia/

double AdaptiveSimpson (double a, double b, double (*f) (double x), double tol);

#endif /* simpson_h */
