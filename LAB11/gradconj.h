//
//  gradconj.h
//  INF1608
//
//  Created by Lucas Ferraço on 03/11/17.
//  Copyright © 2017 Lucas Ferraço. All rights reserved.
//

#ifndef gradconj_h
#define gradconj_h

#include <stdio.h>

#include "matriz.h"

int GradienteConjugado (int n, double ** A, double * b, double * x, double tol);

#endif /* gradconj_h */
