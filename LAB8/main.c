#include <stdio.h>
#include <math.h>

#include "simpson.h"

double integral1(double x);
double integral2(double x);
double integral3(double x);

int main(void) {
	double tol = pow(10, -7), t1, t2;
	
	printf("Integral 1\n");
	printf("AdaptiveSimpson =  %.10g\n", AdaptiveSimpson(0, 1, integral1, tol));
	printf("\n");
	
	printf("Integral 2\n");
	t1 = 1.0 / sqrt(2 * M_PI);
	printf("AdaptiveSimpson =  %.10g\n", t1 * AdaptiveSimpson(-1, 1, integral2, tol));
	printf("\n");
	
	printf("Integral 3\n");
	t2 = 2.0 / sqrt(M_PI);
	printf("AdaptiveSimpson =  %.10g\n", t2 * AdaptiveSimpson(0, 3, integral3, tol));
	printf("\n");
	
	return 0;
}

double integral1(double x) {
	return x / sqrt(x*x + 9);
}

double integral2(double x) {
	return  exp(-x*x / 2.0);
}

double integral3(double x) {
	return exp(-x*x);
}
