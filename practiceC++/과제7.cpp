#include <iostream>
using namespace std;

int count(int num, int count2,int count5)
{
	for (int i = 0; i < num; i++)
	{
		int a;
		cin >> a;
		while (a % 2 == 0) {
			count2 += 1;
			a=a / 2;
		}
		while (a % 5 == 0) {
			count5 += 1;
			a = a / 5;
		}
	}
	if (count2 >= count5)
	{
		return count5;
	}
	return count2;
}
int main(void)
{
	int testCase;
	cin >> testCase;
	for (int j = 0; j < testCase; j++)
	{
		int num;
		cin >> num;
		int answer = count(num,0,0);
		cout << answer << endl;
	}
}
