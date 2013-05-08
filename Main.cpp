#include "Pika.h"
#include "Tra.h"
#include "Reaksion.h"
#include "Solver.h"
#include "Globalet.h"

// Vlerat e dhëna
double F1=4; double F2=3; double F3=3; double alfa=45.00; double q=1;

int main()
{
	Tra AB(9);

	Reaksion A(PALEVIZSHEM); A.pozita(3,0);
	Reaksion B(LEVIZSHEM); B.pozita(7,0);

	Pika forcat[4];
	forcat[0].pozita(0,0); forcat[0].force(F1, 180+90);
	forcat[1].pozita(0,0); forcat[1].ngarkese(q, 3, TREKENDESH_M);
	forcat[2].pozita(5,0); forcat[2].force(F2, alfa);
	forcat[3].pozita(9,0); forcat[3].force(F3, 90);

	AB.forca(forcat, 4);
	AB.llogarit_Momentet(A);

	cout << AB << endl;

	AB.kontakt(A);
	AB.kontakt(B);
	
	Solver sol;
	sol.zgjidh(AB);
	
	_fund();
	return 0;
}