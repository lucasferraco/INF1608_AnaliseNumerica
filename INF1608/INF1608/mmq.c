//
//  mmq.c
//  INF1608
//
//  Created by Lucas Ferraço on 27/09/17.
//  Copyright © 2017 Lucas Ferraço. All rights reserved.
//

#include "mmq.h"

double * mmq (int m, int n, Matriz A, double * b) {
	int * p;
	Matriz AtA, At;
	double * Atb = (double *) malloc(sizeof(double) * n),
	* x = (double *) malloc(sizeof(double) * n);
	
	AtA = mat_cria(n, n);
	At = mat_cria(n, m);
	
	mat_transposta(m, n, A, At);
	mat_multm(n, m, n, At, A, AtA);
	p = fatoracao(n, AtA);
	mat_multv(n, m, At, b, Atb);
	
	x = substituicao(n, AtA, p, Atb);
	
	mat_libera(n, At);
	mat_libera(n, AtA);
	free(Atb);
	
	return x;
}

double norma2 (int m, int n, Matriz A, double * b, double * x) {
	int i;
	double e = 0.0;
	double * r = (double *) malloc(sizeof(double) * m);
	double * Ax = (double *) malloc(sizeof(double) * m);
	
	mat_multv(m, n, A, x, Ax);
	
	for (i = 0; i < m; i++) {
		r[i] = b[i] - Ax[i];
		e += r[i] * r[i];
	}
	
	free(r);
	free(Ax);
	
	return sqrt(e);
}

double concentracao (int n, double * t, double * c, double * pa, double * pb) {
	int i;
	double e,
	* b = (double *) malloc(sizeof(double) * n),
	* x = (double *) malloc(sizeof(double) * 2);
	Matriz A;
	
	A = mat_cria(n, 2);
	
	// log(a) + b*t = log(c) - log(t)
	for (i = 0; i < n; i++) {
		A[i][0] = 1;
		A[i][1] = t[i];
		b[i] = log(c[i]) - log(t[i]);
	}
	
	x = mmq(n, 2, A, b);
	*pa = exp(x[0]);
	*pb = x[1];
	
	e = norma2(n, 2, A, b, x);
	
	mat_libera(n, A);
	free(b);
	free(x);
	
	return e;
}
