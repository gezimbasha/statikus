#include "Pika.h"
#ifndef _FUNKSIONET_H
#include "Funksione.h"
#endif

bool PIKA_MOMENT_DEBUG = false;

Pika::Pika(void)
{
	_pozita[0] = 0;
	_pozita[1] = 0;
	_forcat[0] = 0;
	_forcat[1] = 0;
	_moment = 0;
}

Pika::Pika(const Vector2d& _pos, const Vector2d& _frc)
{
	_pozita[0] =_pos.coeff(0);
	_pozita[1] =_pos.coeff(1);
	_forcat[0] =_frc.coeff(0);
	_forcat[1] =_frc.coeff(1);
	_moment = 0;
}

Pika::Pika(double _x, double _y, double _X, double _Y)
{
	_pozita[0] = _x;
	_pozita[1] = _y;
	_forcat[0] = _X;
	_forcat[1] = _Y;
	_moment = 0;
}

Pika::~Pika(void)
{
}

// Qasesit
double Pika::x() const {return _pozita[0];}
double Pika::y() const {return _pozita[1];}
double Pika::Fx() const {return _forcat[0];}
double Pika::Fy() const {return _forcat[1];}
double Pika::F() const {return sqrt(pow(_forcat[0],2)+pow(_forcat[0],2));}
double Pika::M() const {return _moment;}
string Pika::emri() const {return _emri;}

void Pika::x(double _x) { _pozita[0] = _x; }
void Pika::y(double _y) { _pozita[1] = _y; }
void Pika::Fx(double _X) { _forcat[0] = _X; }
void Pika::Fy(double _Y) { _forcat[1] = _Y; }
void Pika::emri(string _e) { _emri = _e; }

void Pika::pozita(double x, double y)
{
	_pozita[0] = x;
	_pozita[1] = y;
}

void Pika::force(double f, double a)
{
	_forcat[0] = f*cos(deg2rad(a));
	_forcat[1] = f*sin(deg2rad(a));
}

void Pika::moment(double _m)
{
	_moment = _m;
}

string ifEmri(const string p)
{
	if(p != "\0")
		return p;
	else
		return "";
}

// Operatoret
ostream& operator << (ostream &os, Pika& _p)
{
	os  <<  ifEmri(_p.emri()) << "(" << _p.x() << "," << _p.y() << ")" << endl;
	if(_absZero(_p.Fx())!=0)
		os << "X" <<  ifEmri(_p.emri()) << " = " << _p.Fx() << endl;
	if(_absZero(_p.Fy())!=0)
		os << "Y" << ifEmri(_p.emri()) << " = " << _p.Fy() << endl;
	if(_absZero(_p.M())!=0)
		os << "M" << ifEmri(_p.emri()) << " = " << _p.M() << endl;

	return os;
}


Pika& Pika::operator=(const Pika &rhs)
{
	if(this != &rhs)
	{
		this->x(rhs.x());
		this->y(rhs.y());
		this->Fx(rhs.Fx());
		this->Fy(rhs.Fy());
		this->moment(rhs.M());
	}

	return *this;
}

Pika& Pika::operator+=(const Pika &rhs)
{
	this->x(this->x()+rhs.x());
	this->y(this->y()+rhs.y());
	this->Fx(this->Fx()+rhs.Fx());
	this->Fy(this->Fy()+rhs.Fy());
	this->moment(this->M()+rhs.M());

	return *this;
}

Pika& Pika::operator-=(const Pika &rhs)
{
	this->x(this->x()-rhs.x());
	this->y(this->y()-rhs.y());
	this->Fx(this->Fx()-rhs.Fx());
	this->Fy(this->Fy()-rhs.Fy());
	this->moment(this->M()-rhs.M());

	return *this;
}

const Pika Pika::operator+(const Pika& rhs) const
{
	return Pika(*this) += rhs;
}

const Pika Pika::operator-(const Pika& rhs) const
{
	return Pika(*this) -= rhs;
}

bool Pika::operator==(const Pika& rhs) const
{
	if(this->x() == rhs.x())
		if(this->y() == rhs.y())
			if(this->Fx() == rhs.Fx())
				if(this->Fy() == rhs.Fy())
					if(this->M() == rhs.M())
						return true;
	return false;
}

bool Pika::operator!=(const Pika& rhs) const
{
	return !(*this == rhs);
}

// Funksionet
double Pika::krahu_x(const Pika& rhs) const
{
	return (rhs.x()-this->x());
}

double Pika::krahu_y(const Pika& rhs) const
{
	return (rhs.y()-this->y());
}

double Pika::moment(const Pika& rhs) const
{
	double rez = 0;
	rez -= (rhs.Fx() * this->krahu_y(rhs));
	if(PIKA_MOMENT_DEBUG) cout << rhs.Fx() << "*" << this->krahu_y(rhs) << "=" << (rhs.Fx() * this->krahu_y(rhs)) << endl;
	rez += (rhs.Fy() * this->krahu_x(rhs));
	if(PIKA_MOMENT_DEBUG) cout << rhs.Fy() << "*" << this->krahu_x(rhs) << "=" << (rhs.Fy() * this->krahu_x(rhs)) << endl;
	rez += (rhs.M());

	return rez;
}

void Pika::ngarkese(double q, double L, ngarkese_lloj _LL)
{
	double _Faccum = 0;
	switch(_LL)
	{
	case KATRORE:
		_Faccum = q*L;
		Pika::pozita(Pika::x()+L/2, Pika::y());
		Pika::force(_Faccum, 90);
		break;
	case TREKENDESH_P:
		_Faccum = 0.5*q*L;
		Pika::pozita(Pika::x()+(2/3.)*L, Pika::y());
		Pika::force(_Faccum, 90);
		break;
	case TREKENDESH_M:
		_Faccum = 0.5*q*L;
		Pika::pozita(Pika::x()+(1/3.)*L, Pika::y());
		Pika::force(_Faccum, 90);
		break;
	}
}

double Pika::krahu(const Pika &pk, int i) const
{
	if(i == 0)
		return Pika::krahu_y(pk);
	else
		return Pika::krahu_x(pk);
}