#include<iostream>
#include<string>
using namespace std;

int main() {
	string a;
	int b[26] = { 0 };
	cin >> a;
	for (int i = 0; i < a.size(); i++) {
		b[a[i] - 97]++;
	}
	for (int i = 0; i < 26; i++) cout << b[i] << ' ';
}