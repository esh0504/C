#include<iostream>
using namespace std;
void bfs(int num, int y, int x, bool check[][])
{
	check[y][x] = false;
	for (int i = 1; y + i < num; i++)
	{
		check[y + i][x + i] = false;
		if (y - i >= 0) {
			check[y - i][x - i] = false;
		}
	}
	for (int i = 0; i < num; i++)
	{
		check[y][i] = false;
		check[i][x] = false;
	}

}
int main(void)
{
	int num;
	int answer=0;
	cin >> num;
	bool check[11][11];
	for (int i = num; i <= 10; i++)
	{
		for (int j = num; j <= 10; j++)
		{
			check[i][j] = false;
		}
	}
	int count = 0;
	for (int y = 0; y < num; y++)
	{
		for (int x = 0; x < num; x++)
		{
			if (check[y][x] != false)
			{
				check[y][x] = true;
				count += 1;
			}
			if (check[y][x] == true)
			{
				bfs(num, y, x, check);
			}
			if (count == num)
			{
				answer += 1;
				break;
			}
		}
		
	}
	for (int y = 0; y < num; y++)
	{
		for (int x = 0; x < num; x++)
		{
			cout << check[y][x];
		}
		cout << endl;
	}
	cout << answer << endl;
}
