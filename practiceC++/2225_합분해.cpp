#include <iostream>

using namespace std;

class Sol
{
	long long dp[201][201];
	int n, k;
public:
	void set()
	{
		cin >> n >> k;
		for (int i = 1; i <= n; i++)
		{
			dp[i][1] = 1;
			dp[i][2] = i+1;
		}
		for (int i = 1; i <= k; i++)
		{
			dp[0][i] = 1;
		}
	}
	void sol()
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 3; j <= k; j++)
			{
				dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000000;
			}
		}
	}
	void print()
	{
		cout << dp[n][k]% 1000000000 << endl;
	}
};
int main(void)
{
	Sol s;
	s.set();
	s.sol();
	s.print();
	return 0;
}