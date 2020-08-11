#include  <iostream>

using namespace std;

const int ZERO = 0;
const int ONE = 1;
int result = 0;

int sol(int n) {
	if (n == 0) {
		return ZERO;
	}
	else if (n == 1){
		return ONE;
	}
	else {
		return sol(n-1)+sol(n-2);
	}
}

int main(void) {
	int num;
	cin >> num;
	cout << sol(num) << endl;
	return 0;
}