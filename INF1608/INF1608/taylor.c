//
//  taylor.c
//  INF1608
//
//  Created by Lucas Ferraço on 23/08/17.
//  Copyright © 2017 Lucas Ferraço. All rights reserved.
//

#include "taylor.h"
#include <math.h>

double fcos (double x) {
	double p1, p3;
	
	p1 = -(x - M_PI_2);
	p3 = (x - M_PI_2) * (x - M_PI_2) * (x - M_PI_2);
	p3 *= 1.0/6;
	
	return  p1 + p3;
}

double fcos_erro (double x) {
	double p5 = (x - M_PI_2) * (x - M_PI_2) * (x - M_PI_2) * (x - M_PI_2) * (x - M_PI_2);
	p5 *= -1.0/120;
	
	return fabs(p5);
}

double fsqrt (double x) {
	double p1, p2, p3;
	
	p1 = -(x - 1)/2;
	p2 = (x - 1) * (x - 1);
	p2 *= 3.0/8;
	p3 = (x - 1) * (x - 1) * (x - 1);
	p3 *= -5.0/16;
	
	return  1.0 + p1 + p2 + p3;
}

double fsqrt_erro (double x) {
	double p4 = (x - 1) * (x - 1) * (x - 1) * (x - 1);
	p4 *= 35.0/128;
	
	return fabs(p4);
}
