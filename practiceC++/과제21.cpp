#include<iostream>
#include <string>

using namespace std;

int main(void)
{
	int testCase;
	cin >> testCase;
	for (int i = 0; i < testCase; i++)
	{
		int number;
		cin >> number;
		int cnt = 0;
		int number_second[32] = { 0 };
		int count = 31;
		while (number !=0)
		{
			if (number % 2 == 0)
			{
				number_second[count] =0;
			}
			else
			{
				number_second[count] = 1;
			}
			number /= 2;
			count--;
		}
		for (int p = 0; p < 32; p++)
		{
			if (number_second[p] == 1)
			{
				cnt += 1;
			}
		}
		if (cnt % 2 == 0)
		{
			number_second[0] = 0;
		}
		else
		{
			number_second[0] = 1;
		}
		unsigned int sum = 0;
		int multi = 1;
		for (int jk = 31; jk >= 0; jk--)
		{
			if (number_second[jk] == 1)
			{
				sum += multi;
			}
			multi *= 2;
		}
		
		cout << sum << endl;
		
		
	}
	return 0;
}