#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <climits>
using namespace std;
vector<pair<int, string>>sorted;

void merge(vector<pair<int, string>>& v, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    vector<pair<int, string>> Left;
    vector<pair<int, string>> Right;
    for (int i = 0; i < n1; i++) {
        Left.push_back(pair<int, string>(v[p + i].first, v[p + i].second));
    }
    for (int j = 0; j < n2; j++) {
        Right.push_back(pair<int, string>(v[q+j+1].first, v[q+j+1].second));
    }
    Left.push_back(pair<int, string>(-1000, "sd"));
    Right.push_back(pair<int, string>(-1000, "sd"));
    int i = 0; int j = 0;
    for (int k = p; k <= r; k++) {
        if (Left[i].first >= Right[j].first) {
            v[k] = Left[i];
            i++;
        }
        else {
            v[k] = Right[j];
            j++;
        }
    }
}

void mergesort(vector<pair<int, string> >& v, int p, int r) {
    int q;
    if (p < r) {
        q = (p + r) / 2;
        mergesort(v, p, q);
        mergesort(v, q + 1, r);
        merge(v, p, q, r);
    }
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

    // merge sort
    mergesort(v, 0, v.size() - 1);

    for (int i = 0; i < n; i++) {
        cout << v[i].first << ' ' << v[i].second << endl;
    }

    return 0;
}