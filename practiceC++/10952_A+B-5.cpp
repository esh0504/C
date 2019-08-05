#include <iostream>
using namespace std;

int main(void)
{
	int num, num1;
	while (cin >> num >> num1)
	{
		if (num == 0 && num1 == 0)
		{
			break;
		}
		cout << num1 + num << endl;
	}
}