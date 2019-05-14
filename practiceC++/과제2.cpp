#include <iostream>
using namespace std;
void outputPyramid(int n, int k);
int main(void)
{
	int t;
	int n, k;
	cin >> t;
	for (int i = 0; i<t; i++)
	{
		cin >> n >> k;
		outputPyramid(n, k);
	}
	return 0;
}
void outputPyramid(int n, int k)
{
	int num = k;
	cout << num;
	for (int i = 1; i < k; i++) {
		num = num + n - i;
		cout << "*" << num;
		
	}
	cout << endl;
}