#include <iostream>

using namespace std;

int main(void)
{
	int num, answer=0;
	cin >> num;
	if (num % 4==0)
	{
		answer = 1;
		if (num % 100 == 0)
		{
			answer = 0;
			if (num % 400 == 0)
			{
				answer = 1;
			}
		}
	}
	cout << answer;
}