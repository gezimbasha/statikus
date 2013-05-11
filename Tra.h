#pragma once

#include "Reaksion.h"
#include <vector>

typedef vector<Pika> Pika_Stack;
typedef vector<Reaksion> Reaks_Stack;

// Klasa Tra
// Definon nje tra me gjatesi diskrete L, shfrytezohet si
// abstraksion per te definuar matricen zgjidhese.

class Tra
{
	// Pikat kryesore
	Pika_Stack _pikat;
	int _npk;

	int _tGjatesia;

	double _Fx;
	double _Fy;
	double _M;

	double _Rx;
	double _Ry;
	double _Rm;

public:
	Tra(void);
	Tra(int _gjatesia);
	Tra(int _gjatesia, int numForca);
	virtual ~Tra(void);

	// Qasesit
	void force(Pika &pk);
	void force(double x, double y, double F, double kend);
	void forca(Pika *pk, int nf);
	void llogarit_Momentet(Pika &pk);
	void L(int L);

	// Kontakti
	void kontakt(Reaksion &pk);

	// Deklarimet
	double L() const;
	double Fx() const;
	double Fy() const;
	double M() const;
	double Rx() const;
	double Ry() const;
	double Rm() const;
	unsigned int _madhesia() const;
	bool ekuiliber();

	// Operatoret
	friend ostream& operator << (ostream&, Tra &);

	// Reaksionet
	Reaks_Stack _reaksionet;
	int _nrk;

protected:
	// Routina te brendshme
	void llogarit_Reaksionet();
	void llogarit_Forcat();
	void llogarit_Moment(Pika &A, Pika &B);
};

