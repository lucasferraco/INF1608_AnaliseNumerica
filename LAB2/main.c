//
//  main.c
//  INF1608
//
//  Created by Lucas Ferraço on 16/08/17.
//  Copyright © 2017 Lucas Ferraço. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include "raiz.h"

double bisec_teste(double x) {
	return pow(x, 3) - x*sin(2*x) + 0.2;
}

double pf_teste(double x) {
	return (cos(x)+2)/3;
}

int main(int argc, const char * argv[]) {
	double a = 0.25, b = 0.5, p = pow(10, -6), x0 = 1.0;
	double raio = 1.0, volume = 4.0/3.0*M_PI / 2.0;
	
	// Teste bissecao
	printf("Teste bissecao\n");
	printf("funcao = pow(x, 3) - x*sin(2*x) + 0.2\n");
	printf("limites: inf = %.10g \tsup = %.10g\n", a, b);
	printf("precisao = %.10g \n", p);
	printf("bissecao = %.10g \n", bissecao(a, b, p, bisec_teste));
	printf("\n");
	
	// Teste altura_agua
	printf("Teste altura_agua\n");
	printf("raio = %.10g \tvolume = %.10g\n", raio, volume);
	printf("altura_agua = %.10g \n", altura_agua(raio, volume));
	printf("\n");
	
	// Teste pontofixo
	printf("Teste pontofixo\n");
	printf("funcao = (cos(x)+2)/3\n");
	printf("x0 = %.10g\n", x0);
	printf("epsilon = %.10g \n", p);
	printf("pontofixo = %.10g \n", pontofixo(x0, p, pf_teste));
	printf("\n");
	
	// Teste fraiz
	printf("Teste fraiz\n");
	printf("fraiz(3) = %.10g \n", fraiz(3));
	printf("\n");
	
    return 0;
}
