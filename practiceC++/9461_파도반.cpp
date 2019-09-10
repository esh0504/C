#include <iostream>

using namespace std;

class Sol
{
private:
	int n;
	long long dp[101];
public:
	void set()
	{
		cin >> n;
	}
	void sol()
	{
		dp[0] = 0; dp[1] = 1; dp[2] = 1; dp[3] = 1; dp[4] = 2;
		for (int i = 5; i <= n; i++)
		{
			dp[i] = dp[i - 1] + dp[i - 5];
		}
	}
	void printAnswer()
	{
		cout << dp[n] << endl;
	}
};

int main(void)
{
	int test;
	cin >> test;
	for (int i = 0; i < test; i++)
	{
		Sol s;
		s.set();
		s.sol();
		s.printAnswer();
	}
	return 0;
}