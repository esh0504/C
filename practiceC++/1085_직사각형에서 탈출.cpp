#include <iostream>
using namespace std;

int main(void)
{
	int x, y, w, z;
	cin >> x >> y >> w >> z;
	int xd, yd;
	if (w - x > x)
	{
		xd = x;
	}
	else
	{
		xd = w - x;
	}
	if (z - y > y)
	{
		yd = y;
	}
	else
	{
		yd = z - y;
	}
	if (xd >= yd)
	{
		cout << yd << endl;
	}
	else
	{
		cout << xd << endl;
	}
	return 0;
}