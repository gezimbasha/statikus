#pragma once
#include <math.h>

const double M_PI = 3.14159265359;

double deg2rad(double a)
{
	double a_rad;
	a_rad = a * (M_PI/180.);
	return a_rad;
}