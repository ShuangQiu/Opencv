#include<stdio.h>
#include<ctype.h>

int main(int argc,char *argv[])
{
    char *c;
    int   i;
    c = argv[0];
//    printf("%d\n",tolower(argv[0]));
//    printf("%s\n",c);
//    printf("%s\n",*c);
     for(i=0;c[i];i++)
     {
        printf("%d\n",tolower(c[i]));
     }

//    printf("%s\n",argv[0]);
    return 0;
}

