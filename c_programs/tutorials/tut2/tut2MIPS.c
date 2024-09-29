#include <stdint.h>  
#include <stdio.h>
int main() {
    uint32_t s0 = 31; 
    uint32_t t0 = s0;  
    uint32_t t1 = 0x80000000;  

    printf("%d\n", s0);
    printf("%d\n", t0);
    printf("%d\n", t1);
    while (t0 != 0) {  
        uint32_t t2 = t0 & 1;  
        if (t2 != 0) {         
            s0 = s0 ^ t1;      
        }
        t0 = t0 >> 1;    
        printf("%d\n", t0);
    }

    
    printf("%d\n", s0);
    printf("%d\n", t0);
    printf("%d\n", t1);

    return 0;
}
