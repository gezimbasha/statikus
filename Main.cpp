#include "Pika.h"
#include "Tra.h"
#include "Reaksion.h"
#include "Globalet.h"

int main()
{
	Tra AB(4);

	Reaksion reaksion; reaksion.pozita(1,0);

	Pika forcat[3];
	forcat[0].pozita(0,0); forcat[0].force(4, 90);
	forcat[1].pozita(1,0); forcat[1].force(3, 45);
	forcat[2].pozita(2,0); forcat[2].force(2, 180+90);

	AB.forca(forcat, 3);

	cout << AB << endl;
			 
	AB.kontakt(reaksion);

	cout << AB << endl;
	
	AB.force(reaksion);

	cout << AB << endl;

	cout << reaksion << endl;

	_fund();
	return 0;
}