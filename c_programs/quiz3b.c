#include <stdio.h>

void f(char *);

int main() {
    char str[] = "TREE.";
    f(str);
    printf("%s", str);
}

void f(char *c) {
    while(*c) {
        (*c)++;
        c++;
    }
}