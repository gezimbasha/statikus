#include "Reaksion.h"


Reaksion::Reaksion(void)
{
	m_Lloji = LIRE;
	reaksionet(m_Lloji);
}

Reaksion::~Reaksion(void)
{
}

Reaksion::Reaksion(reaksion_lloji ll)
{
	m_Lloji = ll;
	reaksionet(m_Lloji);
}

void Reaksion::reaksionet(reaksion_lloji _r)
{
	if(_r == LIRE){
		R[0]=false;
		R[1]=false;
		R[2]=false;
	}

	if(_r == LEVIZSHEM){
		R[0]=false;
		R[1]=true;
		R[2]=false;
	}

	if(_r == PALEVIZSHEM){
		R[0]=true;
		R[1]=true;
		R[2]=false;
	}

	if(_r == GERBER){
		R[0]=false;
		R[1]=false;
		R[2]=true;
	}

	if(_r == INKASTRIM){
		R[0]=true;
		R[1]=true;
		R[2]=true;
	}
}

reaksion_lloji Reaksion::lloji() const 
{
	return m_Lloji;
}

void Reaksion::lloji(reaksion_lloji ll)
{
	
	m_Lloji = ll;
	reaksionet(m_Lloji);
}