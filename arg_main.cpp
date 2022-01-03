#include <iostream>
using namespace std;
int main(int a, char * b[])
{
	double suma = 0;
	for (int i = 1; i < a; ++i)
	{
		suma += atof(b[i]);
	}
	cout << suma << endl;
}