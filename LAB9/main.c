#include <stdio.h>
#include <math.h>

#include "ode.h"

double y (double t);
double dy (double t, double y);

int main (void) {
	double t = 2.4, t0 = 0, y0 = -1.0;
	double r, h, error, yt = y(t);
	
	printf("Metodo\t\t h\t\t\t y(2.4)\t\t\t erro\n");
	
	for(h = 0.1; h >= 0.001; h /= 10.0) {
		printf("- - - - - - -\n");
		
		r = Euler(t0, t, h, y0, dy);
		error = (r - yt) / yt;
		printf("Euler\t\t %lf\t %lf\t %lf\n", h, r, fabs(error));
		
		r = MidPoint(t0, t, 2*h, y0, dy);
		error = (r - yt) / yt;
		printf("MidPoint\t %lf\t %lf\t %lf\n", 2*h, r, fabs(error));
		
		r = RungeKutta(t0, t, 4*h, y0, dy);
		error = (r - yt) / yt;
		printf("RungeKutta\t %lf\t %lf\t %lf\n", 4*h, r, fabs(error));
	}
	
	printf("- - - - - - -\n");
	
	return 0;
}

double y (double t) {
	return exp(t*t / 2.0) - t*t - 2.0;
}

double dy (double t, double y) {
	return y*t + pow(t, 3);
}
