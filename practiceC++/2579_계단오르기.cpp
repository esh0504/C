#include <iostream>
#include <algorithm>

using namespace std;

class Stair
{
private:
	int numOfStair;
	int arr[301];
	int dp[301];
	int answer = 0;
public:
	Stair(int n)
	{
		numOfStair = n;
		for (int i = 1; i <= n; i++)
		{
			int k;
			cin >> k;
			arr[i] = k;
		}
	}
	void solution()
	{
		dp[0] = 0;
		dp[1] = arr[1];
		dp[2] = arr[1] + arr[2];
		for (int i = 3; i <= numOfStair; i++)
		{
			dp[i] = max(dp[i - 3] + arr[i - 1] + arr[i], dp[i - 2] + arr[i]);
		}
		answer = dp[numOfStair];
	}
	void printAnswer()
	{
		cout << answer << endl;
	}
};
int main(void)
{
	int n;
	cin >> n;
	Stair St(n);
	St.solution();
	St.printAnswer();
	return 0;
}