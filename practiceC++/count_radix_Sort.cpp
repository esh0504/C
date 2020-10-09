#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

queue <pair<int, string>> q;

int digit16(int v, int d) {
    // 양의 정수 v 의 16진수 d 번째 숫자를 반환하는 함수
    // 예를 들어 v 의 값이 78320238 (= 0x4ab126e) 이고 d 가 1 이라면 6 을 반환
    // 예를 들어 v 의 값이 78320238 (= 0x4ab126e) 이고 d 가 4 라면 11 (= 0xb) 을 반환
    v = v >> d * 4;
    return v & 0xf;
}

vector<pair<int, string> > countingSort16(vector<pair<int, string> >& v, int d) {
    int k = 15;
    vector<pair<int, string>> b(v.size());
    int count[16] = { 0 };
    for (int i = 0; i < v.size(); i++) {
        count[digit16(v[i].first, d)] ++;
    }
    for (int i = 0; i < 15; i++) {
        count[i + 1] += count[i];
    }

    for (int i = v.size() - 1; i >= 0; i--) {
        b[count[digit16(v[i].first, d)]-1] = make_pair(v[i].first, v[i].second);
        count[digit16(v[i].first, d)] = count[digit16(v[i].first, d)] - 1;
    }
    return b;
}

int main(void) {
    int n;
    vector<pair<int, string> > v;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int d;
        string s;
        cin >> d >> s;
        v.push_back(pair<int, string>(d, s));
    }

    //radixsort
    for (int d = 0; d < 8; d++) v=countingSort16(v, d);

    for (int i = 0; i < n; i++) {
        cout << v[i].first << ' ' << v[i].second << endl;
    }
    return 0;
}