#include <stdio.h>

// void f(int);

// int main() {

//     int x[5] = {3, 39, 39, 12, 90};
//     f(x[2]);
//     printf("%d\n", x[4]); // This line

// }

// void f(int y) {

//     y*=2;
// }
int f(int *);

int main() {

    int a[] = {-64, -7, 40, 78, 47, -3, -86, 81, 24, 95};
    int x;
    x = f(&a[3]);
    printf("%d\n", x);
}

int f(int *p) {
    return *(p - 3 )  + *(p + 3 ) - *(p - 1 );
}