#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	int x[3];
	int xd;
	int y[3];
	int yd;
	for (int i = 0; i < 3; i++)
	{
		int x1, y1;
		cin >> x1 >> y1;
		x[i] = x1;
		y[i] = y1;
	}
	sort(x, x + 3);
	sort(y, y + 3);
	if (x[0] != x[1])
	{
		xd = x[0];
	}
	else
	{
		xd = x[2];
	}
	if (y[0] != y[1])
	{
		yd = y[0];
	}
	else {
		yd = y[2];
	}
	cout << xd << " " << yd << endl;
	return 0;
}