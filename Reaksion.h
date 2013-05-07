#pragma once

#include "Pika.h"

enum reaksion_lloji
{
	PALEVIZSHEM,
	LEVIZSHEM,
	INKASTRIM
};

class Reaksion : public Pika
{	
	Pika _pk;
	reaksion_lloji m_Lloji;
public:
	Reaksion(void);
	Reaksion(double x, double y, reaksion_lloji);
	virtual ~Reaksion(void);

	void lloji(reaksion_lloji);
	reaksion_lloji lloji() const;
};