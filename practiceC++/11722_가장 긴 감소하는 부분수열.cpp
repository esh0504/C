#include <iostream>

using namespace std;

class Sol
{
private:
	int n;
	int arr[1001];
	int dp[1001];
	int max = 0;
public:
	void setNum()
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			int a;
			cin >> a;
			arr[i] = a;
			dp[i] = 1;
		}
	}

	void sol()
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j < i; j++)
			{
				if (arr[j] > arr[i])
				{
					if (dp[i] > dp[j] + 1)
					{
						dp[i] = dp[i];
					}
					else
					{
						dp[i] = dp[j] + 1;
					}
				}
			}
		}
		for (int i = 1; i <= n; i++)
		{
			if (dp[i] > max)
			{
				max = dp[i];
			}
			else
			{
				continue;
			}
		}
	}
	void printAnswer()
	{
		cout << max << endl;
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