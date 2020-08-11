#include <iostream>

using namespace std;
int DP[1001][10];

int main() {
	int n, sum = 0;
	int i, j, k;
	cin >> n;
	for (i = 0; i <= 9; i++) {
		DP[1][i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = j; k <= 9; k++) {
				DP[i][k] += DP[i - 1][j];
				DP[i][j] %= 10007;
			}
		}
	}
	for (int i = 0; i <= 9; i++) {
		sum += DP[n][i];
	}
	cout << sum%10007 << endl;
}