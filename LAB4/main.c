#include <stdio.h>
#include <math.h>
#include "sistlinear.h"

Matriz criaA();
Matriz criaB();
void teste();

int main(int argc, const char * argv[]) {
	double b1[3] = {3, 3, -6}, b2[6] = {2.5, 1.5, 1, 1, 1.5, 2.5};
	Matriz A, B;
	
	printf("Teste Matriz A:\n");
	A = criaA();
	teste(3, A, b1);
	
	printf("Teste Matriz B:\n");
	B = criaB();
	teste(6, B, b2);
	
	return 0;
}

Matriz criaA() {
	Matriz A = mat_cria(3, 3);
	A[0][0] = 1;
	A[0][1] = 2;
	A[0][2] = -1;
	
	A[1][0] = 2;
	A[1][1] = 1;
	A[1][2] = -2;
	
	A[2][0] = -3;
	A[2][1] = 1;
	A[2][2] = 1;
	
	return A;
}

Matriz criaB() {
	int i, j;
	Matriz B = mat_cria(6, 6);
	
	for (i = 0; i < 6; i++) {
		for (j = 0; j < 6; j++) {
			if (i == j) {
				B[i][j] = 3;
			}
			else if (i+j == 5) {
				B[i][j] = 0.5;
			}
			else {
				B[i][j] = 0;
			}
			
			if (j == i+1 || i == j+1) {
				B[i][j] = -1;
			}
		}
	}
	
	return B;
}

void teste(int n, Matriz M, double * b) {
	int i, * p;
	double * x;
	
	// Teste fatoracao
	printf("Matriz\n");
	mat_imprime(n, n, M, "%.3g");
	printf("\nFatoracao\np = { ");
	p = fatoracao(n, M);
	for (i = 0; i < n; i++)
		printf("%d ", p[i]);
	printf("}\n");
	
	// Teste substituicao
	printf("\nSubstituicao\nx = { ");
	x = substituicao(n, M, p, b);
	for (i = 0; i < n; i++)
		printf("%g ", x[i]);
	printf("}\n\n");
}
