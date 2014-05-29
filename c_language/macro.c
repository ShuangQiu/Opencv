//用可变参数宏(variadic macros)传递可变参数表
// __VA_ARGS__
//C99 引入了对参数个数可变的函数式宏的正式支持。在宏 ``原型" 的末尾加上符号 ... (就像在参数可变的函数定义中), 宏定义中的伪宏 __VA_ARGS__ 就会在调用是 替换成可变参数。 

#include <stdio.h>
 
#define func(...) myfunc((struct mystru){__VA_ARGS__})   //what is " __VA_ARGS__ "
 
struct mystru { const char *name; int number; };
 
void myfunc(struct mystru ms )
{
  printf("%s: %d\n", ms.name ?: "untitled", ms.number);
}
 
int main(int argc, char **argv)
{
  func("three", 3);
  func("hello");
  func(.name = "zero");
  func(.number = argc, .name = "argc",);    // what is "argc"
  func(.number = 42);
  return 0;
}
