#include <stdio.h>

void main(){
    unsigned char x = 0xff;
    printf("%d\n", ++x);
    signed char y =0x7f; //注：0xff就是-1了，因为最高位是1也就是负数了
    printf("%d\n", ++y);
}
