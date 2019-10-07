#include <stdio.h>

long long int gcd(long long int n, long long int m)
{
	if (m == 0)    return n;
	return gcd(m, n % m);
}

int main()
{
	long long int a, b;

	scanf("%lld %lld", &a, &b);

	for (int i = 1; i <= gcd(a, b); i++) {
		printf("1");
	}
	printf("\n");

	return 0;
}
