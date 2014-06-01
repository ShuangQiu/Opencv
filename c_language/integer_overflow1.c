#include <stdio.h>

void main(){
    signed char x = 0x7f;
    signed char y = 0x05;
    signed char r = x * y;
    printf("%d\n", r);
}
