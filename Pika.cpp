#include "Pika.h"
#include "Funksione.h"


Pika::Pika(void)
{
	_pozita << 0, 0;
	_forcat << 0, 0;
	_moment = 0;
}

Pika::Pika(Vector2d* _pos, Vector2d* _frc)
{
	_pozita << _pos->coeff(0), _pos->coeff(1);
	_forcat << _frc->coeff(0), _frc->coeff(1);
	_moment = 0;
}

Pika::Pika(double _x, double _y, double _X, double _Y)
{
	_pozita << _x, _y;
	_forcat << _X, _Y;
	_moment = 0;
}

Pika::~Pika(void)
{
}

// Qasesit
double Pika::x() const {return _pozita.coeff(0);}
double Pika::y() const {return _pozita.coeff(1);}
double Pika::Fx() const {return _forcat.coeff(0);}
double Pika::Fy() const {return _forcat.coeff(1);}
double Pika::F() const {return sqrt(pow(_forcat.coeff(0),2)+pow(_forcat.coeff(1),2));}
double Pika::M() const {return _moment;}

void Pika::x(double _x) { _pozita(0) = _x; }
void Pika::y(double _y) { _pozita(1) = _y; }
void Pika::Fx(double _X) { _forcat(0) = _X; }
void Pika::Fy(double _Y) { _forcat(1) = _Y; }

void Pika::force(double f, double a)
{
	_forcat << f*cos(deg2rad(a)), f*sin(deg2rad(a));
}

void Pika::moment(double _m)
{
	_moment = _m;
}

// Operatoret
ostream& operator << (ostream &os, Pika& _p)
{
	os << "M(" << _p.x() << "," << _p.y() << ")" << endl;
	os << "M.F(" << _p.Fx() << "," << _p.Fy() << ")" << endl;
	os << "M.M(" << _p.M() << ")" << endl;
	os << "Ft = " << _p.F() << endl;
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