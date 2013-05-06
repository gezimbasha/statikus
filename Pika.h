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
	string _emri;

public:
	// Konstruktoret
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
	string emri() const;
	
	void x(double);
	void y(double);
	void Fx(double);
	void Fy(double);
	void pozita(double, double);
	void force(double, double);
	void moment(double);
	void emri(string);

	// Operatoret
	friend ostream& operator << (ostream&, Pika&);
	Pika& operator=(const Pika&);
	Pika& operator+=(const Pika&);
	Pika& operator-=(const Pika&);
	const Pika operator+(const Pika&) const;
	const Pika operator-(const Pika&) const;
	bool operator==(const Pika&) const;
	bool operator!=(const Pika&) const;

	// Funksione
	double krahu_x(const Pika&) const;
	double krahu_y(const Pika&) const;
	double moment(const Pika&) const;

};

