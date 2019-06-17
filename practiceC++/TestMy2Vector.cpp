#include <iostream>
#include "My2Vector.h"
using namespace std;

int main(void)
{
	int numTestCases;
	cin >> numTestCases;
	for (int i = 0; i < numTestCases; i++)
	{
		int coordX, coordY;
		cin >> coordX >> coordY;
		My2Vector v1(coordX, coordY);
		cin >> coordX >> coordY;
		My2Vector v2(coordX, coordY);
		cout << v1 << " " << v2 << endl;
		cout <<  v1*2 +  v2*3 << endl;
	}
}