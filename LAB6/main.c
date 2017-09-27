#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "mmq.h"
#include "matriz.h"

void popula4aa(Matriz A, double * baa);
void popula4ab(Matriz B, double * bab);
void popula4b(double * t, double * c);

int main(void){
	int i, maa = 5, naa = 3, mab = 5, nab = 4, n = 8;
	Matriz Maa, Mab;
	double * baa = (double *) malloc(sizeof(double) * maa),
	* bab = (double *) malloc(sizeof(double) * mab),
	* xaa = (double *) malloc(sizeof(double) * naa),
	* xab = (double *) malloc(sizeof(double) * nab);
	double j, pa, pb,
	* t = (double *) malloc(sizeof(double) * n),
	* c = (double *) malloc(sizeof(double) * n);
	
	// Questao 4aa
	Maa = mat_cria(maa, naa);
	popula4aa(Maa, baa);
	xaa = mmq(maa, naa, Maa, baa);
	printf("Questao 4.a.a\n");
	printf("Solucao aprox.: ");
	for (i = 0; i < naa; i++)
		printf("%.4g ", xaa[i]);
	printf("\nErro associado: %.4g\n\n", norma2(maa, naa, Maa, baa, xaa));
	
	// Questao 4ab
	Mab = mat_cria(mab, nab);
	popula4ab(Mab, bab);
	xab = mmq(mab, nab, Mab, bab);
	printf("Questao 4.a.b\n");
	printf("Solucao aprox.: ");
	for (i = 0; i < naa; i++)
		printf("%.4g ", xab[i]);
	printf("\nErro associado: %.4g\n\n", norma2(mab, nab, Mab, bab, xab));
	
	// Questao 4b
	popula4b(t, c);
	printf("Questao 4.b\n");
	printf("Erro associado: %.4g\n", concentracao(n, t, c, &pa, &pb));
	printf("pa = %.4g\tpb = %.4g\n\n", pa, pb);
	printf("  t  |  c\n");
	printf("-----|-----------------\n");
	for (j = 0.0; j < 16.0; j+=0.1)
		printf("%.1f  |  %.16g\n", j, pa * j * exp(pb * j));
	
	mat_libera(maa, Maa);
	mat_libera(mab, Mab);
	free(baa);
	free(bab);
	free(xaa);
	free(xab);
	free(t);
	free(c);
	
	return 0;
}

void popula4aa(Matriz A, double * baa) {
	A[0][0] = 3; A[0][1] =-1; A[0][2] = 2;
	A[1][0] = 4; A[1][1] = 1; A[1][2] = 0;
	A[2][0] =-3; A[2][1] = 2; A[2][2] = 1;
	A[3][0] = 1; A[3][1] = 1; A[3][2] = 5;
	A[4][0] =-2; A[4][1] = 0; A[4][2] = 3;
	
	baa[0] = 10;
	baa[1] = 10;
	baa[2] = -5;
	baa[3] = 15;
	baa[4] = 0;
}

void popula4ab(Matriz B, double * bab) {
	B[0][0] = 4; B[0][1] = 2; B[0][2] = 3; B[0][3] = 0;
	B[1][0] =-2; B[1][1] = 3; B[1][2] =-1; B[1][3] = 1;
	B[2][0] = 1; B[2][1] = 3; B[2][2] =-4; B[2][3] = 2;
	B[3][0] = 1; B[3][1] = 0; B[3][2] = 1; B[3][3] = -1;
	B[4][0] = 3; B[4][1] = 1; B[4][2] = 3; B[4][3] = -2;
	
	bab[0] = 10;
	bab[1] = 0;
	bab[2] = 2;
	bab[3] = 0;
	bab[4] = 5;
}

void popula4b(double * t, double * c) {
	t[0] = 1; c[0] = 08.0;
	t[1] = 2; c[1] = 12.3;
	t[2] = 3; c[2] = 15.5;
	t[3] = 4; c[3] = 16.8;
	t[4] = 5; c[4] = 17.1;
	t[5] = 6; c[5] = 15.8;
	t[6] = 7; c[6] = 15.2;
	t[7] = 8; c[7] = 14.0;
}
