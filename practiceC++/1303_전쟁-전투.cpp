#include<iostream>
#include <queue>

using namespace std;

pair<int, int> direction[4] = { make_pair(-1,0),make_pair(0,1),make_pair(1,0),make_pair(0,-1) };

int main(void) {
	queue<pair<int, int>> army;
	int a, b;
	cin >> b >> a;
	char arr[101][101];
	bool check[101][101] = { false };
	for (int i = 1; i <= a; i++) {
		for (int j = 1; j <= b; j++) {
			cin >> arr[i][j];
		}
	}
	int n = 0; int m = 0;
	int count = 0;
	for (int i = 1; i <= a; i++) {
		for (int j = 1; j <= b; j++) {
			if (arr[i][j] == 'W' && check[i][j] == false) {
				count++;
				army.push(make_pair(i, j));
				while (!army.empty()) {
					pair <int, int>tmparmy = army.front();
					army.pop();
					int p = tmparmy.first;
					int o = tmparmy.second;
					check[p][o] = true;
					for (int k = 0; k < 4; k++) {
						if (arr[p + direction[k].first][o + direction[k].second] == 'W' && check[p + direction[k].first][o + direction[k].second] == false) {
							army.push(make_pair(p + direction[k].first, o + direction[k].second));
							check[p + direction[k].first][o + direction[k].second] = true;
							count++;
						}
					}
				}
				n += count * count;
				count = 0;
			}
			count = 0;
			if (arr[i][j] == 'B' && check[i][j] == false) {
				count++;
				army.push(make_pair(i, j));
				while (!army.empty()) {
					pair <int, int>tmparmy = army.front();
					army.pop();
					int p = tmparmy.first;
					int o = tmparmy.second;
					check[p][o] = true;
					for (int k = 0; k < 4; k++) {
						if (arr[p + direction[k].first][o + direction[k].second] == 'B' && check[p + direction[k].first][o + direction[k].second] == false) {
							army.push(make_pair(p + direction[k].first, o + direction[k].second));
							check[p + direction[k].first][o + direction[k].second] = true;
							count++;
						}
					}
				}
				m += count * count;
				count = 0;
			}
		}
	}
	cout << n << " " << m;
	return 0;
}