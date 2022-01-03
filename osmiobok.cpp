#include <iostream>
#include <algorithm>
using namespace std;
main ()
{
		int d, space=0, wys;
	cout<<"Podaj dlugosc boku osmiokata: "<<endl;
	cin>>d;
	wys=3*d-2;
	
	for(int i=0; i<wys; ++i)
	{
		for(int j=0; j<d-1-min(i,wys-1-i); ++j)
		{
			cout<<" ";
			++space;
		}
		
		for(int k=0; k<wys-2*space; ++k)
		{
			cout<<"*";
		}
		space=0;
		cout<<endl;
	}
	system("pause");
}
