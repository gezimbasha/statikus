#include "Pika.h"
#include "Globalet.h"

int main()
{
	Pika p1;
	Pika p2;
	p1.pozita(0,0);
	p2.pozita(-3,0);

	p2.force(4, 90);

	cout << p1.moment(p2) << endl;

	cout << endl;
	cout << "---------------------------------------------------" << endl;
	cout << setw(50) << TITULLI;
	cout << endl;
	system("pause");
	return 0;
}