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

double Pika::x() {return _pozita.coeff(0);}
double Pika::y() {return _pozita.coeff(1);}
double Pika::Fx() {return _forcat.coeff(0);}
double Pika::Fy() {return _forcat.coeff(1);}
double Pika::F() {return sqrt(pow(_forcat.coeff(0),2)+pow(_forcat.coeff(1),2));}
double Pika::M() {return _moment;}

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