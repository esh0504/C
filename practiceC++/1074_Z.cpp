#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;
int n, r, c;
int result;
void recursion(int x, int y, int len) {
	if (x == r && y == c) {
		cout << result << endl;
		exit(0);
	}
	if (len == 1) {
		result++; return;
	}
	if (!(x <= r && r<x + len && y <= c && c<y + len)) {
		result += len * len;
		return;
	}
	recursion(x, y, len / 2);//1사분면
	recursion(x, y + len / 2, len / 2);//2사분면
	recursion(x + len / 2, y, len / 2);//3사분면
	recursion(x + len / 2, y + len / 2, len / 2);//4사분면
}

int main() {
	cin >> n >> r >> c;
	recursion(0, 0, pow(2, n));
	return 0;
}