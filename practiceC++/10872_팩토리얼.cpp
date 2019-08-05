#include <iostream>

using namespace std;

int main(void)
{
	int test;
	int result = 1;
	cin >> test;
	
	for (int i = 1; i <= test; i++)
	{
		result *= i;
	}
	cout << result;
}