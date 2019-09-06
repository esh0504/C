#include <iostream>

using namespace std;

class Sol
{
private:
	int n;
	int dp[1001];
public:
	void setNum()
	{
		cin >> n;
		dp[1] = 1;
		dp[2] = 2;
	}
	void printAnswer()
	{
		cout << dp[n]%10007 << endl;
	}
	void solution()
	{
		for (int i = 3; i <= n; i++)
		{
			dp[i] = (dp[i - 1] + dp[i - 2])%10007;
		}
	}
};

int main(void)
{
	Sol sol;
	sol.setNum();
	sol.solution();
	sol.printAnswer();
	return 0;
}