#include <iostream>

using namespace std;
int min(int a, int b)
{
	return a > b ? b : a;
}
int countZero(int n)
{
	int two = 0;
	int five = 0;
	int count = 0;
	for (int i = 2; i <= n; i++)
	{
		int num = i;
		while (num % 2 == 0)
		{
			num /= 2;
			two++;
		}
		while (num % 5 == 0)
		{
			num /= 5;
			five++;
		}
	}
	return min(two,five);
}

int main(void)
{
	int n;
	cin >> n;
	cout << countZero(n) << endl;
	return 0;
}