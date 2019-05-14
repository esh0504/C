#include <iostream>
#include<algorithm>
#include <cmath>
using namespace std;

int main(void)
{
	int num = 0;
	int answer = 1;
	int haming[7410];
	for (int i = 0; i < 13; i++)
	{
		answer = 1;
		int num5 = pow(5, i);
		answer *= num5;
		if (answer > 1000000000)
		{
			break;
		}
		else if (answer < 0)
		{
			break;
		}
		for (int j = 0; j < 19; j++)
		{
			answer = 1;
			int num3 = pow(3, j);
			answer *= num3 * num5;
			if (answer > 1000000000)
			{
				break;
			}
			else if (answer < 0)
			{
				break;
			}
			for (int k = 0; k < 30; k++)
			{
				answer = 1;
				int num2 = pow(2, k);
				answer = num2 * num3*num5;
				if (answer > 1000000000)
				{
					break;
				}
				else if (answer < 0)
				{
					break;
				}
				else  {
					haming[num] = answer;
					num++;
				}
			}
		}
	}
	sort(haming, haming + 7410);
	int haming_copy[7410];
	num = 0;
	for (int i = 5879; i < 7409; i++)
	{
		if (haming[i] == haming[i + 1])
		{
			continue;
		}
		else {
			haming_copy[num] = haming[i];
			num++;
		}
	}
	int test ;
	cin >> test;
	for (int i = 0; i < test; i++)
	{
		int num;
		cin >> num;
		cout << haming_copy[num] << endl;
	}
}