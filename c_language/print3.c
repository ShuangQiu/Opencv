//程序会输出4321，你知道为什么吗？要知道为什么，你需要知道printf的返回值是什么。printf返回值是输出的字符个数。
//Ref   http://coolshell.cn/articles/945.html
//2014-06-02
//shaokc

#include <stdio.h>
int main()
{
    int i=43;
    printf("%d\n",printf("%d",printf("%d",i)));
    return 0;
}
