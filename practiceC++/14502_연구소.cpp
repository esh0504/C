#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Sol
{
private:
	vector <vector<int>> map;
	vector <vector<int>> copy;
	vector <vector<bool>> check;
	int n, m;
	int answer = 0;
	queue<int> x;
	queue<int> y;
public:
	void set()
	{
		cin >> n >> m;
		for (int i = 0; i < n; i++)
		{
			vector <int> v;
			for (int j = 0; j < m; j++)
			{
				int a;
				cin >> a;
				v.push_back(a);
			}
			map.push_back(v);
			copy.push_back(v);
		}
	}
	void reset()
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				copy[i][j] = map[i][j];
			}
		}
		for (int i = 0; i < n; i++)
		{
			vector<bool> v;
			for (int j = 0; j < m; j++)
			{
				if (copy[i][j] == 0)
				{
					v.push_back(true);
					continue;
				}
				v.push_back(false);
			}
			check.push_back(v);
		}
	}
	void spread()
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (copy[i][j] == 2)
				{
					x.push(i);
					y.push(j);
				}
			}
		}
		while (!x.empty())
		{
			int p=x.front();
			int r = y.front();
			x.pop();
			y.pop();
			if (p != n - 1 && r != m - 1)
			{
				if (copy[p+1][r] == 0 && check[p+1][r] == true)
				{
					copy[p+1][r] = 2;
					check[p+1][r] = false;
					x.push(p+1);
					y.push(r);
				}
				if (copy[p][r+1] == 0 && check[p][r+1] == true)
				{
					copy[p][r+1] = 2;
					check[p][r+1] = false;
					x.push(p);
					y.push(r+1);
				}
			}
			if (r != 0 && p != n - 1)
			{
				if (copy[p][r-1] == 0 && check[p][r-1] == true)
				{
					copy[p][r-1] = 2;
					check[p][r-1] = false;
					x.push(p);
					y.push(r-1);
				}
				if (copy[p][r+1] == 0 && check[p][r+1] == true)
				{
					copy[p][r+1] = 2;
					check[p][r+1] = false;
					x.push(p);
					y.push(r+1);
				}
			}
			if (p != 0 && r != 0)
			{
				if (copy[p][r-1] == 0 && check[p][r-1] == true)
				{
					copy[p][r-1] = 2;
					check[p][r-1] = false;
					x.push(p);
					y.push(r-1);
				}
				if (copy[p-1][r] == 0 && check[p-1][r] == true)
				{
					copy[p-1][r] = 2;
					check[p-1][r] = false;
					x.push(p-1);
					y.push(r);
				}
			}
			if (p != 0 && r != m - 1)
			{
				if (copy[p][r+1] == 0 && check[p][r+1] == true)
				{
					copy[p][r+1] = 2;
					check[p][r+1] = false;
					x.push(p);
					y.push(r+1);
				}
				if (copy[p-1][r] == 0 && check[p-1][r] == true)
				{
					copy[p-1][r] = 2;
					check[p-1][r] = false;
					x.push(p-1);
					y.push(r);
				}
			}
		}
		int count = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (copy[i][j] == 0)
				{
					count++;
				}
			}
		}
		answer = max(answer, count);
	}
	void wall(int cnt) {
		if (cnt == 3) {
			spread();
			return;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (copy[i][j] == 0) {
					copy[i][j] = 1;
					wall(cnt + 1);
					copy[i][j] = 0;
				}
			}
		}

	}
};