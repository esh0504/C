#include <iostream>
#include <string>

using namespace std;

bool check(string word) {
	if (word.substr(0,3)=="100") {
		int i = 3;
		while (word[i]=='0') {
			i++;
			if (i > word.size() - 1) {
				return false;
			}
		}
		while (word[i] == '1') {
			if (i == word.size() - 1) {
				return true;
			}
			if (word[i] == '1'&&word.substr(i + 1, 3) == "100") {
				return check(word.substr(i + 1));
			}
			i++;
		}
		return(check(word.substr(i)));
	}
	else if (word.substr(0, 2) == "01") {
		if (word.size()==2){
			return true;
		}
		return check((word.substr(2)));
	}
	else {
		return false;
	}
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		string word;
		cin >> word;
		bool p = check(word);
		if (p) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
}