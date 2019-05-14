#include <iostream>
using namespace std;

int pan(int a, int b, int c)
{
	if (c >= a + b)
	{
		return 0;
	}
	if (a == b)
	{
		if (b == c)
		{
			return 1;
		}
		else
		{
			return 3;
		}
	}
	else if (b == c)
	{
		return 3;
	}
	else if (b*b + a * a == c * c)
	{
		return 2;
	}
	else {
		return 4;
	}
}
int main(void)
{
	int testCase;
	cin >> testCase;
	for (int test = 0; test < testCase; test++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		cout << pan(a, b, c) << endl;
	}
}