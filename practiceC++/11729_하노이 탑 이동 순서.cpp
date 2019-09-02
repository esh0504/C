#include <cstdio>
using namespace std;
void move(int from, int to) {
	printf("%d %d\n", from, to);
}
void hanoi(int n, int from, int by, int to) {
	if (n == 1) {
		move(from, to);
	}
	else {
		hanoi(n - 1, from, to, by);
		move(from, to);
		hanoi(n - 1, by, from, to);
	}
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	if (n >= 1 && n <= 20) {
		if (n == 1) puts("1");
		else printf("%d\n", (1 << n) - 1);
		hanoi(n, 1, 2, 3);
	}
	return 0;
}