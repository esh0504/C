#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
	int testCase;
	cin >> testCase;
	
	for (int i = 0; i < testCase; i++)
	{
		int candi[1000]; 
		int sum = 0;
		int num;
		cin >> num;
		for (int j = 1; j <= num; j++)
		{
			int a;
			cin >> a;
			candi[j] = a;
			sum += a;
		}
		sum = sum / 2;
		for (int k = 1; k <= num; k++)
		{
			if (sum < candi[k])
			{
				cout << k << endl;
				break;
			}
			if (k == num && candi[k] <= sum) {
				cout << 0 << endl;
				break;
			}
		}
	}
}