#include <iostream>
using namespace std;

int main(void)
{
	int testCase;
	cin >> testCase;
	for (int test = 0; test < testCase; test++)
	{
		int num;
		cin >> num;
		int mid = (num - 1) / 2;
		for (int i = 0; i < num; i++)
		{
			for (int j = 0; j < num; j++)
			{
				if (i == mid)
				{
					cout << "+";
				}
				else if (i < mid)
				{
					if (mid-i>j || mid+i<j)
					{
						cout << "*";
					}
					else
					{
						cout << "+";
					}
				}
				else
				{
					if (i - mid <= j && j<num-i+mid )
					{
						cout << "+";
					}
					else
					{
						cout << "*";
					}
				}
			}cout << endl;
		}
	}
}