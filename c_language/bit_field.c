//http://blog.csdn.net/lovecodeless/article/details/23270911
//2014-06-03
//shaokc
#include<stdio.h>
struct
{
    unsigned a  :20;
    unsigned b  : 6;
    unsigned c  : 2;
}flags;       //20+6+2<32（一个机器字的位宽）故可在1个机器字内存储
struct
{
    unsigned d  :20;
    unsigned e  :6;   //32-（20+6）=6该机器字剩余6bit
    unsigned f  :20;  //6bit不够存储f,f将在下一个机器字边界开始存储
}flagscopy;  //20+6+20>32（一个机器字的位宽）故需在2个机器字内存储
int main(){

    flags.c=3;             //位字段初始化与使用     
    printf("Flags.c is : %d \n",flags.c);

    int n=sizeof(flags);   //flags占一个机器字，sizeof为4
    printf("Size of flags :%d\n",n);
    
    n=sizeof(flagscopy);   //flagscopy占两个机器字，sizeof为8
    printf("Size of flagscopy :%d\n",n);
    return 0;
}
