#include <iostream>
#include <math.h>
using namespace std;
int closestNumber(int n, int m);
int main(void)
{
	int t;
	int n, m;
	cin >> t;
	for (int i = 0; i<t; i++)
	{
		cin >> n >> m;
		cout << closestNumber(n, m) << endl;
	}
	return 0;
}
int closestNumber(int n, int m)
{
	
	int small = n / m;
	int big = small + 1;
	if (n*m<0) {
		big = small - 1;
	}
	
	
	int small2 = int(sqrt((n - (small*m))*(n - (small*m))));
	int big2 = int(sqrt((n - (big*m))*(n - (big*m))));
	if (big2 < small2) {
		return big * m;
	}
	else if (big2 > small2) {
		return small * m;
	}
	else {
		int bigm = big * m;
		int smallm = small * m;
		int bigm2 = bigm;
		int smallm2 = smallm;
		if (bigm2 < 0) {
			bigm2 = bigm * -1;
		}if (smallm2 < 0) {
			smallm2 = smallm * -1;
		}
		if (bigm2 > smallm2) {
			return bigm;
		}
		else {
			return smallm;
		}


	}
}
