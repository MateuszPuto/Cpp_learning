#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

double praw(int ile);
double urodziny();

int main()
{
	srand(time(NULL));
	cout << "Wynik: " << praw(100) << endl;
	cout << urodziny() << endl;
	system("pause");
}

double praw(int ile)
{
	int add = 0;
	double  kat1, kat2, x1, x2, y1, y2, dl, cmp;
	cmp = sqrt(3);

	for (int i = 0; i < ile; ++i)
	{
		kat1 = 2.0*3.14*rand() / RAND_MAX;
		kat2 = 2.0*3.14*rand() / RAND_MAX;
		cout << kat1 << endl;
		x1 = cos(kat1);
		x2 = cos(kat2);
		y1 = sin(kat1);
		y2 = sin(kat2);
		dl = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

		if (dl > cmp)
			add++;
	}

	return 1.0 * add / ile;
}

double urodziny()
{
	const int osob = 180;
	int tab[12 * osob], spr[12 * osob], ile=0;

	for (int i = 0; i < 12 * osob; ++i)
	{
		spr[i] = 0;
	}

	//losowanie
	for (int i = 0; i < 12; ++i)
	{
		for (int j = 0; j < osob; ++j)
		{
			tab[i*osob + j] = (rand() / 31) + 1;
		}
	}

	//sprawdzanie
	for (int i = 0; i < 12 * osob; ++i)
	{
		spr[tab[i]]++;
	}
	for (int i = 0; i < 12 * osob; ++i)
	{
		if (spr[i] > 1)
			ile++;
	}

	return ile / osob;
}

