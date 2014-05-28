#include <stdlib.h>
 
struct X{ int a; char b; int c;};
struct X x1;
printf("%d,", sizeof(struct x1));

struct Y{ int a; char b; int c; char d;};
struct Y y1;
printf("%d\n", sizeof(struct y1));
