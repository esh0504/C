#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N;
	cin >> N;
	vector<int> limit;
	int time = 0;
	bool flag;

	for (int i = 0; i < N; i++) {
		int k;
		cin >> k;
		limit.push_back(k);
	}
	sort(limit.begin(), limit.end(), greater<int>());

	int M;
	cin >> M;

	list<int> l;

	for (int i = 0; i < M; i++) {
		int x;
		cin >> x;
		l.push_back(x);
	}

	l.sort(greater<int>());

	if (l.front() > limit[0])  
		time = -1;


	else {
		while (!l.empty()) { 
			flag = true;
			for (int i = 0; i < N; i++) {
				if (l.empty()) 
					break;

				if (l.front() <= limit[i]) 
					l.pop_front();

				else {
					for (auto it = l.begin(); it != l.end(); it++) 
						if (*it <= limit[i]) {
							l.erase(it);
							flag = false;
							break;
						}

					if (flag) 
						N = N - (N - i);
				}
			}
			time++;
		}
	}

	cout << time;
	return 0;
}