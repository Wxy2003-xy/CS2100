#include <stdio.h>
#include <stdlib.h>
int main(){
    int i = 0, j = 0;
    int *m = (int *)malloc(2 * sizeof(int));
    int *k = &j;
    int *p = &i; 
    int **q = &k; 
    m[0]=5, m[1] = 6;
    printf("%ld\n", sizeof(int));
    printf("%p, %p, %d, %d\n", p, q, m[0], m[1]);
    printf("%p, %p, %d, %d\n", &m[0], &m[1], m[0], m[1]);
    
    p = &m[0];
    q = &p;
    p++;
    (*p)--;  
    (**q)--;   

    printf("%p, %p, %d, %d\n", p, q, m[0], m[1]);
    return 0;
}