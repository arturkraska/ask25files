#include <stdio.h>

void fun(const char* str)
{
    printf(str);
}

int main()
{
    fun("Line 1\n");
    fun("Line 2\n");
    return 0;
}