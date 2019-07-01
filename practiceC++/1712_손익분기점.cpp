#include <iostream>
using namespace std;
int main(void)
{
	int a, b, c;
	cin >> a >> b >> c;
	int i = a / (c - b) + 1;
	if (c - b <= 0)
	{
		i = -1;
	}
	cout << i << endl;
	return 0;
}