#include <iostream>

using namespace std;

int main(void)
{
	int num;
	int answer = 0;
	for (int i = 0; i < 5; i++)
	{
		cin >> num;
		answer += num * num;
	}
	answer = answer % 10;
	cout << answer;
}