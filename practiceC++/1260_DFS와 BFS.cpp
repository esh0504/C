#include <iostream>
#include <queue>
#include <cstring>        // memset

using namespace std;

int v, e, startNum;
int arr[1001][1001];     // 인접행렬
bool check[1001];        // check배열
void dfs(int x);
void bfs(int x);

int main()
{
	/*정점의 개수, 간선의 개수, 탐색시작 정점의 번호 입력받기*/
	cin >> v >> e >> startNum;

	/*입력을 받아 인접행렬 만들기*/
	while (e--) {
		int x, y;
		cin >> x >> y;
		arr[x][y] = arr[y][x] = 1; // 주어진 간선이 양방향이라고 하였으므로
	}

	/*인접행렬을 이용해서 DFS, BFS탐색하기*/
	dfs(startNum);
	cout << "\n";

	memset(check, false, sizeof(check));

	bfs(startNum);
	cout << "\n";
}

void dfs(int x) {
	cout << x << " ";
	check[x] = true;

	for (int i = 1; i <= v; i++) {
		if (check[i] == false && arr[x][i] == 1)
			dfs(i);
	}
}

void bfs(int x) {
	queue<int> q;

	q.push(x);
	check[x] = true;

	while (!q.empty()) {
		int currentNode = q.front();
		q.pop();
		cout << currentNode << " ";
		for (int i = 1; i <= v; i++) {
			if (check[i] == false && arr[currentNode][i] == 1) {
				q.push(i);
				check[i] = true;
			}
		}
	}
}