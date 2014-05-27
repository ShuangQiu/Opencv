#include <stdio.h>

struct test{
    int i;
    char *p;
};

int main(int argc, char** argv) {
//    struct foo f={0};
    struct test t;
//        printf( f.a->s);
    printf("%x\n", t.p);
    return 0;
}
