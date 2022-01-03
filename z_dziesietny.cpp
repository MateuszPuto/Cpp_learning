#include <iostream>
using namespace std;
#define liczba 213;

void nadwa(unsigned short a);
void nacztery(unsigned short a);
void naosiem(unsigned int a);
void nahex(unsigned short a);

int main()
{
	unsigned short a = liczba;
	unsigned int b = liczba;
	cout << "w systemie dwojkowym: ";
	nadwa(a);
	cout << endl;
	cout << "w systemie czworkowym: ";
	nacztery(a);
	cout << endl;
	cout << "w systemie osemkowym: ";
	naosiem(b);
	cout << endl;
	cout << "w systemie szesnastkowym: ";
	nahex(a);
	cout << endl;
	system("pause");
}

void nadwa(unsigned short a)
{
	unsigned short b = 0x8000;

	for (int i = 0; i < 16; ++i)
	{
		cout << (a&b ? 1:0);
		a = a << 1;	
	}
	cout << endl;
}

void nacztery(unsigned short a)
{
	unsigned short b = 0xc000;
	unsigned short c;
	for (int i = 0; i < 8; ++i)
	{
		c = ((a&b)>>14);
		cout << c;
		a = a << 2;
	}
	cout << endl;
}

void naosiem(unsigned int a)
{
	unsigned int b = 0x00038000;
	unsigned int c;
	for (int i = 0; i < 6; ++i)
	{
		c = ((a&b) >> 15);
		cout << c;
		a = a << 3;
	}
	cout << endl;
}

void nahex(unsigned short a)
{
	unsigned short b = 0xf000;
	unsigned short c;
	for (int i = 0; i < 4; ++i)
	{
		c = ((a&b) >> 12);
		cout <<hex<< c;
		a = a << 4;
	}
	cout << endl;
}

