#include <stdio.h>

int sum(int n, int *tab);

int arr[] = {7, 9, 13, 17, 19};
char c, empty[100];

int main()
{
    printf("main: 0x%x\n", *(int*)&main);
    int n = 3;
    printf("%d\n", sum(n, arr));
    return 0;
}