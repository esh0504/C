#include <iostream>
using namespace std;
double boonchim(int num) {
	double degree = num * 6;
	return degree;
}

double sichim(int num,int boon) {
	double degree = num * 30 + boon * 0.5;
	return degree;
}


int main(void) {
	int testCase;
	cin >> testCase;
	for (int i = 0; i < testCase; i++) {
		int si, boon;
		cin >> si;
		cin >> boon;
		double degree = sichim(si, boon) - boonchim(boon);
		if (degree < 0) {
			degree *= -1;
		}
		if (degree > 180) {
			degree = 360 - degree;
		}
		printf("%d\n",(int)degree);
	}
}


