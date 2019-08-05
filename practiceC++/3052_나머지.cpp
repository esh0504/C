	#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int main(void)
{
	int na[10];
	int answer = 0;
	for (int i = 0; i < 10; i++)
	{
		int num;
		cin >> num;
		na[i] = num % 42;
	}
	sort(na, na+10);
	for (int i = 0; i < 9; i++)
	{
		if (na[i] != na[i + 1])
		{
			answer++;
		}
	}
	cout << answer+1 << endl;
}