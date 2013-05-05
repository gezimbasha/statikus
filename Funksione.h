#pragma once
#include <math.h>

double deg2rad(double a)
{
	double a_rad;
	a_rad = a * (M_PI/180.);
	return a_rad;
}