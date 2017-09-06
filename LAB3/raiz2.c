#include "raiz2.h"
#include <math.h>
#include <stdlib.h>

#define MAX_I 50

double ** mat_cria( int m, int n );
void mat_libera( int m, double ** A);
double mat_det_3x3( double ** M );

int secante (double x0, double x1, int p, double (*f) (double x), double* r) {
	int i = 0;
	double precision = 0.5 * pow(10, -p);
	double fx0 = f(x0), fxi = f(x1), dx;
	
	while (fabs(fxi) >= precision && i < MAX_I) {
		dx = (fxi - fx0)/(x1 - x0);
		x0 = x1;
		x1 = x1 - fxi/dx;
		
		fx0 = fxi;
		fxi = f(x1);
		
		i++;
	}
	
	if (i >= MAX_I)
		return 0;
	else
		*r = x1;
	
	return i;
}

int IQI (double x0, double x1, double x2, int p, double (*f) (double x), double * r) {
	int i = 0;
	double precision = 0.5 * pow(10, -p);
	double ** A, ** Ac;
	double fx0 = f(x0), fx1 = f(x1), fx2 = f(x2), fx = fx2;
	double d0, d1, d2, c;
	
	while(fabs(fx) >= precision && ++i && i < MAX_I) {
		A = mat_cria(3, 3);
		A[0][0] = fx0 * fx0;
		A[0][1] = fx0;
		A[0][2] = 1;
		A[1][0] = fx1 * fx1;
		A[1][1] = fx1;
		A[1][2] = 1;
		A[2][0] = fx2 * fx2;
		A[2][1] = fx2;
		A[2][2] = 1;
		
		Ac = mat_cria(3, 3);
		Ac[0][0] = A[0][0];
		Ac[0][1] = A[0][1];
		Ac[0][2] = x0;
		Ac[1][0] = A[1][0];
		Ac[1][1] = A[1][1];
		Ac[1][2] = x1;
		Ac[2][0] = A[2][0];
		Ac[2][1] = A[2][1];
		Ac[2][2] = x2;
		
		c = mat_det_3x3(Ac) / mat_det_3x3(A);
		
		mat_libera(3, Ac);
		mat_libera(3, A);
		
		d0 = fabs(c - x0);
		d1 = fabs(c - x1);
		d2 = fabs(c - x2);
		
		if(d0 > d1 && d0 > d2)
			x0 = c;
		else if(d1 > d0 && d1 > d2)
			x1 = c;
		else
			x2 = c;
		
		fx0 = f(x0);
		fx1 = f(x1);
		fx2 = f(x2);
		fx = f(c);
		
		i++;
	}
	
	if (i >= MAX_I)
		return 0;
	else
		*r = c;
	
	return i;
}

double ** mat_cria (int m, int n) {
	int i;
	double ** matriz;
	
	matriz = malloc(m * sizeof(double *));
	
	for (i = 0; i < m; i++) {
		matriz[i] = malloc(n * sizeof(double));
	}
	
	return matriz;
}

void mat_libera (int m, double ** A) {
	int i;
	
	for (i = 0; i < m; i++) {
		free(A[i]);
		A[i] = NULL;
	}
	
	free(A);
}

double mat_det_3x3( double ** M ) {
	double l0, l1, l2;
	
	if(!M) {
		printf("Matriz invalida\n");
		return -1;
	}
	
	l0 = M[0][0] * (M[1][1] * M[2][2] - M[1][2] * M[2][1]);
	l1 = M[0][1] * (M[1][0] * M[2][2] - M[2][0] * M[1][2]);
	l2 = M[0][2] * (M[1][0] * M[2][1] - M[2][0] * M[1][1]);
	
	return l0 - l1 + l2;
}
