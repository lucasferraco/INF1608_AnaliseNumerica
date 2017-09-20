#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "interp.h"

int fat(int n);

int main(void){
	int n = 6;
	double a = 0, b = M_PI_2;
	double x, aprox, cosReal;
	double erro = (pow((b-a)/2, n) / (pow(2, n-1)) * (1.0 / fat(n)));
	double * xi = Chebyshev(n, a, b);
	double * bi = NewtonCoef(n, xi, &cos);
	
	for (x = -2 * M_PI; x < 2 * M_PI; x += 0.5) {
		aprox = NewtonAval(n, xi, bi, x);
		cosReal = cos(x);
		
		printf("x:\t\t\t\t%.10g\n", x);
		printf("cos(x):\t\t\t%.10g\n", cosReal);
		printf("NewtonAval(x):\t%.10g\n\n", aprox);
		
		if (x >= 0 && x <= M_PI_2)
			printf("-> x pertence a [0, Pi/2] <-\n\n");
		
		if (fabs(cosReal - aprox) > erro) {
			printf("-> Apoximacao ruim <-\n");
			printf("erro calculado = %.12g\n", fabs(cosReal - aprox));
			printf("erro permitido = %.12g\n\n", erro);
		}
		
		
		printf("----------------------------\n\n");
	}
	
	free(bi);
	free(xi);
	
	return 0;
}

int fat(int n) {
	if (n == 1)
		return 1;
	else
		return n * fat(n - 1);
}
