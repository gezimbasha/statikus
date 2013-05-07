#pragma once

#include "Pika.h"
#include "Reaksion.h"
#include "Tra.h"

#include <Eigen\Eigen\Dense>
using namespace Eigen;

class Solver
{	
public:
	Solver(void);
	virtual ~Solver(void);

	void zgjidh(Tra _tr);
};

