#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <iomanip>
using namespace std;

void pi(int ile_razy);

int main()
{
	int ile;
	cout << "Podaj ilosc punktow do obliczenia liczby pi: " << endl;
	cin >> ile;
	pi(ile);
}

void pi(int ile_razy)
{
	double x, y, kolo = 0;
	
	srand(time(NULL));
	
	for(int i = 0; i < ile_razy; i++)
	{
		x = static_cast<double>(rand()) / RAND_MAX * 2 - 1;
		y = static_cast<double>(rand()) / RAND_MAX * 2 - 1;
		
		if(x*x + y*y <= 1) 
		{
			kolo++;
		}
	}
	
	cout << "Liczba pi wynosi okolo: " << setprecision(20) << 4 * kolo / ile_razy << endl;
}
