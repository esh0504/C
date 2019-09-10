#include <iostream>
#include <algorithm>

using namespace std;

class Sol
{
private:
	int n;
	int answer = 0;
	int d2[100001];
	int d[100001];
public:
	void Set()
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int a;
			cin >> a;
			d[i] = a;
		}
		for (int i = 0; i < n; i++)
		{
			int a;
			cin >> a;
			d2[i]=a;
		}
		sort(d, d + n);
		sort(d2, d2 + n);
	}
	void sol()
	{
		for (int i = 0; i < n; i++)
		{
			answer+=d[i] * d2[n - i - 1];
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
	s.Set();
	s.sol();
	s.printAnswer();
	return 0;
}