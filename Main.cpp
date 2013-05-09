#include "Pika.h"
#include "Tra.h"
#include "Reaksion.h"
#include "Solver.h"
#include "Globalet.h"

// Vlerat e dhëna
double F1=4; double F2=3; double F3=3; double alfa=45.00; double q=1;

int main()
{
	Tra AB(10);

	Reaksion A(PALEVIZSHEM); A.pozita(0,0);
	Reaksion B(LEVIZSHEM); B.pozita(10,0);

	Pika forcat[1];
	forcat[0].pozita(4,0); forcat[0].force(6,90);

	AB.forca(forcat, 1);
	AB.llogarit_Momentet(A);

	cout << AB << endl;

	AB.kontakt(A);
	AB.kontakt(B);
	
	Solver sol;
	sol.zgjidh(AB);

	cout << DBL_MIN << endl;
	
	_fund();
	return 0;
}