#include <stdio.h>

int main(){
    int x = 0;
    float y = 0;
    int i, j;

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            x++;
            if (!(j % 2)) {
                continue;
            }
            y += x / 2;
        }
        if (!(i % 3)) {
            break;
        }
    }
    
    printf("x=%d; y=%f", x, y);




    return 0;
}