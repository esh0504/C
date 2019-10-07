#include <iostream>
#include <stack>
using namespace std;

stack<char> st;
char map[21][21];
int main(void)
{
	int r, c;
	cin >> r >> c;
	for (int i=1; i <= c; i++)
	{
		for (int j = 1; j <= r; j++)
		{
			char a;
			cin >> a;
			map[i][j] = a;
		}
	}
}
bool check(int r, int c,char ch)
{
	for (int i = 1; i <= c; i++)
	{
		for (int j = 1; j <= r; j++)
		{
			if (ch == map[i][j])
			{
				return false;
			}
		}
	}
	return true;
}
void dfs()
{
	
}