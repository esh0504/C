#include <iostream>
#include <cstdio>
#define MOD 1000007
using namespace std; 
int N,M,x,y; 
long long a[202][202]; 
int main()
{
	for (int i = 1; i <= 200; i++)
	{
		for (int j = 1; j <= 200; j++)
		{
			if (i == 1 || j == 1)
				a[i][j] = 1;
			else
			{
				a[i][j] = (a[i - 1][j] + a[i][j - 1]) % MOD;
			}
		}
	}
	scanf("%d %d", &M, &N);
	scanf("%d %d", &x, &y);
	printf("%lld", (a[x][y] * a[M - x + 1][N - y + 1]) % MOD);
}
