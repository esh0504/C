#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int count(string a) {
	int lena = a.size();
	int count = 0;
	for (int i = 1; i < lena; i++) {
		char ac = a.at(i);
		if (ac == ' '&& a.at(i-1)!=' ') {
			count += 1;
		}
		if (i == lena - 1) {
			if (a.at(i) == ' ') {
				count -= 1;
			}
		}
	}return count+1;



}
int main(void) {
	string a;
	getline(cin, a);
	cout << count(a) << endl;
	return 0;
}