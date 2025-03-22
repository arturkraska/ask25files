/*
gcc main.c plik.c
gcc plik.c -S -O2
gcc plik.s plik.c
gcc plik.s main.c -c
objdump -d plik.o
*/

#include <stdio.h>

int fun(int a, int b);

int main()
{
    int x, y;
    scanf("%d %d", &x, &y);
    printf("%d\n", fun(x, y));
    return 0;
}