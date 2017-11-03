//
//  gradconj.c
//  INF1608
//
//  Created by Lucas Ferraço on 03/11/17.
//  Copyright © 2017 Lucas Ferraço. All rights reserved.
//

#include "gradconj.h"

double Norma2 (int n, double * v) {
	int i;
	double soma = 0;
	
	for (i = 0; i < n; i++)
		soma += v[i] * v[i];
	
	return sqrt(soma);
}

int GradienteConjugado (int n, double ** A, double * b, double * x, double tol) {
	int i, k;
	double * Ax = (double *) malloc(sizeof(double) * n);
	double * rk0 = (double *) malloc(sizeof(double) * n);
	double * rk1 = (double *) malloc(sizeof(double) * n);
	double * dk0 = (double *) malloc(sizeof(double) * n);
	double * dk1 = (double *) malloc(sizeof(double) * n);
	double * Ad = (double *) malloc(sizeof(double) * n);
	double * xn = (double *) malloc(sizeof(double) * n);
	
	double alpha, beta, num, den;

	// d0 = r0 = b − Ax
	mat_multv(n, n, A, x, Ax);
	for (i = 0; i < n; i++) {
		rk0[i] = b[i] - Ax[i];
		dk0[i] = rk0[i];
	}
	
	
	for (k = 0; k < n; k++) {
		if (Norma2(n, rk0) < tol)
			break;
		
		// alpha_k = rTk * rK / dTk * Adk
		num = 0;
		den = 0;
		mat_multv(n, n, A, dk0, Ad);
		for (i = 0; i < n; i++) {
			num += rk0[i] * rk0[i];
			den += dk0[i] * Ad[i];
		}
		alpha = num/den;
		
		// x_{k+1} = xk + Alpha_k dk
		for (i = 0; i < n; i++)
			xn[i] = x[i] + alpha * dk0[i];
		
		// r_{k+1} = rk - Alpha_k A dk
		for (i = 0; i < n; i++)
			rk1[i] = rk0[i] + alpha * Ad[i];
		
		// Beta_k = rTn * rn / rT * r
		num = 0;
		den = 0;
		for (i = 0; i < n; i++) {
			num += rk1[i] * rk1[i];
			den += rk0[i] * rk0[i];
		}
		beta = num/den;
		
		// d_{k+1} = r_{k+1} + Beta_k dk;
		for (i = 0; i < n; i++)
			dk1[i] = rk1[i] + beta * dk0[i];
		
		for (i = 0; i < n; i++) {
			x[i] = xn[i];
			rk0[i] = rk1[i];
			dk0[i] = dk1[i];
		}
	}
	
	return k;
}
