//stdout和stderr是不是同设备描述符。stdout是块设备，stderr则不是。//
//对于块设备，只有当下面几种情况下才会被输入，//
//1）遇到回车，
//2）缓冲区满，
//3）flush被调用。
//而stderr则不会。
//Ref   http://coolshell.cn/articles/945.html
//shaokc 
//2014-06-02

#include <stdio.h>
 
int main()
{
    int a = (1,2);
    printf("a : %d\n",a);
    return 0;
}
