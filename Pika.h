#pragma once
#include <iostream>
#include <iomanip>
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
	Pika(Vector2d*, Vector2d*);
	Pika(double, double, double, double);
	~Pika(void);

	// Qasja
	double x() const;
	double y() const;
	double Fx() const;
	double Fy() const;
	double F() const;
	double M() const;
	
	void x(double);
	void y(double);
	void Fx(double);
	void Fy(double);
	void force(double, double);
	void moment(double);

	// Operatoret
	friend ostream& operator << (ostream&, Pika&);
	Pika& operator=(const Pika&);

};

