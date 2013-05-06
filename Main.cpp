#include "Pika.h"
#include "Globalet.h"

int main()
{
	Pika p1;
	Pika p2;
	p1.pozita(0,0);
	p2.pozita(-4,2);

	p2.force(4, 360-30);

	cout << p1.moment(p2) << endl;

	cout << endl;
	cout << "---------------------------------------------------" << endl;
	cout << setw(50) << TITULLI;
	cout << endl;
	system("pause");
	return 0;
}