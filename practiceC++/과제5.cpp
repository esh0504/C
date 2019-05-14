#include <iostream>
using namespace std;
int isLeapYear(int year);
int main(void)
{
	int t;
	int year;
	cin >> t;
	for (int i = 0; i<t; i++)
	{
		cin >> year;
		cout << isLeapYear(year) << endl;
	}
	return 0;
}
int isLeapYear(int year)
{
	if (year % 4 == 0)
	{
		if (year % 100 == 0)
		{
			if (year % 400 == 0)
			{
				return 1;
			}
			return 0;
		}
		return 1;
	}
	return 0;
}