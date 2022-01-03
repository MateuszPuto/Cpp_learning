#include <iostream>
using namespace std;

struct wielomian {
	int stopien;
	double* tab;
	void wpisz();
	void wypisz();
};

void wielomian::wpisz()
{
	cout << "Podaj stopien: ";
	cin >> stopien;
	tab = new double[stopien + 1];

	for (int i = 0; i < stopien + 1; ++i)
	{
		cout << "Podaj wspolczynnik przy wyrazie stopnia " << i << ": ";
		cin >> tab[i];
	}
}

void wielomian::wypisz()
{
	for (int i = 0; i < stopien + 1; ++i)
	{
		cout << tab[i] << "x^" << i << " + ";
	}
	cout << endl;
}

wielomian dodaj(wielomian &a, wielomian &b)
{
	wielomian wynik;
	(a.stopien > b.stopien ? wynik.stopien = a.stopien : wynik.stopien = b.stopien);
		wynik.tab = new double[wynik.stopien];

		for(int i = 0; i < wynik.stopien; ++i)
		{
			//nie mozna tak dodawac
			wynik.tab[i] = a.tab[i] + b.tab[i];
		}
	return wynik;
}

int main()
{
	wielomian a, b, c;
	a.wpisz();
	a.wypisz();
	b.wpisz();
	b.wypisz();
	c = dodaj(a, b);
	c.wypisz();

	system("pause");
}