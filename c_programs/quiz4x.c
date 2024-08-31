#include <stdio.h>
#include <stdlib.h>
int main(){
    int i = 0, j = 0;
    int *k = &j;
    int *p = &i; 
    int **q = &k; 
    int x=5, y = 6;
    printf("%ld\n", sizeof(int));
    printf("%p, %p, %d, %d\n", p, q, x, y);
    printf("%p, %p, %d, %d\n", &x, &y, x, y);
    
    p = &x;
    q = &p;
    p++;
    (*p)--;  
    (**q)++;    // EXC_BAD_ACCESS

    printf("%p, %p, %d, %d\n", p, q, x, y);
    return 0;
}