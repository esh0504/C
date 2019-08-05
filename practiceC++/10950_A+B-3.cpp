#include <iostream>
using namespace std;

int main(void)
{
	int test;
	cin >> test;
	for (int i = 0; i < test; i++)
	{
		int num, num2;
		cin >> num >> num2;
		cout << num + num2 << endl;
	}
}