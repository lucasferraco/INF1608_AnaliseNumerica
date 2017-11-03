//
//  matriz.h
//  inf1608_lab0
//
//  Created by Lucas Ferraço on 16/08/17.
//  Copyright © 2017 Lucas Ferraço. All rights reserved.
//

#ifndef matriz_h
#define matriz_h

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Cria dinamicamente uma matriz de dimensao m × n,
// onde m representa o numero de linhas e n representa o numero de colunas.
double** mat_cria (int m, int n);


// Libera a memoria de uma matriz previamente criada.
// A funcao recebe o numero de linhas m da matriz.
void mat_libera (int m, double** A);


// Preenche a transposta de uma dada matriz.
// A funcao recebe as dimensoes m × n da matriz original,
// a matriz original A e a matriz transposta a ser preenchida T (com dimensão n × m).
void mat_transposta (int m, int n, double** A, double** T);


// Recebe uma matriz e um vetor, e preencha um outro vetor com o resultado da multiplicacao da matriz pelo vetor.
// A funcao recebe a dimensao m × n da matriz e assume que o primeiro vetor v tem dimensao n e o vetor resultado w tem dimensao m.
void mat_multv (int m, int n, double** A, double* v, double* w);


// Calcule a multiplicacao entre duas matrizes: C = AB.
// A funcao recebe as dimensoes m, n e q, e as matrizes Am×n, Bn×q e Cm×q, preenchendo C.
void mat_multm (int m, int n, int q, double** A, double** B, double** C);


// Testa se duas matrizes A e B sao iguais, elemento a elemento, dentro de uma dada tolerancia,
// isto e, o valor absoluto das diferencas entre os elementos deve ser menor ou igual a tolerancia.
int mat_iguais (int m, int n, double** A, double** B, double tol);


// Exibe os elementos de uma matriz na tela.
// Cada elemento deve ser exibido com o formato especificado via parametro;
// elementos da mesma linha devem ser separados por um espaco ’ ’ em branco,
// e linhas da matriz devem ser separadas por um caractere de mudanca de linha ’\n’.
void mat_imprime (int m, int n, double** A, char* format);


#endif /* matriz_h */
