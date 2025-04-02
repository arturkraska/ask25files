#include <stdio.h>

long long fun(long long x);

int main()
{
	long long n;
	scanf("%lld", &n);
	long long r = fun(n);
	printf("%lld\n", r);
	return 0;
}