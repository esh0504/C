#include <iostream>
#include<vector>
#include <queue>

using namespace std;

vector<bool> check;
queue<int> q;
vector<vector<int> > solution(int n, vector<vector<int> > signs)
{
    vector<vector<int> > answer=signs;
    for (int i = 0; i < n; i++) {
        check.push_back(false);
    }
    for (int i = 0; i < n; i++) {
        
        for (int j = 0; j < n; j++) {
            if (signs[i][j] == 1) {
                q.push(j);
            }
        }
        fill(check.begin(), check.end(), false);
        while (!q.empty()) {
            int p = q.front();
            q.pop();
            
            for (int j = 0; j < n; j++) {
                if (signs[p][j] == 1 && check[j] == false) {
                    q.push(j);
                    answer[i][j] = 1;
                    check[j] = true;
                }
            }
        }
    }

    return answer;
}



void main() {
    
    vector<vector<int>> input;
    for (int i = 0; i < 3; i++) {
        vector<int>tmp;
        int n;
        for (int j = 0; j < 3; j++) {
            cin >> n;
            tmp.push_back(n);
        }
        input.push_back(tmp);
    }
    vector<vector<int>> output = solution(3, input);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
    return;
}