#include <iostream>
#include <math.h>
using namespace std;

int pan(int x1, int y1, int x2, int y2, int x3, int y3)
{
	double l1 = (x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1);
	double l2 = (x3 - x2)*(x3 - x2) + (y3 - y2)*(y3 - y2);
	double l3 = (x1 - x3)*(x1 - x3) + (y1 - y3) * (y1 - y3);
	double l4 = sqrt(l1);
	double l5 = sqrt(l2);
	double l6 = sqrt(l3);
	
	if (l1 > l2 && l1 > l3)
	{
		if (l4 >= l5 + l6)
		{
			return 0;
		}
		if (l1 == l2 + l3)
		{
			return 1;
		}
		else if (l1 < l2 + l3)
		{
			return 3;
		}
		else if (l1 > l2 + l3)
		{
			return 2;
		}
	}
	else if (l2 > l1 &&l2 > l3)
	{
		if (l5 >= l4 + l6)
		{
			return 0;
		}
		if (l2 == l1 + l3)
		{
			return 1;
		}
		else if (l2 > l1 + l3)
		{
			return 2;
		}
		else if (l2 < l1 + l3)
		{
			return 3;
		}
	}
	else if (l3>l1 &&l3>l2)
	{
		if (l6 >= l4 + l5) {
			return 0;
		}
		if (l3 == l1 + l2)
		{
			return 1;
		}
		else if (l3 < l1 + l2)
		{
			return 3;
		}
		else if (l3 > l1 + l2)
		{
			return 2;
		}
	}
	return 0;
}
int main(void)
{
	int testCase;
	cin >> testCase;
	for (int test = 0; test < testCase; test++)
	{
		int x1, y1, x2, y2, x3, y3;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		cout << pan(x1, y1, x2, y2, x3, y3) << endl;
	}
}