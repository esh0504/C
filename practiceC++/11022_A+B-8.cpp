#include <iostream>
using namespace std;

int main(void)
{
	int test;
	cin >> test;
	for (int i = 1; i <= test; i++)
	{
		int num, num2;
		cin >> num >> num2;
		cout << "Case #" << i << ": "<<num<<" + "<<num2<<" = " << num + num2 << endl;
	}
}