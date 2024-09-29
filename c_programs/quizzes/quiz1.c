#include <pthread.h>
#include <stdio.h>

#define MESSAGE "Hello World"

int main() {
            int i, j;
            for (i = 0; i < 3; i++) {
                for (j = 0; j < 3; j++) {
                    printf("i: %d; j: %d\n", i, j);
                    if (j > 1) 
                        continue;
                    printf("st\n");
                    }
                if (i > 0) 
                    break;
            }

}