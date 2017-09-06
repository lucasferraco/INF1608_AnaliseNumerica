#include <stdio.h>
#include <math.h>
#include "raiz2.h"

double f(double x) {
	return cos(x) - pow(x, 3) + x;
}

void calculoRaiz(double x0, double x1, double x2) {
	double r_sec = 0.0, r_IQI = 0.0, p = 6;
	
	printf("x0 = %.6g / x1 = %.6g / x2 = %.6g\n", x0, x1, x2);
	printf("Secante >> Iterações: %d Raiz: %.6f \n", secante(x0, x1, p, &f, &r_sec), r_sec);
	printf("IQI >> Iterações: %d Raiz: %.6f \n", IQI(x0, x2, x1, p, &f, &r_IQI), r_IQI);
	printf("\n");
	
	printf("-------------------------------\n\n");
}

int main(int argc, const char * argv[]) {
	
	printf("Calculo da raiz de f(x) = cos(x) - pow(x, 3) + x\n");
	printf("-------------------------------\n\n");
	calculoRaiz(0.0, 3.0, 1.5);
	calculoRaiz(1.13, 1.16, 1.14);
	calculoRaiz(-4, 4, 1);
	calculoRaiz(1000, 2000, 1200);
	
    return 0;
}
