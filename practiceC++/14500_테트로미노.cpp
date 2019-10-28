#include <iostream>

using namespace std;

class Sol
{
private:
	int m, n,k;
	int maxt = 0;
	int map[501][501];
public:
	void set()
	{
		cin >> m >> n;
		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				cin >> k;
				map[i][j] = k;
			}
		}
	}
	int max(int a, int b)
	{
		return a > b ? a : b;
	}
	void check_blue()
	{
		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= n-3; j++)
			{
				maxt = max(map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i][j + 3], maxt);
			}
		}
		for (int i = 1; i <= m - 3; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				maxt = max(map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 3][j], maxt);
			}
		}
	}
	void check_yellow()
	{
		for (int i = 1; i <= m - 1; i++)
		{
			for (int j = 1; j <= n - 1; j++)
			{
				maxt = max(map[i][j] + map[i + 1][j] + map[i][j + 1] + map[i + 1][j + 1], maxt);
			}
		}
	}
	void check_orange()
	{
		for (int i = 1; i <= m - 1; i++)
		{
			for (int j = 1; j <= n - 2; j++)
			{
				maxt = max(map[i][j] + map[i + 1][j] + map[i][j + 1] + map[i][j + 2], maxt);
			}
		}
		for (int i = 1; i <= m - 2; i++)
		{
			for (int j = 1; j <= n - 1; j++)
			{
				maxt = max(map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 2][j + 1], maxt);
			}
		}
		for (int i = 1; i <= m - 2; i++)
		{
			for (int j = 1; j <= n - 1; j++)
			{
				maxt = max(map[i][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i + 2][j + 1], maxt);
			}
		}
		for (int i = 1; i <= m - 1; i++)
		{
			for (int j = 1; j <= n - 2; j++)
			{
				maxt = max(map[i][j + 2] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 1][j + 2], maxt);
			}
		}
		for (int i = 1; i <= m - 2; i++)
		{
			for (int j = 1; j <= n - 1; j++)
			{
				maxt = max(map[i + 2][j] + map[i + 2][j + 1] + map[i + 1][j + 1] + map[i][j + 1], maxt);
			}
		}
		for (int i = 1; i <= m - 1; i++)
		{
			for (int j = 1; j <= n - 2; j++)
			{
				maxt = max(map[i][j] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 1][j + 2], maxt);
			}
		}
		for (int i = 1; i <= m - 2; i++)
		{
			for (int j = 1; j <= n - 1; j++)
			{
				maxt = max(map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i][j + 1], maxt);
			}
		}
		for (int i = 1; i <= m - 1; i++)
		{
			for (int j = 1; j <= n - 2; j++)
			{
				maxt = max(map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j + 2], maxt);
			}
		}
	}
	void check_green()
	{
		for (int i = 1; i <= m - 2; i++)
		{
			for (int j = 1; j <= n - 1; j++)
			{
				maxt = max(map[i][j] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 2][j + 1], maxt);
			}
		}
		for (int i = 1; i <= m - 1; i++)
		{
			for (int j = 1; j <= n - 2; j++)
			{
				maxt = max(map[i + 1][j] + map[i + 1][j + 1] + map[i][j + 1] + map[i][j + 2], maxt);
			}
		}
		for (int i = 1; i <= m - 2; i++)
		{
			for (int j = 1; j <= n - 1; j++)
			{
				maxt = max(map[i][j + 1] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 2][j], maxt);
			}
		}
		for (int i = 1; i <= m - 1; i++)
		{
			for (int j = 1; j <= n - 2; j++)
			{
				maxt = max(map[i][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i + 1][j + 2], maxt);
			}
		}
	}
	void check_puple()
	{
		for (int i = 1; i <= m - 1; i++)
		{
			for (int j = 1; j <= n - 2; j++)
			{
				maxt = max(map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j + 1], maxt);
			}
		}
		for (int i = 1; i <= m - 2; i++)
		{
			for (int j = 1; j <= n - 1; j++)
			{
				maxt = max(map[i + 1][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i + 2][j + 1], maxt);
			}
		}
		for (int i = 1; i <= m - 1; i++)
		{
			for (int j = 1; j <= n - 2; j++)
			{
				maxt = max(map[i][j + 1] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 1][j + 2], maxt);
			}
		}
		for (int i = 1; i <= m - 2; i++)
		{
			for (int j = 1; j <= n - 1; j++)
			{
				maxt = max(map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 1][j + 1], maxt);
			}
		}
	}
	void sol()
	{
		check_blue();
		check_green();
		check_orange();
		check_puple();
		check_yellow();
	}
	void printAnswer()
	{
		cout << maxt << endl;
	}
};

int main(void)
{
	Sol s;
	s.set();
	s.sol();
	s.printAnswer();
	return 0;
}