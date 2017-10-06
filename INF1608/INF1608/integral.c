#include "integral.h"

double derivada (double (*f) (double x), double h, double x) {
	double f1 = f(x + h);
	double f2 = f(x - h);
	
	return (f1 - f2) / 2*h;
}

double simpson (double (*f) (double), double a, double b, int n) {
	double h = (b - a) / n;
	double xi = a, integral = 0;
	
	while (xi < b) {
		integral += (h/6) * (f(xi) + 4*f(xi + h/2) + f(xi + h));
		xi += h;
	}
	
	return integral;
}

double pontomedio (double (*f) (double), double a, double b, int n) {
	double h = (b - a) / n;
	double xi = a, integral = 0;
	
	while (xi < b) {
		integral += h * f(xi + h/2);
		xi += h;
	}
	
	return integral;
}
