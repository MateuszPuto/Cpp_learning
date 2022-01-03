#include <iostream>
using namespace std;

void pieciokat(int dl);

int main()
{
	int dl_boku;
	cout << "Podaj dlugosc boku: ";
	cin >> dl_boku;
	cout << endl;
	pieciokat(dl_boku);

	system("pause");
}

void pieciokat(int dl)
{
	int s = 3 * dl / 2 - 1;

	int g = 1;
	for (int i = 0; i < dl; i++)
	{
		for (int j = 0; j < s; j++)
		{
			cout << " ";
		}
		for (int k = 0; k < g; k++)
		{
			cout << "*";
		}
		cout << "\n";
		g += 2;
		s--;
	}
	s = 1;
	g = 3 * dl - 4;
	for (int i = 0; i < dl - 1; i++)
	{
		for (int j = 0; j < s; j++)
		{
			cout << " ";
		}
		for (int k = 0; k < g; k++)
		{
			cout << "*";
		}
		cout << endl;
		s++;
		g -= 2;
	}
}