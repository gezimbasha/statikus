#include "Pika.h"
#include "Tra.h"
#include "Reaksion.h"
#include "Solver.h"
#include "Globalet.h"

int main()
{
	Tra AB(9);

	Reaksion A(INKASTRIM); A.pozita(0,0);

	Pika forcat[4];
	forcat[0].pozita(3,0); forcat[0].force(4, 45);
	forcat[1].pozita(6,0); forcat[1].force(3, 90);
	forcat[2].pozita(7.5,0); forcat[2].force(3, 90);
	forcat[3].pozita(9,0); forcat[3].force(3, 180+90);

	AB.forca(forcat, 4);

	cout << AB << endl;

	AB.kontakt(A);
	
	Solver sol;
	sol.zgjidh(AB);
	
	_fund();
	return 0;
}