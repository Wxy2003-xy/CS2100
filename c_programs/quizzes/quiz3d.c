#include <stdio.h>
#include <string.h>
typedef struct {
    int x;
    char c[32];
} TTest;

TTest f(TTest);

int main(){
    TTest t1 = {5, "hello world"};
    TTest t2 = f(t1);
    printf("%d %s %d %s\n", t1.x, t1.c, t2.x, t2.c);
    return 0;
}

TTest f(TTest t1) {
    static TTest tmp;
    t1.x--;
    strcpy(t1.c, "penguin");
    tmp = t1;
    return tmp;
}