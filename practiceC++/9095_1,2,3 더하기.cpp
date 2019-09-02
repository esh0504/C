#include <iostream>
using namespace std;

class Sol
{
private:
	int n;
	int dp[12];
public:
	void setNum()
	{
		cin >> n;
	}
	void printAnswer()
	{
		cout << dp[n]<<endl;
	}
	void sol()
	{
		dp[0] = 0;
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 4;
		for (int i = 4; i <= n; i++)
		{
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		}
	}
};

int main(void)
{
	int testCase;
	cin >> testCase;
	for (int i = 0; i < testCase; i++)
	{
		Sol sol;
		sol.setNum();
		sol.sol();
		sol.printAnswer();
	}
	return 0;
}