#include <iostream>

using namespace std;

class Sol
{
private:
	int n;
	long long dp[91] = { 0 };
public:
	void setNum()
	{
		cin >> n;
	}
	void sol()
	{
		dp[1] = 1;
		dp[2] = 1;
		for (int i = 3; i <= n; i++)
		{
			dp[i] = dp[i - 2] + dp[i - 1];
		}
	}
	void printAnswer()
	{
		cout << dp[n] << endl;
	}
};
int main(void)
{
	Sol s;
	s.setNum();
	s.sol();
	s.printAnswer();
	return 0;
}