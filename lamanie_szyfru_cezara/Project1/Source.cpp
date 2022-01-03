#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <stdlib.h>
using namespace std;

double* wczytywaniezpliku();
double * szyfruj(double *);
int rozszyfruj(double * tablica, double *prob);

int main()
{
	double *wsk;
	int kod;
	double enProb[26] = { 8.167, 1.492, 2.782, 4.253, 12.702, 2.228, 2.015, 6.094, 6.966, 0.153, 0.772, 4.025, 2.406, 6.749, 7.507, 1.929,
		0.095, 5.987, 6.327, 9.056, 2.758, 0.978, 2.360, 0.150, 1.974, 0.074 };
	srand(time(NULL));


	wsk = wczytywaniezpliku();
	wsk = szyfruj(wsk);
	kod = rozszyfruj(wsk, enProb);
	cout <<"Kod: " << kod << endl;

	system("pause");
}

double* wczytywaniezpliku()
{
	// odczyt z pliku, out: tablica ilosci wystapien liter
	string linia;
	double static litery[26];
	int ascii[127];
	ifstream plik("infile.txt");
	for (int i = 0; i < 127; ++i)
		ascii[i] = 0;
	while (getline(plik, linia))
	{
		for (int i = 0; i < linia.size(); ++i)
		{
			ascii[static_cast<int>(linia.at(i))]++;
		}


	}
	for (int i = 65; i < 91; ++i)
		litery[i - 65] = ascii[i];
	for (int i = 97; i < 123; ++i)
		litery[i - 97] = ascii[i];
	for (int i = 0; i < 26; ++i)
		cout << static_cast<char>(i + 97) << " " << litery[i] << endl;
	plik.close();
	return litery;
}

double * szyfruj(double * tablica)
{
	// szyfr cezara o losowe przesuniecie na zagregowanych literach z pliku, cout: przesuniecie, in: tablica do przesuniecia
	//out: tablica  przesunieta o przesuniecie
	int zmienna = rand() % 26, temp[26];
	for (int i = 0; i < 26; ++i)
		temp[i] = tablica[i];
	for (int i = 0; i < 26; ++i)
	{
		tablica[((i + zmienna) % 26)] = temp[i];
	}
	cout <<"Przesuniecie: " << zmienna << endl;
	return tablica;
}

int rozszyfruj(double * tablica, double * prob)
{
	// lamanie przesuniecia w szyfrze cezara,in: zaszyfrowana tablica, in: tablica prawdopodobienstwa wystepowania liter, out: przesuniecie
	double wynik[26], min = 0, kod = 0, suma = 0;
	

	for (int i = 0; i < 26; ++i)
	{
		wynik[i] = 0;
		suma += tablica[i];
	}
	for (int i = 0; i < 26; ++i)
	{
		tablica[i] = tablica[i] / suma;
		cout << tablica[i] << endl;
	}

	for (int i = 0; i < 26; ++i)
	{
		for (int j = 0; j < 26; ++j)
		{
			wynik[i] += abs( tablica[(j + i)%26] - prob[j] );
		}

	}

	min = wynik[0];
	for (int i = 0; i < 26; ++i)
	{
	//	cout << wynik[i] << endl;
	
		if (wynik[i] < min)
		{
			min = wynik[i];
			kod = i;
		}
	}
	return kod;
}
