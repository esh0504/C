#include<iostream>
#include<vector>

using namespace std;

int n, s, ans = 0;
vector<int> v;

void dfs(int sum, int idx, int leng) {
	sum += v[idx];

	if (idx >= n)
		return;

	if (sum == s && leng >= 1)
		ans++;

	dfs(sum, idx + 1, leng + 1);
	dfs(sum - v[idx], idx + 1, leng);
}
int main(void) {
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	dfs(0, 0, 1);
	cout << ans;
	return 0;
}
