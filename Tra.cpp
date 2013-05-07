#include "Tra.h"

Tra::Tra(void)
{
	_tGjatesia = 0;
	_npk = 0;
	_Fx = 0; _Fy = 0; _M = 0;
}

Tra::~Tra(void)
{
}

Tra::Tra(int _gjatesia)
{
	_tGjatesia = _gjatesia;
	_npk = 0;
	_Fx = 0; _Fy = 0; _M = 0;
}

void Tra::force(Pika &pk)
{
	_npk+=1;
	_pikat.reserve(_npk);
	_pikat.push_back(pk);
	Tra::llogarit_Forcat();
}

void Tra::force(double x, double y, double F, double kendi)
{
	_npk+=1;
	Pika temp;
	temp.pozita(x,y); temp.force(F, kendi);
	_pikat.push_back(temp);
	Tra::llogarit_Forcat();
}

void Tra::forca(Pika *pk, int nf)
{
	for(int i=0; i<nf; i++){
		Tra::force(pk[i]);
	}
}

void Tra::L(int _l)
{
	_tGjatesia = _l;
}

void Tra::llogarit_Forcat()
{
	Pika temp = _pikat.at(_npk-1);
	_Fx += temp.Fx();
	_Fy += temp.Fy();
}

// Qasesit
double Tra::Fx() const { return _Fx; }
double Tra::Fy() const { return _Fy; }