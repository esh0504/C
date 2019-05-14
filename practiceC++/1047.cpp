#include<iostream>
#include<stdio.h>
#include <map>
using namespace std;
int main(void) {
	int numOfTree;
	cin >> numOfTree;
	auto mylist[41];
	for (int i = 0; i < numOfTree; i++) {
		map<string, int> tree;
		int x, y, num;
		cin >> x >> y >> num;
		tree["x"] = x;
		tree["y"] = y;
		tree["num"] = num;
		mylist.push_back(tree);

	}
}