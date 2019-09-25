#include <iostream>

using namespace std;

class Sol
{
private:
	int n;
	int max ;
	int dp[1001];
	int arr[1001];
public:
	void setNum()
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			int a;
			cin >> a;
			arr[i] = a;
		}
	}
	void sol()
	{
		for (int i = 1; i <= n; i++)
		{
			int memory=arr[i];
			dp[i] = arr[i];
			for (int j = i; j > 0; j--)
			{
				if (arr[j] < arr[i] && (memory<(dp[j]+arr[i])))
				{
					dp[i] = dp[j] + arr[i];
					memory = dp[i];
				}
			}
		}
		max = 0;
		for (int i = 1; i <= n; i++)
		{
			if (dp[i] > max)
			{
				max = dp[i];
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