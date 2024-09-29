#include <stdio.h>

type func(int x) {
    // $v0 -> count
    // $t0 -> i
    int i;
    int count;

    i = 32;
    count = 0;

    // L3:
    {
        int x;  // $a0 -> x
        if (x < 0) {     
        // L6:
            i--;
        }
    }
    // L7:
    {
        if (i == 0) {
            return ; // L8;
        }
        x <<= 1;
    }
}


int main(){

    return 0;
}