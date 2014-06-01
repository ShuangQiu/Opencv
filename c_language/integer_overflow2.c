#include <stdio.h>

void main(){
    short len = 0;
    while(len< MAX_LEN) {
        len += readFromInput(fd, buf);
        buf += len;
    }
}
