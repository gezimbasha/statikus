#include "Reaksion.h"


Reaksion::Reaksion(void)
{
}

Reaksion::~Reaksion(void)
{
}

Reaksion::Reaksion(double x, double y, reaksion_lloji ll)
{
	_pk.x(x); _pk.y(y);
	m_Lloji = ll;
}