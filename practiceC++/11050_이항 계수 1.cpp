#include <iostream>

using namespace std;

int main() {
	int n, k;
	int result = 1;
	int de = 1;
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		result = result * (n - i);
		de = (i+1) * de;
	}
	cout << result / de << endl;
	
}