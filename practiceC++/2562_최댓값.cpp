#include <iostream>

using namespace std;

int main(void)
{
	int num[10];
	int max = 0;
	int maxindex = 0;
	for (int i = 1; i < 10; i++)
	{
		int a;
		cin >> a;
		num[i] = a;
		if (max < a)
		{
			max = a;
			maxindex = i;
		}
	}
	cout << max << endl << maxindex;
}