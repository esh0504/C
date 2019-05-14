#include<iostream>
#include<stdio.h>
#include<map>
#include<vector>
using namespace std;
int main(void) {


vector<int> score = { 0 };
int a;

for (int i = 0; i < 5; i++) {
	cin >> a;
	if (a < 40) {
		a = 40;
	}
	score.push_back(a);

}
int sum = 0;
for (int j = 1; j <= 5; j++) {
	sum += score[j];
	}
cout << sum / 5 << endl;
}