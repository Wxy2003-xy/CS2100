#include <stdio.h>

int main(){
    int x = 1993, y = 602;
    int *p, *q, x = 5, y = 2;
    p = &x;
    q = &y;
    *p = *q + 1;
    printf("%d  %d", x, y);


    return 0;
}