#include <iostream>
#include <string>
#include<vector>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<char>> v;
	for (int i = 0; i < n; i++) {
		string word;
		cin >> word;
		vector<char> v2;
		for (int j = 0; j < m; j++) {
			v2.push_back(word[j]);
		}
		v.push_back(v2);
	}
	for(int i=0;i<n-)
}