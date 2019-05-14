#include <iostream>

using namespace std;

int main(void)
{
	int testCase;
	cin >> testCase;
	for (int i = 0; i<testCase; i++)
	{
		int year, month, day;
		int date = 0;
		cin >> year >> month >> day;
		for (int j = 1; j<month; j++)
		{
			if (j == 1 or j == 3 or j == 5 or j == 7 or j == 8 or j == 10)
			{
				date += 31;
			}
			else if (j == 2) {
				if (year % 4 == 0)
				{
					if (year % 100 == 0)
					{
						if (year % 400 == 0)
						{
							date += 29;
							continue;
						}
						date += 28;
						continue;
					}
					date += 29;
					continue;
				}
				date += 28;
			}
			else
			{
				date += 30;
			}
		}
		date += day;
		cout << date << endl;
	}
}