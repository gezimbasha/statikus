#include "Pika.h"
#include "Globalet.h"

int main()
{
	Pika p1(1.5,1,0,2);
	p1.moment(3.5);

	cout << "P1" << endl;
	cout << p1 << endl;
	
	cout << endl << endl;

	Pika p2;
	p2 -= p1;

	cout << "P2" << endl;
	cout << p2 << endl;

	cout << endl;
	cout << "---------------------------------------------------" << endl;
	cout << setw(50) << TITULLI;
	cin.ignore();
	return 0;
}