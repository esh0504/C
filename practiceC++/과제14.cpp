#include <iostream>
using namespace std;

int main(void)
{
	int testCase;
	cin >> testCase;
	for (int i = 0; i < testCase; i++)
	{
		int num;
		cin >> num;
		for (int i=1;i<=num;i++){
			int answer = i;
			for (int j = 1; j <= i; j++)
			{
				cout << answer<<" ";
				answer += num - j;
			}
			cout << endl;
		}
	}
}