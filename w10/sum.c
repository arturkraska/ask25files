
static int cnt = 3;

int sum(int n, int *tab)
{
    static int cnt = 0;
    cnt++;
    int res = 0;
    for(int i = 0; i < n; i++)
        res += tab[i];
    return res;
}

int f()
{
    cnt++;
}
