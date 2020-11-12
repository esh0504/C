#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int calc(int a, int b, string op) {
    if (op == "-") {
        return a - b;
    }
    else {
        return a + b;
    }
}

int maxNum(int a, int b) {
    return a > b ? a : b;
}
int minNum(int a, int b) {
    return a > b ? b : a;
}
int solution(vector<string> arr)
{
    vector<vector<int>>max_dp;
    vector<vector<int>>min_dp;
    int m = arr.size() / 2 + 1;
    vector<int> max_t;
    vector<int> min_t;
    for (int j = 0; j < m; j++) {
        max_t.push_back(INT_MIN);
        min_t.push_back(INT_MAX);
    }
    for (int i = 0; i < m; i++) {   
        min_dp.push_back(min_t);
        max_dp.push_back(max_t);
    }

    for (int i = 0; i < m; i++) 
    {
        min_dp[i][i] = max_dp[i][i] = stoi(arr[i * 2]); 
    }
    for (int i = 1; i < m; i++) {
        for (int j = 0; j < m - i; j++) {
            int k = i + j;
            string  op;
            for (int p = j; p < k; p++) {
                op = arr[p * 2 + 1];
                max_dp[j][k] = maxNum(max_dp[j][k], calc(max_dp[j][p], max_dp[p + 1][k], op));
                max_dp[j][k] = maxNum(max_dp[j][k], calc(min_dp[j][p], max_dp[p + 1][k], op));
                max_dp[j][k] = maxNum(max_dp[j][k], calc(max_dp[j][p], min_dp[p + 1][k], op));
                max_dp[j][k] = maxNum(max_dp[j][k], calc(min_dp[j][p], min_dp[p + 1][k], op));
                min_dp[j][k] = minNum(min_dp[j][k], calc(max_dp[j][p], max_dp[p + 1][k], op));
                min_dp[j][k] = minNum(min_dp[j][k], calc(max_dp[j][p], min_dp[p + 1][k], op));
                min_dp[j][k] = minNum(min_dp[j][k], calc(min_dp[j][p], max_dp[p + 1][k], op));
                min_dp[j][k] = minNum(min_dp[j][k], calc(min_dp[j][p], min_dp[p + 1][k], op));
            }
        }
    }
    int answer = max_dp[0][m-1];
    return answer;
}

int main() {
    int n;
    cin >> n;
    vector<string> arr;
    for (int i = 0; i < n; i++) {
        string a;
        cin >> a;
        arr.push_back(a);
    }
    cout << solution(arr) << endl;
    return 0;
}