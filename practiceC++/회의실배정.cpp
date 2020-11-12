#include<vector>
#include <algorithm>

using namespace std;

bool srt(vector<int> a, vector<int> b) {
    if (a[1] == b[1]) {
        return a[0] < b[0];
    }
    else {
        return a[1] < b[1];
    }
}

int solution(vector<vector<int> > arr)
{
    int answer = 0;
    sort(arr.begin(), arr.end(), srt);
    int now = arr[0][1];
    answer = 1;
    for (int i = 1; i < arr.size(); i++) {
        if (now <= arr[i][0]) {
            answer++;
            now = arr[i][1];
        }
    }

    return answer;
}