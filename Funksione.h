#pragma once
#include <math.h>

bool PROG_DEBUG = true;

double deg2rad(double a)
{
	double a_rad;
	a+=180;
	a_rad = a * (M_PI/180.);
	return a_rad;
}