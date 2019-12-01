#include <iostream>
#include <queue>
using namespace std;

class Sol
{
private:
	int map[1001][1001] = { 0 };
	int d[1001]={100001};
	int n, m;
	int a, r;
	int start,destination,w;
	priority_queue <int> q;

public:
	void set()
	{
		cin >> n >> m;
		for (int i = 0; i < m; i++)
		{
			cin >> start >> destination >> w;
			map[start][destination]=w;
		}
		cin >> a >> r;
		for (int i = 1; i <= n; i++)
		{
			d[i] = map[a][i];
			if (d[i] != -1)
			{
				q.push(i);
			}
		}

	}
	int min(int a, int b)
	{
		if (a == 100001 )
		{
			return b;
		}
		if (b == 100001)
		{
			return a;
		}
		return a > b ? b : a;
	}
	void sol()
	{
		while (!q.empty())
		{
			int k = q.top();
			q.pop();
			for (int i = 1; i <= n; i++)
			{
				d[i] = min(d[i], d[k] + map[k][i]);
			}
		}
		cin >> r;
	}
	void print()
	{
		cout << d[r] << endl;
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