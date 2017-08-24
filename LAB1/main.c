//
//  main.c
//  INF1608
//
//  Created by Lucas Ferraço on 16/08/17.
//  Copyright © 2017 Lucas Ferraço. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include "taylor.h"

int main(int argc, const char * argv[]) {
	double x = 0, n = 1.001;
	
	// Teste fcos
	printf("Teste fcos\n");
	printf("fcos(%f) = %lf \n", x, fcos(x));
	printf("cos(%f)  =  %lf \n", x, cos(x));
	printf("\n");
	
	// Teste fcos_erro
	printf("Teste fcos_erro\n");
	printf("fcos_erro(%f) = %lf \n", x, fcos_erro(x));
	if (fcos_erro(x) > fabs(cos(x) - fcos(x))) {
		printf("Aproximacao correta\n");
	}
	else {
		printf("Aproximacao errada\n");
	}
	printf("\n");
	
	// Teste fsqrt
	printf("Teste fsqrt\n");
	printf("fsqrt(%f) = %lf \n", n, fsqrt(n));
	printf("sqrt(%f)  =  %lf \n", n, 1/sqrt(n));
	printf("\n");
	
	// Teste fsqrt_erro
	printf("Teste fsqrt_erro\n");
	printf("fcos_erro(%f) = %lf \n", n, fsqrt_erro(n));
	if (fsqrt_erro(n) > fabs(1/sqrt(n) - fsqrt(n))) {
		printf("Aproximacao correta\n");
	}
	else {
		printf("Aproximacao errada\n");
	}
	printf("\n");
	
    return 0;
}
