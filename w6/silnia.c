
long long fun(long long n)
{
	if (n == 0)
		return 1;
	return n * fun(n - 1);
}
