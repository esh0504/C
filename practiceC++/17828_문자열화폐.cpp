#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N, X;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> X;

	// ¿¹¿Ü
	if (26 * N < X || X < N)
	{
		cout << "!\n";

		return 0;
	}

	string result;

	for (int i = 0; i < N; i++)
	{
		result += 'A';
	}

	X -= N;

	for (int i = N - 1; i >= 0 && X > 0; i--)
	{
		int temp = min(X, 25); // A + 25 = Z

		result[i] += temp;
		X -= temp;
	}

	cout << result << "\n";

	return 0;
}