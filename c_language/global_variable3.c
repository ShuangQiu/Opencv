//http://coolshell.cn/articles/5761.html
//gcc -o  global_variable2 global_variable2.c -g -O     : will print a random value
//gcc -o  global_variable2 global_variable2.c -g        : most compiler will print 42

#include<stdio.h>

int b(void){printf("3");return 3;}
int c(void){printf("4");return 4;}

int main(void){
    int a = b() +c();
    printf("%d\n",a);
}
