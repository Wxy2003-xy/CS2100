#include <stdio.h>

int main(){
    int *p, *q, x=2376, y=2674;
    printf("%p, %p, %d, %d\n", p, q, x, y);
    printf("%p, %p, %d, %d\n", &x, &y, x, y);

    p = &x;
    q = &y;
    *p = *q + 1;
    printf("%p, %p, %d, %d\n", p, q, x, y);


    return 0;
}