#include <iostream>

using namespace std;

class Sol
{
private:
	int n;
	long long dp[117];
public:
	void setNum()
	{
		cin >> n;
	}
	void printAnswer()
	{
		cout << dp[n] << endl;
	}
	void sol()
	{
		dp[1] = dp[2] = dp[3] = 1;
		for (int i = 4; i <= n; i++)
		{
			dp[i] = dp[i - 1] + dp[i - 3];
		}
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