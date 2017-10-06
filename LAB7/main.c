#include <stdio.h>
#include <math.h>

#include "integral.h"

double f(double x);
double f1(double x);
double integral1(double x);
double integral2(double x);
double integral3(double x);
double Emin(void);

int main(void) {
	int i;
	double pot10, dn, fd1 = f1(0), erro;
	
	// Questao 2.a
	printf("Questao 2.a\n");
	printf("    h       |               f'(0)            |           Erro\n");
	for (i = 0; i < 12; i++) {
		pot10 = pow(10, -(i + 1));
		dn = derivada(f, pot10, 0);
		erro = dn - fd1;
		
		printf(" 10^(-%.2d)   |   %.20g   |   %.20g\n", i + 1, dn, erro);
	}
	
	printf("\n");
	printf("O h que minimiza o erro e 10^-6.\n");
	printf("O h teorico que minimiza o erro e %.20g.\n", Emin());
	printf("Os valores estao na mesma ordem de precisao, logo conferem.\n");
	printf("\n\n");
	
	// Questao 2.b
	printf("Questao 2.b\n");
	
	printf("Integral 1\n");
	printf("Resultado = 2.0\n");
	printf("S(n = 16) = %.14g | S(n = 32) = %.14g\n", simpson(integral1, 0, 4, 16), simpson(integral1, 0, 4, 32));
	printf("M(n = 16) = %.14g | M(n = 32) = %.14g\n", pontomedio(integral1, 0, 4, 16), pontomedio(integral1, 0, 4, 32));
	
	printf("\nIntegral 2\n");
	printf("Resultado = 6.9986217091241\n");
	printf("S(n = 16) = %.14g | S(n = 32) = %.14g\n", simpson(integral2, 1, 3, 16), simpson(integral2, 1, 3, 32));
	printf("M(n = 16) = %.14g | M(n = 32) = %.14g\n", pontomedio(integral2, 1, 3, 16), pontomedio(integral2, 1, 3, 32));

	printf("\nIntegral 3\n");
	printf("Resultado = 5.8696044010894\n");
	printf("S(n = 16) = %.14g | S(n = 32) = %.14g\n", simpson(integral3, 0, M_PI, 16), simpson(integral3, 0, M_PI, 32));
	printf("M(n = 16) = %.14g | M(n = 32) = %.14g\n", pontomedio(integral3, 0, M_PI, 16), pontomedio(integral3, 0, M_PI, 32));
	
	printf("\n");
	printf("O metodo de Simpson e mais preciso que o do Ponto Medio.\n");
	printf("Quanto mais passos, mais preciso e o resultado.\n");
	printf("\n");
	
	return 0;
}

double f(double x) {
	return cos(x) - 2 * sin(x);
}

double f1(double x) {
	return -sin(x) - 2*cos(x);
}

double integral1(double x) {
	double denominador = sqrt(pow(x, 2) + 9);
	
	return x/denominador;
}

double integral2(double x) {
	return pow(x, 2) * log(x);
}

double integral3(double x) {
	return pow(x, 2) * sin(x);
}

double Emin() {
	// (3 * EMAQ / f'''(0))^(-1/3)
	// f'''(0) = 2
	double maq = pow(2, -52);
	
	return cbrt(3 * maq / 2);
}

