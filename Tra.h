#pragma once

#include "Pika.h"
#include <vector>

typedef vector<Pika> Pika_Stack;

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

	// Deklarimet
	double L() const;
	double Fx() const;
	double Fy() const;
	double M() const;
	unsigned int _madhesia() const;

	void L(int L);

	// Operatoret
	friend ostream& operator << (ostream&, Tra &);

protected:
	// Routina te brendshme
	void llogarit_Forcat();
	void llogarit_Moment(Pika &A, Pika &B);
};

