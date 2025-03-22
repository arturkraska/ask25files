#include <stdio.h>

union fi
{
    int i;
    float f;
};
union fi liczba;

int main()
{
    float f = 15213;
    printf("%f\n", f);
    int i = f;
    printf("%d\n", i);
    printf("0b%032b\n\n", i);
    
    i = *(int *)&f;
    printf("0x%X\n", i);
    printf("0b%032b\n\n", i);
    
    liczba.f = 9;
    printf("%f\n", liczba.f);
    printf("0b%032b\n\n", liczba.i);
    
    int x = 0xC0A00000;
    float f2 = *(float *)&x;
    printf("%f\n", f2);
    
    return 0;
}