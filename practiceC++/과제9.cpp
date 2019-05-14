#include <iostream>
using namespace std;

int yoill(int year)
{
	int date = 0;
	for (int h = 1; h < year; h++)
	{
		if (h % 4 == 0)
		{
			if (h % 100 == 0)
			{
				if (h % 400 == 0)
				{
					date+=366;
					continue;
				}
				date+=365;
				continue;
			}
			date+=366;
			continue;
		}
		date+=365;
		continue;
		
	}
	date += 1;
	return date % 7;
}

int main(void)
{
	int testCase;
	cin >> testCase;
	for (int i = 0; i < testCase; i++)
	{
		int year;
		cin >> year;
		int answer = yoill(year);
		cout << answer << endl;
	}
}