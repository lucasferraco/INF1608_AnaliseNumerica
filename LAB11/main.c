#include <stdio.h>
#include <math.h>

#include "gradconj.h"

double ** MatrizM1 (int n);
double ** MatrizM2 (int n);

int main (void) {
	int n = 3, k, i;
	double ** M1, ** M2, b1[3], b2[3], x1[3], x2[3];
	double tol = pow(10, -6);

	printf("Teste do metodo dos Gradientes Conjugados");
	printf("\n----------------\n\n");

	M1 = MatrizM1(n);
	b1[0] = 0; b1[1] = 2; b1[2] = 3;
	x1[0] = 1.1; x1[1] = 1; x1[2] = 1;

	M2 = MatrizM2(n);
	b2[0] = 3; b2[1] = -3; b2[2] = 4;
	x2[0] = 2.1; x2[1] = -1; x2[2] = 1;

	printf("Matriz 1\n");
	mat_imprime(n, n, M1, "%.2f");
	k = GradienteConjugado(n, M1, b1, x1, tol);
	printf("\nSolucao com %d iteracoes\nx = ", k);
	for (i = 0; i < n; i++)
		printf("%f  ", x1[i]);
	
	printf("\n\n----------------\n");

	printf("\nMatriz 2\n");
	mat_imprime(n, n, M2, "%.2f");
	k = GradienteConjugado(n, M2, b2, x2, tol);
	printf("\nSolucao com %d iteracoes\nx = ", k);
	for (i = 0; i < n; i++)
		printf("%f  ", x2[i]);
	printf("\n\n");

	return 0;
}

double ** MatrizM1 (int n) {
	double ** m = mat_cria(n, n);

	m[0][0] = 1; m[0][1] = -1; m[0][2] = 0;
	m[1][0] = -1; m[1][1] = 2; m[1][2] = 1;
	m[2][0] = 0; m[2][1] = 1; m[2][2] = 2;

	return m;
}

double ** MatrizM2 (int n) {
	double ** m = mat_cria(n, n);

	m[0][0] = 1; m[0][1] = -1; m[0][2] = 0;
	m[1][0] = -1; m[1][1] = 2; m[1][2] = 1;
	m[2][0] = 0; m[2][1] = 1; m[2][2] = 5;

	return m;
}


