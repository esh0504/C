#include<cstdio>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

stack<pair<int, int>> st;
vector<int> vc;
int map[51][51] = { 0 };
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%1d", &map[i][j]);
        }
    }
    int room = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (map[i][j])
            {
                room = 0;
                map[i][j] = 0;
                st.push(make_pair(i, j));
                while (!st.empty())
                {
                    room++;
                    pair<int, int> now = st.top(); st.pop();
                    for (int k = 0; k < 4; k++) {
                        if (map[now.first + dy[k]][now.second + dx[k]])
                        {
                            map[now.first + dy[k]][now.second + dx[k]] = 0;
                            st.push(make_pair(now.first + dy[k], now.second + dx[k]));
                        }
                    }
                }
                vc.push_back(room);
            }
        }
    }
    sort(vc.begin(), vc.end());
    printf("%d\n", vc.size());
    for (int i = 0; i < vc.size(); i++)printf("%d\n", vc[i]);
    return 0;
}
