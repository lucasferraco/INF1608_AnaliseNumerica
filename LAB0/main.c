//
//  main.c
//  inf1608_lab0
//
//  Created by Lucas Ferraço on 16/08/17.
//  Copyright © 2017 Lucas Ferraço. All rights reserved.
//

#include <stdio.h>
#include "matriz.h"

int main(int argc, const char * argv[]) {
	int i, j, m = 2, n = 3, q = 4;
	double v[n], resultado[m];
	double **A, **T, **B, **C, **D, **E;
	
	
	// Teste mat_cria e mat_imprime
	printf("Teste mat_cria e mat_imprime\n");
	A = mat_cria(m, n);
	
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			A[i][j] = i + j;
	
	printf("Matriz A:\n");
	mat_imprime(m, n, A, "%.16g");
	printf("\n");
	
	
	// Teste mat_transposta
	printf("Teste mat_transposta (At)\n");
	T = mat_cria(n, m);
	
	printf("Matriz At:\n");
	mat_transposta(m, n, A, T);
	mat_imprime(n, m, T, "%.16g");
	printf("\n");
	
	// Teste mat_multv
	for (i = 0; i < n; i++)
		for (j = 0; j < q; j++)
			v[j] = j*2;
	
	printf("Teste mat_multv (A*v)\n");
	printf("Vetor v:\n");
	for (i = 0; i < n; i++)	printf("%.16g ", v[i]);
	printf("\n");
	mat_multv(2, 3, A, v, resultado);
	printf("Vetor resultado:\n");
	for (i = 0; i < m; i++)	printf("%.16g ", resultado[i]);
	printf("\n\n");
	
	
	// Teste mat_multm
	printf("Teste mat_multm (A*B)\n");
	B = mat_cria(n, q);
	C = mat_cria(m, q);
	
	for (i = 0; i < n; i++)
		for (j = 0; j < q; j++)
			B[i][j] = i + j;
	
	printf("Matriz B:\n");
	mat_imprime(n, q, B, "%.16g");
	mat_multm(m, n, q, A, B, C);
	printf("Matriz C (A*B):\n");
	mat_imprime(m, q, C, "%.16g");
	printf("\n");
	
	
	// Teste mat_iguais
	D = mat_cria(m, n);
	
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			D[i][j] = i + j + 1;
	
	printf("Teste mat_iguais\n");
	printf("Matriz B:\n");
	mat_imprime(m, n, D, "%.16g");
	
	
	// A e D sao iguais
	if (mat_iguais(m, n, A, D, 1)) printf("A e D sao iguais\n");
	else printf(" A e D sao diferentes\n");
	
	E = mat_cria(m, n);
	
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			E[i][j] = D[i][j] + 1;
	
	printf("Matriz E:\n");
	mat_imprime(m, n, E, "%.16g");
	
	// A e E nao sao iguais
	if (mat_iguais(m, n, A, E, 1)) printf("A e E sao iguais\n");
	else printf("A e E sao diferentes\n");
	printf("\n");
	
	// Teste mat_libera
	printf("Teste mat_libera\n");
	printf("A[0]: %p\n", A[0]);
	mat_libera(m, A);
	printf("A[0] mat_libera(m, A): %p\n", A[0]);
	printf("\n");
	
	mat_libera(n, B);
	mat_libera(m, C);
	mat_libera(m, D);
	mat_libera(m, E);
	mat_libera(n, T);
	
	return 0;
}
