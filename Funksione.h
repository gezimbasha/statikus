#ifndef _FUNKSIONET_H
#define _FUNKSIONET_H
#include <math.h>

double deg2rad(double a)
{
	double a_rad;
	a+=180;
	a_rad = a * (M_PI/180.);
	return a_rad;
}

template<class T>
T _absZero(T x) // Not used atm;
{
	double TOL = 1e-4;
	if(abs(x) <= TOL){
		return 0;
	}
	else
		return x;
}

#endif