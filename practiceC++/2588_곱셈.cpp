#include <iostream>
using namespace std;

int one(int num)
{
	return num % 10;
}
int de(int num)
{
	return (num % 100 - one(num))/10;
}
int hun(int num)
{
	return num / 100;
}
int main(void)
{
	int num1,num2;
	cin >> num1 >> num2;
	int resu1, resu2, resu3;
	resu1 = one(num2) * num1;
	resu2 = de(num2)*num1;
	resu3 = hun(num2)*num1;
	cout << resu1 << endl << resu2 << endl << resu3 << endl;
	cout << resu1 + resu2 * 10 + resu3 * 100;
	return 0;
}