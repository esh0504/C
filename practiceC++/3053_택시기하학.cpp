#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES
#define M_PI       3.14159265358979323846


using namespace std;

double taxi(int r)
{
	return r * r * 2;
}
double circle(int r)
{
	return r * r*M_PI;
}
int main(void)
{
	cout.precision(6);
	int r;
	cin >> r;
	cout << fixed;
	cout << circle(r) << endl << taxi(r) << endl;
}