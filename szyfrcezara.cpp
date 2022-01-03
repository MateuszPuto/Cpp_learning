#include <iostream>
#include <ctime>
using namespace std;

int najdluzszy(int t[], int dlugosc);
int losowe(int max, int min);
void szyfrcezara(char[100], int przesuniecie);
void szyfr(char napis[100], int klucz);

int main()
{
	//losowanie
	srand(time(NULL));
	int max = 10, min = -10;
	const int dlugosc = 10;
	int tab[dlugosc];

	//szyfr
	char tekst[100] = { "Ala ma kota" };
	int przesuniecie = 1;
	int klucz = 0;

	//losowanie
	for (int i = 0; i < dlugosc; ++i)
	{
		tab[i] = losowe(max, min);
	}

	cout << najdluzszy ( tab, dlugosc) << endl;

	//szyfr
	szyfrcezara(tekst, przesuniecie);
	cout << "szyfr 1: " << tekst;

	cout << endl << "szyfr 2: " << endl;
	szyfr(tekst, klucz);
	for (int i = 0; i < 100; ++i)
		cout << tekst[i];
	cout << endl;


	system("pause");
	return 0;
}
//losowanie
int losowe(int max, int min)
{
	return ( rand() % (max + 1 - static_cast<unsigned int>(min)) ) + min;
}

int najdluzszy(int t[], int dlugosc)
{
	int dl = 0, poprzednia = -11;
	for (int i = 0; i < dlugosc; ++i)
	{
		if (t[i] > poprzednia)
			++dl;
		poprzednia = t[i];
	}
	return dl;
}

//szyfr
void szyfrcezara(char napis[100], int przesuniecie)
{
	int i, zm, szyfr[100];
	for (int i = 0; szyfr[i] = napis[i]; i++)
	{
		int zm = napis[i] + przesuniecie;

		if (zm == ' ')
		{

		}
		else if(zm < 'A' && zm > 'Z')
		{
			zm = zm - 'Z' + 'A' - 1;
		}
		else if (zm < 'a' && zm > 'z')
		{
			zm = zm - 'z' + 'a' - 1;
		}
		napis[i] = zm;
	}
}

void szyfr(char napis[100], int klucz)
{
	for (int i = 0; napis[i]; ++i)
	{
		if(napis[i] != ' ')
		napis[i] = napis[i] ^ klucz;
	}

}