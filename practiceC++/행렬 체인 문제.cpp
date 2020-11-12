#include <vector>
#include <climits>
#include <iostream>
#define MIN(A, B) ((A)>(B)?(B):(A))

using namespace std;

int main(void) {
    int n;
    vector<int> v;

    cin >> n;
    for (int i = 0; i < n + 1; i++) {
        int d;
        cin >> d;
        v.push_back(d);
    }

    long long m[1001][1001];

    for (int l = 0; l < n; l++)
    {
        for (int i = 1; i <= n - l; i++)
        {
            int j = i + l;
            if (j == i)
            {
                m[i][j] = 0;
                continue;
            }
            m[i][j] = LLONG_MAX;
            for (int k = i; k <= j - 1; k++) {
                m[i][j] = MIN(m[i][j], m[i][k] + m[k + 1][j] + v[i - 1] * v[k] * v[j]);
            }
        }
    }

    cout << m[1][n] << endl;

    // solve here and print the result using cout 
    return 0;
}