#include <iostream>
#include<string.h>
#include<stack>

using namespace std;

class Sol
{
private:
	int n, m;
	int answer;
	int** map;
	bool** check;
	stack<pair<int, int>> st;
public:
	void set()
	{
		cin >> n >> m;
		map = new int*[n];
		check = new bool*[n];
		for (int i = 0; i < n; i++)
		{
			map[i] = new int[m];
			check[i] = new bool[m];
			memset(map[i], 0, sizeof(int)*m);
			memset(check[i], false, sizeof(bool)*m);
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				int a;
				cin >> a;
				map[i][j] = a;
			}
		}
	}
	void dfs(int cnt, int x, int y)
	{
		if (x == n-1, y == m-1)
		{
			answer = cnt;
			return;
		}
		check[x][y] = true;
		if (check[x][y+1] == false && map[x][y+1] == 1)
		{
			pair<int, int> pr = make_pair(x, y);
			st.push(pr);
			dfs(cnt + 1, x, y + 1);
		}
		else if (check[x][y-1] == false && map[x][y-1] == 1)
		{
			pair<int, int> pr = make_pair(x, y-1);
			st.push(pr);
			dfs(cnt+1, x, y-1);
		}
		else if (check[x+1][y] == false && map[x+1][y] == 1)
		{
			pair<int, int> pr = make_pair(x+1, y);
			st.push(pr);
			dfs(cnt + 1, x+1, y);
		}
		else if (check[x-1][y] == false && map[x-1][y] == 1)
		{
			pair<int, int> pr = make_pair(x-1, y);
			st.push(pr);
			dfs(cnt + 1, x-1, y);
		}
		else
		{
			int x1 = st.top().first;
			int y1 = st.top().second;
			dfs(cnt - 1, x1,y1);
		}
	}
	void print()
	{
		cout << answer << endl;
	}
};

int main(void)
{
	Sol s;
	s.set();
	s.dfs(0,0,0);
	s.print();
	return 0;
}