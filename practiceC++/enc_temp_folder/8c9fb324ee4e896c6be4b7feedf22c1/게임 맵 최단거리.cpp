#include<vector>
#include <queue>
#include <cstring>
#include <iostream>
#define MAX 10001
using namespace std;

int dist[101][101], mX[] = { -1,0,1,0 }, mY[] = { 0,1,0,-1 };

int solution(vector<vector<int> > maps)
{
    memset(dist, MAX, sizeof(dist));
    int N = maps.size(), M = maps[0].size();
    dist[0][0] = 0;
    int answer = 1;
    queue<pair<int, int>>q;
    q.push(make_pair(0, 0));
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + mX[i];
            int ny = y + mY[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if (maps[nx][ny] == 0) continue;
            if (dist[nx][ny] > dist[x][y] + 1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push(make_pair(nx, ny));
            }

        }
    }
    if (dist[N - 1][M - 1] == 286331153) answer = -1;
    else
        answer = dist[N - 1][M - 1] + 1;
    return answer;
}

int main() {
    vector<vector<int>>maps;
    for (int i = 0; i < 5; i++) {
        vector<int> tmp;
        for (int j = 0; j < 5; j++) {
            int n; 
            cin >> n;
            tmp.push_back(n);
        }
        maps.push_back(tmp);
    }
    cout << solution(maps) << endl;
}