#pragma once
#include <iostream>
#include <Eigen\Eigen\Dense>
using namespace Eigen;
using namespace std;

class Pika
{
	Vector2d _pozita;
	Vector2d _forcat;
	double _moment;

public:
	Pika(void);
	Pika(Vector2d, Vector2d);
	Pika(double, double, double, double);
	~Pika(void);

	// Qasja
	double x();
	double y();
	double Fx();
	double Fy();
	double F();
	double M();

	void x(double);
	void y(double);
	void Fx(double);
	void Fy(double);
	void force(double, double);
	void moment(double);

};

