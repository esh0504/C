#include<iostream>

using namespace std;

int sol(int a ,int count,int n,int *attr) {
	if (a == 0) {
		return count;
	}
	else {
		for (int i = 0; i < n; i++) {
			if (attr[i] < a) {
				return sol(a - attr[i], count + 1,n, attr);
			}
			else if (attr[i] == a) {
				return count + 1;
			}
			else {
				continue;
			}
		}
	}
}

int main() {
	int arr[11] = { 0 };
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[n-i-1];
	}
	
	
	int ans = sol(k, 0,n, arr);
	cout << ans << endl;
}