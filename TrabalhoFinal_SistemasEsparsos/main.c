//
//  main.c
//  Sparce
//
//  Created by Pedro Gomes Branco on 16/11/17.
//  Copyright © 2017 Pedro Gomes Branco. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include "sparse.h"
#include "methods.h"
#include "gradconj.h"

int mod(int a, int b) {
    int r = a % b;
    
    if (r < 0){
        return r + b;
    }
    return r;
}

Sparse** cria_primeiro_sistema(int n) {
    int i;
    Sparse** A = sparse_cria(n);
    
    for (i = 0; i < n; i++) {
        A[i] = malloc(sizeof(Sparse) * 6);
        
        A[i][0].col = i;
        A[i][0].val = i+1;
        
        A[i][1].col = mod(i+1, n);
        A[i][1].val = 0.5;
        
        A[i][2].col = mod(i+2, n);
        A[i][2].val = 0.5;
        
        A[i][3].col = mod(i-1, n);
        A[i][3].val = 0.5;
        
        A[i][4].col = mod(i-2, n);
        A[i][4].val = 0.5;
        
        A[i][5].col = -1;
    }
    return A;
}

Sparse** cria_segundo_sistema(int n) {
    int i, k, col;
    Sparse** A = sparse_cria(n);
    
    for (i = 0; i < n; i++) {
        A[i] = malloc(sizeof(Sparse) * 8);
        
        A[i][0].col = i;
        A[i][0].val = i+1;
        
        A[i][1].col = mod(i+1, n);
        A[i][1].val = 0.5;
        
        A[i][2].col = mod(i+2, n);
        A[i][2].val = 0.5;
        
        A[i][3].col = mod(i-1, n);
        A[i][3].val = 0.5;
        
        A[i][4].col = mod(i-2, n);
        A[i][4].val = 0.5;
        
        if(i+1 < n/2) {
            k = 5;
            
            col = (i+1)/2;
            if(col != i && col != mod(i+1, n)&& col != mod(i+2, n)&& col != mod(i-1, n)&& col != mod(i-2, n)){
                A[i][k].col = col;
                A[i][k].val = 0.5;
                k++;
            }
            
            col = (i+1)*2;
            if(i * 2 < n && col != i && col != mod(i+1, n)&& col != mod(i+2, n)&& col != mod(i-1, n)&& col != mod(i-2, n)){
                A[i][k].col = col;
                A[i][k].val = 0.5;
                k++;
            }
            
            A[i][k].col = -1;
        } else {
            A[i][5].col = -1;
        }
    }
    return A;
}

double* cria_x(int n) {
    int i;
    double* x = vet_cria(n);
    for(i = 0; i < n; i++) {
        x[i] = 1;
    }
    return x;
}

void testa(int n, Sparse** A, double* b, double* xbarra, double* xsol) {
    int i, iter;
    double dif;
    
    iter = ConjugateGradient(n, A, b, xbarra);
    
    for(i = 0; i < n; i++) {
        dif += fabs((xbarra[i] - xsol[i])/xsol[i]);
    }
    dif = dif / n;
    
    printf("Erro: %f%%\n", dif*n);
    printf("Iteracoes: %d\n", iter);
}

int main(void) {
    int i = 0;
    int n = 100;
    float w = 1.1;
    Sparse** A;
    double* x;
    double* b;
    double* xbarra;
    clock_t end,start;
    
    
    while (i < 3){
        printf("**** N = %d\n\n", n);
        
        printf("Sem pre-cond\n");
        start = clock();
        A = cria_primeiro_sistema(n);
        x = cria_x(n);
        b = vet_cria(n);
        xbarra = calloc(n, sizeof(double));
        sparse_multv(n, A, x, b);
        start = clock();
        testa(n, A, b, xbarra, x);
        end = clock();
        printf("Levou %lf segundos\n\n", (double)(end-start) / CLOCKS_PER_SEC);
        
        
        
        printf("Jacobi\n");
        A = cria_primeiro_sistema(n);
        x = cria_x(n);
        b = vet_cria(n);
        xbarra = calloc(n, sizeof(double));
        sparse_multv(n, A, x, b);
        start = clock();
        A = precond_jacobi(n, A, b);
        testa(n, A, b, xbarra, x);
        end = clock();
        printf("Levou %lf segundos\n\n", (double)(end-start) / CLOCKS_PER_SEC);
        
        
        printf("Gauss-Seidel\n");
        A = cria_primeiro_sistema(n);
        x = cria_x(n);
        b = vet_cria(n);
        xbarra = calloc(n, sizeof(double));
        sparse_multv(n, A, x, b);
        start = clock();
        A = precond_ssor(n, A, b, 1.0);
        testa(n, A, b, xbarra, x);
        end = clock();
        printf("Levou %lf segundos\n\n", (double)(end-start) / CLOCKS_PER_SEC);
        
        while (w < 2.1){
            printf("SSOR, w = %f\n", w);
            A = cria_primeiro_sistema(n);
            x = cria_x(n);
            b = vet_cria(n);
            xbarra = calloc(n, sizeof(double));
            sparse_multv(n, A, x, b);
            start = clock();
            A = precond_ssor(n, A, b, w);
            testa(n, A, b, xbarra, x);
            end = clock();
            printf("Levou %lf segundos\n\n", (double)(end-start) / CLOCKS_PER_SEC);
            w+=0.1;
        }
        
        w = 1.1;
        i++;
        n*=10;
        
        printf("-----------------------------\n\n");
    }
    return 0;
}

