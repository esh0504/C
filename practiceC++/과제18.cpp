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
		for (int i = 0; i < num; i++)
		{
			for (int j = 0; j < num; j++)
			{
				if (i <= ((num - 1) / 2))
				{
					if (i > j || i>=num-j)
					{
						cout << "-";
					}
					else if (i % 2 == 0)
					{
						if (j % 2 == 0)
						{
							cout << "*";
						}
						else
						{
							cout << "+"; 
						}
					}
					else if (i % 2 == 1)
					{
						if (j % 2 == 0)
						{
							cout << "+";
						}
						else
						{
							cout << "*";
						}
					}
				}
				
				else
				{
					if (num-1-i>j || num-1-i>=num-j)
					{
						cout << "-";
					}
					else if (i % 2 == 0)
					{
						if (j % 2 == 0)
						{
							cout << "*";
						}
						else if (j % 2 == 1)
						{
							cout << "+";
						}
					}
					else if(i%2==1) 
					{
						if (j % 2 == 0)
						{
							cout << "+";
						}
						else if (j % 2 == 1)
						{
							cout << "*";
						}
					}
				}
			}
			cout << endl;
		}
	}
}