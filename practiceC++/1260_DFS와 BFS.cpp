#include <iostream>
#include <queue>
#include <cstring>        // memset

using namespace std;

int v, e, startNum;
int arr[1001][1001];     // �������
bool check[1001];        // check�迭
void dfs(int x);
void bfs(int x);

int main()
{
	/*������ ����, ������ ����, Ž������ ������ ��ȣ �Է¹ޱ�*/
	cin >> v >> e >> startNum;

	/*�Է��� �޾� ������� �����*/
	while (e--) {
		int x, y;
		cin >> x >> y;
		arr[x][y] = arr[y][x] = 1; // �־��� ������ ������̶�� �Ͽ����Ƿ�
	}

	/*��������� �̿��ؼ� DFS, BFSŽ���ϱ�*/
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