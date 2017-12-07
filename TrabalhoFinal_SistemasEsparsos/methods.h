//
//  methods.h
//  Sparce
//
//  Created by Pedro G. Branco on 25/11/17.
//  Copyright © 2017 Pedro Gomes Branco. All rights reserved.
//

#ifndef methods_h
#define methods_h

#include <stdio.h>
#include "sparse.h"

Sparse** precond_jacobi(int n, Sparse** A, double* b);

Sparse** precond_ssor(int n, Sparse** A, double* b, double w);

#endif /* methods_h */
