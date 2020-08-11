#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int maxNum(int a, int b) {
	return a > b ? a : b;
}
int main() {
	int max = 0;
	int n, m;
	cin >> n >> m;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		if (k > m) {
			continue;
		}
		v.push_back(k);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				int sum = v[i] + v[j] + v[k];
				if (sum == m) {
					max = m;
					i = j = k = n;
					continue;
				}
				if (sum > m) {
					break;
				}
				else {
					max = maxNum(max, sum);
				}
			}
		}
	}
	cout << max << endl;
}