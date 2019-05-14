#include <iostream>
using namespace std;
void outputZigZag(int n, int k);
int main(void)
{
	int t;
	int n, k;
	cin >> t;
	for (int i = 0; i<t; i++)
	{
		cin >> n >> k;
		outputZigZag(n, k);
	}
	return 0;
}
void outputZigZag(int n, int k)
{
	int startNum = 0;
	for (int i = 1; i < k; i++) {
		startNum += i;
	}if (k % 2 == 1) {
		startNum += 1;
		cout << startNum;
		for (int i = 1; i < k; i++) {
			cout << "*" << startNum + i;
		}cout << endl;
	}
	else
	{
		startNum += k;
		cout << startNum;
		for (int i = 1; i < k; i++) {
			cout << "*" << startNum - i;
		}cout << endl;
	}
}