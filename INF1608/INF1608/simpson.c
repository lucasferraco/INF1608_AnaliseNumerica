//
//  simpson.c
//  INF1608
//
//  Created by Lucas Ferraço on 13/10/17.
//  Copyright © 2017 Lucas Ferraço. All rights reserved.
//

#include "simpson.h"
#include <math.h>

double DoubleSimpson (double a, double b, double (*f) (double x), double * v) {
	double c = (a + b) / 2;
	double fa = f(a);
	double fb = f(b);
	double fc = f(c);
	double Sab = ((b-a)/6) * (fa + 4*fc + fb);
	double Sac = ((c-a)/6) * (fa + 4*f((a+c)/2) + fc);
	double Scb = ((b-c)/6) * (fc + 4*f((c+b)/2) + fb);
	double Eab16 = fabs(Sab - Sac - Scb) / 15.0;
	
	*v = Sac + Scb + Eab16;
	
	return Eab16;
}


double AdaptiveSimpson (double a, double b, double (*f) (double x), double tol) {
	double v, c;
	
	if (DoubleSimpson(a, b, f, &v) < tol) {
		return v;
	}
	
	c = (a + b) / 2;
	return DoubleSimpson(a, c, f, &v) + DoubleSimpson(c, b, f, &v);
}
