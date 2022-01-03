#include <iostream>
using namespace std;

int ** stworz(int n, int m);
void wypelnij(int ** tab, int n, int m);
void wypisz(int ** tab, int n, int m);
void usun(int ** tab, int n, int m);
int * kolumna(int ** tab, int n, int m);
char * pierwszeLitery(char * tekst);

int main()
{
	int** tablica;
	int n, m;
	char * tekst = { "Ala ma kota" };
	cout << "Wprowadz wysokosc: ";
	cin >> n;
	cout << endl;
	cout << "Wprowadz dlugosc: ";
	cin >> m;
	cout << endl;
	tablica = stworz(n, m);
	wypelnij(tablica, n, m);
	wypisz(tablica, n, m);
	usun(tablica, n, m);
	cout << pierwszeLitery(tekst);
	system("pause");
}

int ** stworz(int n, int m)
{
	int **wsk = new int *[n];
	for (int i = 0; i < m; ++i)
	{
		*(wsk + i) = new int[m];
	}
	return wsk;
}

void wypelnij(int ** tab, int n, int m)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
			tab[i][j] = i + j;
	}

}

void wypisz(int ** tab, int n, int m)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout << tab[i][j] << " ";
		}
		cout << endl;
	}
	
}

void usun(int ** tab, int n, int m)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			delete[] tab[j];
		}
	}
	delete[] tab;
}

int * kolumna(int ** tab, int n, int m)
{
	int suma = 0, max  = 0, k;
	int * kolumna = &tab[0][0];
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
			suma += tab[n][m];

		if (suma > max)
		{
			max = suma;
			kolumna = &tab[0][i];
			k = i;
		}
	}


		for (int j = 0; j < n; ++j)
		{
			cout << tab[j][k] << endl;
		}

	return kolumna;
}

char * pierwszeLitery(char * tekst)
{
	int i = 0, ileSpacji = 2, n = 1;
	while (tekst[i])
	{
		if (tekst[i] == ' ')
		{
			ileSpacji++;
		}
		++i;
	}

	char * wynik = new char[ileSpacji];

	wynik[0] = tekst[0];

	for (int j = 0; j < i; ++j)
	{
		if (tekst[j] == ' ')
		{
			wynik[n] = tekst[j + 1];
			n++;
		}
	}

	return wynik;
}