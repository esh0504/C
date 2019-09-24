#include <iostream>
using namespace std;

class Sol
{
private:
	int num;
	int answer=0;
	int day[17];
	int pay[17];
	int dp[17] = { 0 };
public:
	int max(int a, int b)
	{
		return a >= b ? a : b;
	}
	void setNum()
	{
		cin >> num;
		for (int i = 1; i <= num; i++)
		{
			int a, b;
			cin >> a >> b;
			day[i] = a;
			pay[i] = b;
		}
	}
	void printAnswer()
	{
		cout << answer << endl;
	}
	void sol()
	{
		for (int i = 1; i <= num+1; i++)
		{
			for (int j = 1; j < i; j++)
			{
				dp[i] = max(dp[i], dp[j]);
				if (j + day[j] == i)
				{
					dp[i] = max(dp[i], dp[j] + pay[j]);
				}
			}
		}
		answer = max(answer, dp[num+1]);
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