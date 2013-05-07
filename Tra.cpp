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
}

void Tra::force(double x, double y, double F, double kendi)
{
	_npk+=1;
	Pika temp;
	temp.pozita(x,y); temp.force(F, kendi);
	_pikat.push_back(temp);
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