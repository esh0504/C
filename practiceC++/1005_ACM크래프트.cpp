#include <iostream>

using namespace std;

class Sol
{
private:
	int n;
	int k,s,d,w;
	int arr[1001];
	int dps[1001];
	int dpd[1001];
	int dp[1001];
	
public:
	int max(int a, int b)
	{
		return a > b ? a : b;
	}
	void setNum()
	{
		cin >> n >> k;
		for (int i = 1; i <= n; i++)
		{
			int a;
			cin >> a;
			arr[i] = a;
			dp[i] = a;
		}
		for (int i = 1; i <= k; i++)
		{
			cin >> s >> d;
			dps[i] = s;
			dpd[i] = d;
		}
	}
	void sol()
	{
		for (int cnt = 0; cnt <= k; cnt++)
		{
			for (int i = 1; i <= k; i++)
			{
				dp[dpd[i]] = max(dp[i], dp[dps[i]] + arr[dpd[i]]);
			}
		}
		
	}
	void printAnswer()
	{
		cin >> w;
		cout << dp[w] << endl;
	}
};

int main(void)
{
	int testCase;
	cin >> testCase;
	for (int t = 0; t < testCase; t++)
	{
		Sol s;
		s.setNum();
		s.sol();
		s.printAnswer();
	}
	return 0;
}