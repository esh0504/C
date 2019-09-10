#include <iostream>

using namespace std;

class Sol {
private:
	int n;
	int dp[1001];
public:
	void setNum()
	{
		cin >> n;
		dp[1] = 1;
		dp[2] = 3;
	}
	void sol()
	{
		for (int i = 3; i <= n; i++)
		{
			dp[i] = (dp[i - 1] + (2 * dp[i - 2]))%10007;
		}
	}
	void printAnswer()
	{
		cout << dp[n]%10007 << endl;
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