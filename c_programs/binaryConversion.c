#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NUMBERS 10000  

int toDecimal(int input, int baseFrom) {
    int tmp = input;
    int power = 1;
    int res = 0;
    
    while (tmp > 0) {
        int remainder = tmp % 10;
        res += power * remainder;
        power *= baseFrom;
        tmp /= 10;
    }
    return res;
}

int fromDecimal(int input, int baseTo) {
    int tmp = input;
    int power = 1;
    int res = 0;

    while (tmp > 0) {
        int remainder = tmp % baseTo;
        res += power * remainder;
        tmp /= baseTo;
        power *= 10;
    }
    return res;
}

int integerConversion(int input, int baseFrom, int baseTo) {
    if (baseFrom < 2 || baseTo < 2) {
        printf("Error: Base must be at least 2.\n");
        exit(1);  // Exit with an error code if base is invalid
    }
    
    // If the input is already in decimal, directly convert it to the target base
    if (baseFrom == 10) {
        return fromDecimal(input, baseTo);
    }
    
    // Otherwise, first convert to decimal, then to the target base
    int decimalValue = toDecimal(input, baseFrom);
    return fromDecimal(decimalValue, baseTo);
}

int main() {
    FILE *filePointer;
    char filename[] = "example.txt";  
    char line[1024];                   
    int numbers[MAX_NUMBERS];         
    int count = 0;                    
    filePointer = fopen(filename, "r");
    if (filePointer == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return 1;
    }
    while (fgets(line, sizeof(line), filePointer) != NULL) {   
        if (sscanf(line, "%d", &numbers[count]) == 1) {
            count++;
        }
    }
    fclose(filePointer);
    printf("%d", toDecimal(1101100010, 2));




    return 0;
}
