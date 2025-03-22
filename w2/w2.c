#include <stdio.h>
#include <stdint.h>

int main()
{
    uint32_t x = (uint32_t)-0x134 >> 4;

    printf("int:  %d\n", x); 
    printf("uint: %u\n", x);  
    printf("hex:  %X\n", x);  
    printf("oct:  %o\n", x);  
    printf("bin:  %032b\n", x);  

    printf("size: %d\n", sizeof(char*));  

    
    int32_t t[] = {1, 40, 0x89ABCDEF};
    unsigned char *c = t;

    printf("addr: %p\n", c);

    for(int i=0; i<12; i++)
        printf("%02x ", c[i]);
    printf("\n");
    
    return 0;
}