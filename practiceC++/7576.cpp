#include<iostream>
#include<stdio.h>
#include<queue>
#include<map>
#include<vector>
using namespace std;
int x_length, y_length;
int tomato[1001][1001];
bool check[1001][1001];
typedef struct
{
	int y, x;
}
Dir;
Dir moveDir[4] = { { 1, 0 },{ -1, 0 },{ 0, 1 },{ 0, -1 } };

void bfs(int y, int x,bool check[1001][1001])
{	
	for (int i = 0; i < 4; i++)
	{
		int nextY = y + moveDir[i].y;
		int nextX = x + moveDir[i].x;

		if (0 <= nextY && nextY < 1001 && 0 <= nextX && nextX < 1001)
		{
			if (check[nextY][nextX] == true)
			{
				bfs(nextY, nextX,check);
			}
			else if (check[nextY][nextX]==false)
			{
				check[nextY][nextX] = true;
			}
		}
	}
}
int main(void) {
	int x_length, y_length;
	cin >> x_length >> y_length;
	int Count = 0;
	for (int i = 0; i < y_length; i++)
	{
		for (int j = 0; j < x_length; j++)
		{
			int a;
			cin >> a;
			tomato[i][j] = a;
			check[i][j] = false;
			if (a == 1)
			{
				check[i][j] = true;
			}
		}
	}
	int count = 0;
	while (count != x_length * y_length)
	{
		for (int i = 0; i < y_length; i++)
		{
			for (int j = 0; j < x_length; j++)
			{
				if (check[i][j]==true)
				{
					bfs(i, j,check);
					Count += 1;
				}
			}
		}
	}
	cout << Count << endl;
	return 0;
}