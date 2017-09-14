#ifndef sistlinear_h
#define sistlinear_h

#include <stdio.h>

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


// Funcoes auxiliares para lidar com matrizes.
// (Retiradas do LAB0)
typedef double ** Matriz;

// Cria dinamicamente uma matriz de dimensao m × n,
// onde m representa o numero de linhas e n representa o numero de colunas.
Matriz mat_cria (int m, int n);


// Libera a memoria de uma matriz previamente criada.
// A funcao recebe o numero de linhas m da matriz.
void mat_libera (int m, Matriz A);


// Recebe uma matriz e um vetor, e preencha um outro vetor com o resultado da multiplicacao da matriz pelo vetor.
// A funcao recebe a dimensao m × n da matriz e assume que o primeiro vetor v tem dimensao n e o vetor resultado w tem dimensao m.
void mat_multv (int m, int n, Matriz A, double* v, double* w);


// Calcule a multiplicacao entre duas matrizes: C = AB.
// A funcao recebe as dimensoes m, n e q, e as matrizes Am×n, Bn×q e Cm×q, preenchendo C.
void mat_multm (int m, int n, int q, Matriz A, Matriz B, Matriz C);


// Exibe os elementos de uma matriz na tela.
// Cada elemento deve ser exibido com o formato especificado via parametro;
// elementos da mesma linha devem ser separados por um espaco ’ ’ em branco,
// e linhas da matriz devem ser separadas por um caractere de mudanca de linha ’\n’.
void mat_imprime (int m, int n, Matriz A, char* format);

#endif /* sistlinear_h */
