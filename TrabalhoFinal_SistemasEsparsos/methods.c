//
//  methods.c
//  Sparce
//
//  Created by Pedro G. Branco on 25/11/17.
//  Copyright © 2017 Pedro Gomes Branco. All rights reserved.
//

#include "methods.h"

Sparse** precond_jacobi(int n, Sparse** A, double* b) {
    int i;
    
    double* b_ = vet_cria(n);
    Sparse** Minv = sparse_cria(n);
    Sparse** C;
    
    for(i = 0; i < n; i++) {
        Minv[i] = malloc(sizeof(Sparse) * 2);
        
        Minv[i][0].col = i;
        Minv[i][0].val = 1.0/sparse_get(i, i, A);
        
        Minv[i][1].col = -1;
    }
    
    
    C = sparse_multm(n, Minv, A);
    
    sparse_multv(n, Minv, b, b_);
    vet_copia(n, b_, b);
    
    return C;
}

Sparse** precond_ssor(int n, Sparse** A, double* b, double w) {
    int i, j, k;
    
    double* b_ = vet_cria(n);
    
    Sparse** C;
    Sparse** M1 = sparse_cria(n);
    Sparse** M2 = sparse_cria(n);
    Sparse** M3 = sparse_cria(n);
    Sparse** Ma;
    Sparse** Mb;
    Sparse** Minv;
    
    for(i = 0; i < n; i++) {
        M1[i] = malloc(sizeof(Sparse) * n);
        
        M1[i][0].col = i;
        M1[i][0].val = sparse_get(i, i, A);
        
        k = 1;
        for(j = 0; j < n; j++) {
            if(A[i][j].col == -1) break;
            if(A[i][j].col < i) {
                M1[i][k].col = A[i][j].col;
                M1[i][k].val = A[i][j].val * w;
                k++;
            }
        }
        
        M1[i][k].col = -1;
    }
    
    for(i = 0; i < n; i++) {
        M2[i] = malloc(sizeof(Sparse) * 2);
        
        M2[i][0].col = i;
        M2[i][0].val = 1.0/sparse_get(i, i, A);
        
        M2[i][1].col = -1;
    }
    
    for(i = 0; i < n; i++) {
        M3[i] = malloc(sizeof(Sparse) * n);
        
        M3[i][0].col = i;
        M3[i][0].val = sparse_get(i, i, A);
        
        k = 1;
        for(j = 0; j < n; j++) {
            if(A[i][j].col == -1) break;
            if(A[i][j].col > i) {
                M3[i][k].col = A[i][j].col;
                M3[i][k].val = A[i][j].val * w;
                k++;
            }
        }
        
        M3[i][k].col = -1;
    }
    
    Ma = sparse_multm(n, M1, M2);
    Mb = sparse_multm(n, Ma, M3);
    // M = sparse_inv(n, Mb);
    Minv = Mb;
    
    C = sparse_multm(n, Minv, A);
    
    sparse_multv(n, Minv, b, b_);
    vet_copia(n, b_, b);
    
    return C;
}
