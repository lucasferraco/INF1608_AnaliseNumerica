//
//  matriz.c
//  inf1608_lab0
//
//  Created by Lucas Ferraço on 16/08/17.
//  Copyright © 2017 Lucas Ferraço. All rights reserved.
//

#include "matriz.h"

Matriz mat_cria (int m, int n) {
	int i;
	Matriz matriz;
	
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

void mat_transposta (int m, int n, Matriz A, Matriz T){
	int i, j;
	
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			T[j][i] = A[i][j];
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

int mat_iguais (int m, int n, Matriz A, Matriz B, double tol) {
	int eIgual = 1, i = 0, j = 0;
	double dif = 0.0;
	
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			dif = fabs(A[i][j] - B[i][j]);
			
			if (dif > tol) {
				eIgual = 0;
				break;
			}
		}
	}
	
	return eIgual;
}

void mat_imprime (int m, int n, Matriz A, char* format) {
	int i, j;
	
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			printf(format, A[i][j]);
			printf(" ");
		}
		printf("\n");
	}
}
