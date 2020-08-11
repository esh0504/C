#include <iostream>
#include <queue>

using namespace std;

bool participant[51][51];
int partNum[51];

bool cannotLie[51];
bool connected[51][51];

int N, M;

int main() {
	cin >> N >> M;


	for (int i = 0; i <= M; i++) {
		cin.clear();
		cin >> partNum[i];
		if (partNum[i] == 0 && i != 0) {
			i--;
			M--;
			continue;
		}
		for (int k = 0; k < partNum[i]; k++) {
			int curParticipant;
			cin >> curParticipant;
			participant[i][curParticipant] = true;
		}
	}

	if (partNum[0] == 0) {
		cout << M;
		return 0;
	}

	for (int i = 0; i <= M; i++) {
		for (int k = i; k <= M; k++) {
			if (i == k) {
				connected[i][k] = true;
				continue;
			}

			for (int m = 0; m <= N; m++) {
				if (participant[i][m] && participant[k][m]) {
					connected[i][k] = connected[k][i] = true;
					break;
				}
			}
		}
	}

	queue<int> q;
	q.push(0);
	cannotLie[0] = true;
	int ans = M;

	while (!q.empty()) {
		int curParty = q.front();
		q.pop();

		for (int i = 1; i <= M; i++) {
			if (cannotLie[i]) {
				continue;
			}
			if (connected[curParty][i]) {
				q.push(i);

				cannotLie[i] = true;
				ans--;
			}
		}
	}

	cout << ans;
}