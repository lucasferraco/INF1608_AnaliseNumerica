//
//  ode.h
//  INF1608
//
//  Created by Lucas Ferraço on 19/10/17.
//  Copyright © 2017 Lucas Ferraço. All rights reserved.
//

#ifndef ode_h
#define ode_h

#include <stdio.h>

// Metodo de Euler
// Recebe como parametros o tempo inicial t0, o tempo final t1, o passo de integracao h,
// o valor inicial x(t0) e a funcao derivada f(t,x(t)), tendo como retorno o valor no tempo final x(t1).
double Euler (double t0, double t1, double h, double x0, double (*f) (double t, double x));

// Ponto Medio
double MidPoint (double t0, double t1, double h, double x0, double (*f) (double t, double x));

// Runge-Kutta de ordem 4
double RungeKutta (double t0, double t1, double h, double x0, double (*f) (double t, double x));

#endif /* ode_h */
