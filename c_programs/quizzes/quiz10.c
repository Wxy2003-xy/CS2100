#include <stdio.h>
int* fun(int *);
int main(){
    int a = 140;
    int *p;
    p = fun(&a);
    (*p)--;
    printf("%d", a);
    return 0;
}
int *fun(int *x) {  
    (*x)*=-235;
    return x;
}