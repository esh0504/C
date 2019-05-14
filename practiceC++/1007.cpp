#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;

double distance(int x, int y) {
	double x2 = x * x;
	double y2 = y * y;
	return x2+y2;
}

int main(void) {
	double a = distance(0, 1);
	printf("%d",a );
	return 0;
}
