//
//  ode.c
//  INF1608
//
//  Created by Lucas Ferraço on 19/10/17.
//  Copyright © 2017 Lucas Ferraço. All rights reserved.
//

#include "ode.h"

double Euler (double t0, double t1, double h, double x0, double (*f) (double t, double x)) {
	double x1 = x0, t;
	
	for (t = t0; t < t1; t += h) {
		if (t + h > t1)
			h /= 3.0;
		
		x1 += h * f(t, x1);
	}
	
	return x1;
}

double MidPoint (double t0, double t1, double h, double x0, double (*f) (double t, double x)) {
	double s1, x1 = x0, t;
	
	for(t = t0; t < t1; t += h)	{
		if(t + h > t1)
			h /= 3.0;
		
		s1 = h * f(t,x1);
		x1 += h * f((t + h)/2.0, (x1 + s1)/2.0);
	}
	
	return x1;
}

double RungeKutta (double t0, double t1, double h, double x0, double (*f) (double t, double x)) {
	double s1,s2,s3,s4;
	double x1 = x0, t;
	
	for(t = t0; t < t1; t += h) {
		if(t+h>t1)
			h /= 3.0;
		
		s1 = h * f(t,x1);
		s2 = h * f(t + h/2.0, x1 + s1/2.0);
		s3 = h * f(t + h/2.0, x1 + s2/2.0);
		s4 = h * f(t + h, x1 + s3);
		x1 += (s1 + 2*(s2 + s3) + s4) / 6.0;
	}
	
	return x1;
}
