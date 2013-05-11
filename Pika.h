#pragma once
#include <iostream>
#include <iomanip>
#include <Eigen\Eigen\Dense>
using namespace Eigen;
using namespace std;

// Shtesat e mija


enum ngarkese_lloj
{
	KATRORE,
	TREKENDESH_P,
	TREKENDESH_M
};

class Pika
{
	double _pozita[2];
	double _forcat[2];
	double _moment;
	string _emri;

public:
	// Konstruktoret
	Pika(void);
	Pika(const Vector2d&, const Vector2d&);
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
	void ngarkese(double q, double L, ngarkese_lloj lloj); 
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
	double krahu(const Pika&, int) const;
	double moment(const Pika&) const;

};

