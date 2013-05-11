#include "Tra.h"

Tra::Tra(void)
{
	_tGjatesia = 0;
	_npk = 0; _nrk = 0;
	_Fx = 0; _Fy = 0; _M = 0;
}

Tra::~Tra(void)
{
}

Tra::Tra(int _gjatesia)
{
	_tGjatesia = _gjatesia;
	_npk = 0; _nrk = 0;
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
	_M += temp.M();
}

void Tra::llogarit_Moment(Pika &A, Pika &B)
{
	_M += A.moment(B);
}

void Tra::llogarit_Momentet(Pika &pk)
{
	_M = 0;
	for(unsigned i=0; i<_pikat.size(); i++)
		Tra::llogarit_Moment(pk, _pikat.at(i));
	for(unsigned i=0; i<_reaksionet.size(); i++)
		Tra::llogarit_Moment(pk, _reaksionet.at(i));
}

void Tra::kontakt(Reaksion &pk)
{
	_nrk += 1;
	_reaksionet.reserve(_nrk);
	_reaksionet.push_back(pk);
}

// Qasesit
double Tra::Fx() const { return _Fx; }
double Tra::Fy() const { return _Fy; }
double Tra::M() const { return _M; }
double Tra::Rx() const { return _Rx; }
double Tra::Ry() const { return _Ry; }
double Tra::Rm() const { return _Rm; }
unsigned int Tra::_madhesia() const { return _pikat.capacity(); }

bool Tra::ekuiliber()
{
	if( (_Rx + _Fx) == 0 )
		if( (_Ry + _Fy) == 0)
			if( (_Rm + _M) == 0)
				return true;

	if( _Fx == 0 && _Fy == 0 && _M == 0 )
		return true;

	return false;
}

// Operatoret
ostream& operator << (ostream& os, Tra &t)
{
	os << "Fx = " << t.Fx() << " [kN]" << endl;
	os << "Fy = " << t.Fy() << " [kN]"<< endl;
	os << "M  = " << t.M() <<  " [kN m]"<< endl;
	if(t.ekuiliber()) os << "Trari eshte ne ekuiliber" << endl;
	else os << "Trari nuk eshte ne ekuiliber" << endl;

	return os;
}