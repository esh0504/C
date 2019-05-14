#include<iostream>
#include<vector>
using namespace std;
int main(void) {
	vector<int> num = { 0 };
	for (int i = 0; i < 8; i++) {
		int a;
		cin >> a;
		num.push_back(a);
	}
	int count = 0;
	int count2=0;
	for (int i = 1; i < 9; i++) {
		if (num[i] == i) {
			count += 1;
		}
		else if (num[i] == 9 - i) {
			count2 += 1;
		}
	}
		
	if (count > 7){              
		printf("ascending");
	}
	else if (count2 > 7){
		printf("descending");
	}
	else {
		printf("mixed");
	}
}
