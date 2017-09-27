//
//  mmq.h
//  INF1608
//
//  Created by Lucas Ferraço on 27/09/17.
//  Copyright © 2017 Lucas Ferraço. All rights reserved.
//

#ifndef mmq_h
#define mmq_h

#include <stdio.h>
#include "matriz.h"
#include "sistlinear.h"

// Resolve o sistema Am×n * n = bm pelo metodo dos minimos quadrados.
// A funcao retorna o vetor que representa a solucao aproximada.
double * mmq (int m, int n, Matriz A, double * b);


// Calcula a norma-2 do residuo:
double norma2 (int m, int n, Matriz A, double * b, double * x);


// Recebe um conjunto de dados (ti,ci) observado em um paciente e retorne os coeficientes a e b correspondentes.
// A funcao recebe como parametros o numero de dados observados n, o vetor com os valores do tempo t e
// o vetor com os valores da concentracao c. Alem disso, a funcao recebe dois ponteiros para armazenar
// os valores dos coeficientes calculados pa e pb. A funcao retorna a norma-2 do residuo calculado.
double concentracao (int n, double * t, double * c, double * pa, double * pb);


#endif /* mmq_h */
