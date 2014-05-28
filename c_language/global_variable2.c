//http://coolshell.cn/articles/5761.html
//gcc -o  global_variable2 global_variable2.c -g -O     : will print a random value
//gcc -o  global_variable2 global_variable2.c -g        : most compiler will print 42

#include <stdio.h>

void foo(void)
{
    int a;
    printf("%d\n", a);
}

void bar(void)
{
    int a = 42;
}

int main(void)
{
    bar();
    foo();
}
