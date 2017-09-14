#include "sistlinear.h"
#include <math.h>
#include <stdlib.h>


int * pivot (int n, Matriz A) {
	int i, j, max, * p;
	double * aux;
	
	p = malloc(sizeof(int *) * n);
	for (i = 0; i < n; i++)
		p[i] = i;
	
	for (i = 0; i < n; i++)  {
		max = i;
		for (j = i+1; j < n; j++)
			if (fabs(A[j][i]) > fabs(A[max][i]))
				max = j;
		
		if (max != i) {
			aux = A[i];
			A[i] = A[max];
			A[max] = aux;
			
			j = p[i];
			p[i] = p[max];
			p[max] = j;
		}
	}
	
	return p;
}

int * fatoracao (int n, Matriz A) {
	int i, j, k, * p;
	double s;
	
	p = pivot(n, A);
	
	for (j = 0; j < n-1; j++) {
		for (i = j+1; i < n; i++) {
			s = A[i][j] / A[j][j];
			
			for (k = j+1; k < n; k++)
				A[i][k] -= s * A[j][k];
			
			A[i][j] = s;
		}
	}
	
	return p;
}

double * substituicao (int n, Matriz A, int * p, double * b) {
	int i, j;
	double * Pb, * y, * x, soma;
	
	// Achar y, top-down
	// Ly = Pb
	Pb = malloc(sizeof(double) * n);
	for (i = 0; i < n; i++)
		Pb[i] = b[p[i]];
	
	y = malloc(sizeof(double) * n);
	for (i = 0; i < n; i++) {
		soma = 0;
		
		for (j = 0; j < i; j++)
			soma += A[i][j] * y[j];
		
		y[i] = Pb[i] - soma;
	}
	
	// Achar x, bottom-up
	// Ux = y
	x = malloc(sizeof(double) * n);
	for (i = n-1; i >= 0; i--) {
		soma = 0;
		
		for (j = i+1; j < n; j++)
			soma += A[i][j] * x[j];
		
		x[i] = (y[i] - soma) / A[i][i];
	}
	
	// Liberar
	free(y);
	free(Pb);
	
	return x;
}

Matriz mat_cria (int m, int n) {
	int i;
	double ** matriz;
	
	matriz = malloc(m * sizeof(double *));
	
	for (i = 0; i < m; i++) {
		matriz[i] = malloc(n * sizeof(double));
	}
	
	return matriz;
}

void mat_libera (int m, Matriz A) {
	int i;
	
	for (i = 0; i < m; i++) {
		free(A[i]);
		A[i] = NULL;
	}
	
	free(A);
}

void mat_multv (int m, int n, Matriz A, double* v, double* w){
	int i, j;
	double aux = 0.0;
	
	for (i = 0; i < m; i++) {
		aux = 0.0;
		
		for (j = 0; j < n; j++) {
			aux += A[i][j] * v[j];
		}
		
		w[i] = aux;
	}
}

void mat_multm (int m, int n, int q, Matriz A, Matriz B, Matriz C) {
	int i, j, k;
	
	for (i = 0; i < m; i++) {
		for (j = 0; j < q; j++) {
			C[i][j] = 0;
			
			for (k = 0; k < n; k++) {
				C[i][j] += A[i][k]*B[k][j];
			}
		}
	}
}

void mat_imprime (int m, int n, Matriz A, char * format) {
	int i, j;
	
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			printf(format, A[i][j]);
			printf("  ");
		}
		printf("\n");
	}
}

