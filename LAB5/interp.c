//
//  interp.c
//  INF1608
//
//  Created by Lucas Ferraço on 20/09/17.
//  Copyright © 2017 Lucas Ferraço. All rights reserved.
//

#include "interp.h"
#include <math.h>
#include <stdlib.h>

typedef double ** Matriz;
Matriz mat_cria (int m, int n);
void mat_libera (int m, Matriz A);

double * Chebyshev (int n, double a, double b) {
	int i, beta = -1;
	double xi;
	double * amostras = malloc(sizeof(double *) * n);
	
	for (i = 0; i < n; i++) {
		beta += 2;
		
		xi = (b - a)/2.0;
		xi *= cos((beta*M_PI) / (2.0*n));
		xi += (a+b)/2.0;
		
		amostras[i] = xi;
	}
	
	return amostras;
}

double * NewtonCoef (int n, double * xi, double (*f) (double)) {
	int i, j, k;
	Matriz F = mat_cria(n, n);
	double * b = malloc(sizeof(double *) * n);
	
	for (k = 0; k < n; k++) {
		i = 0;
		for (j = k; j < n; j++, i++) {
			if (i == j)
				F[i][j] = f(xi[i]);
			else
				F[i][j] = (F[i+1][j] - F[i][j-1]) / (xi[j] - xi[i]);
		}
	}
	
	for (i = 0; i < n; i++)
		b[i] = F[0][i];
	
	mat_libera(n, F);
	
	return b;
}

double NewtonAval (int n, double * xi, double * bi, double x) {
	int i, j;
	double aval = 0, f;
	
	for (i = 0; i < n; i++) {
		f = 1;
		
		for (j = 0; j < i; j++)
			f *= x - xi[j];
		
		aval += bi[i] * f;
	}
	
	return aval;
}

/// Funcoes auxiliares

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
