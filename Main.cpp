#include "Pika.h"
#include "Globalet.h"

int main()
{
	Pika p1(1.5,1,0,2);
	p1.moment(3.5);

	Pika p2;
	p2 = p1;
	p2 += p1;

	Pika p3;
	p3 = p2+p1;

	cout << (p1 == p2) << endl;
	cout << (p2 == p3) << endl;
	cout << ((p2+p1)==p3) << endl;

	cout << endl;
	cout << "---------------------------------------------------" << endl;
	cout << setw(50) << TITULLI;
	cin.ignore();
	return 0;
}