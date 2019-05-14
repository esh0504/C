#include <iostream>
using namespace std;
int lengthOfIntervalIntersection(int a, int b, int c, int d);
int main(void)
{
	int t;
	int h, m,a,b,c,d;
	cin >> t;
	for (int i = 0; i<t; i++)
	{
		cin >> a >> b >> c >> d;
		cout << lengthOfIntervalIntersection(a, b, c, d) << endl;
	}
	return 0;
}
int lengthOfIntervalIntersection(int a, int b, int c, int d)
{
	if (a >= c&&a<=d)
	{
		if (b <= d)
		{
			return b - a;
		}
		else
		{
			return d - a;
		}
	}
	else if (c >= a && c <= b)
	{
		if (d <= b)
		{
			return d - c;
		}
		else
		{
			return b - c;
		}
	}
	else {
		return -1;
	}
}