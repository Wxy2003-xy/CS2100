#include <stdio.h>

// Student number: A0282500R
// Student name: Wang Xiyu
// Tutorial Group: T01

// Function prototype
int func(int a0);

int func(int a0) {
    int t0 = 32;  // $t0;
    int v0 = 0;  // $v0;

    while (t0 > 0) {  // L3
        if (a0 >= 0) {
            v0++;        // L6
        }
        t0--;
        if (t0 == 0) {
            return v0;
        }
        a0 <<= 1;
    }
    return v0;
}
