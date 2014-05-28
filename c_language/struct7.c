#include<stdio.h>

struct X { int a; char b; int c; };
//struct Y { int a; char b; int  c; char d;};  //16 byte
struct Y { int a; char b; char c; int  d;};  //12 byte

int main(){
    printf("%d\n", sizeof(struct X));
    printf("%d\n", sizeof(struct Y));
}

