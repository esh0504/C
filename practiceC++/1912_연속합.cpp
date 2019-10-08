#include <iostream>

using namespace std;

class Sol
{
private:
	int n;
	int answer;
	int now;
	int dp[100001] = { 0 };
	int arr[100001] = { 0 };
public:
	void setNum()
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			int a;
			cin >> a;
			arr[i] = a;
			dp[i] = a;
		}
		answer = arr[1];
	}
	int max(int i, int j)
	{
		return i > j ? i : j;
	}

	void sol()
	{
		for (int i = 2; i <= n; i++) {


			if (dp[i - 1] > 0 && dp[i] + dp[i - 1] > 0) {
				dp[i] += dp[i - 1];
			}
			if (answer < dp[i]) {
				answer = dp[i];
			}

		}
	}
	void printAnswer()
	{
		cout << answer << endl;
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
