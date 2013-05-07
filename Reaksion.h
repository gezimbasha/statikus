#pragma once

#include "Pika.h"

enum reaksion_lloji
{
	LIRE,
	PALEVIZSHEM,
	LEVIZSHEM,
	INKASTRIM
};

class Reaksion : public Pika
{
	reaksion_lloji m_Lloji;

public:
	Reaksion(void);
	Reaksion(reaksion_lloji);
	virtual ~Reaksion(void);

	void lloji(reaksion_lloji);
	reaksion_lloji lloji() const;
	bool R[3];

private:
	void reaksionet(reaksion_lloji);
};