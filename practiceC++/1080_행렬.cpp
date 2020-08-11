#include <iostream>
#include <string>
using namespace std;

void change(int i, int j,int (*ptr)[51]) {
	for (int k = i; k < i+3; k++) {
		for (int l = j; l < j+3; l++) {
			if (ptr[k][l] == 1) {
				ptr[k][l] = 0;
			}
			else {
				ptr[k][l] = 1;
			}
		}
	}
}


int main() {
	int n, m;
	int count = 0;
	cin >> n >> m;
	int arr[51][51] = { 0 };
	
	int arrB[51][51] = { 0 };
	for (int i = 0; i < n; i++) {
		string word;
		cin >> word;
		for (int j = 0; j < m; j++) {
			arr[i][j] = (int)word[j]-48;
		}
	}

	for (int i = 0; i < n; i++) {
		string word;
		cin >> word;
		for (int j = 0; j < m; j++) {
			arrB[i][j] = (int)word[j]-48;
		}
	}

	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 2; j++) {
			if (arr[i][j] != arrB[i][j]) {
				count++;
				change(i, j,arr);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] != arrB[i][j]) {
				count = -1;
				i = n;
				break;
			}
		}
	}
	cout << count << endl;
}