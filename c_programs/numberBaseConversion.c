#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <ctype.h>

// Function to convert a character to its corresponding integer value
int charToValue(char c) {
    if (isdigit(c)) return c - '0';                  // '0'-'9' -> 0-9
    else if (isalpha(c)) return toupper(c) - 'A' + 10; // 'A'-'Z' -> 10-35
    return -1;  // Error case: character is not valid
}

// Function to convert an integer value to its corresponding character
char valueToChar(int value) {
    if (value >= 0 && value <= 9) return value + '0';      // 0-9 -> '0'-'9'
    else if (value >= 10 && value <= 35) return value - 10 + 'A'; // 10-35 -> 'A'-'Z'
    return '?';  // Error case
}

int toDecimal(const char *input, int baseFrom) {    // ensure original input not modified
    int res = 0;
    int power = 1;      // initialised to baseFrom^0
    for (int i = strlen(input) - 1; i >= 0; i--) {
        int value = charToValue(input[i]);          // convert char representation to int value
        if (value < 0 || value >= baseFrom) {
            printf("Error: Invalid digit '%c' for base %d\n", input[i], baseFrom);
            exit(1);
        }
        res += value * power;
        power *= baseFrom;
    }
    return res;
}

void fromDecimal(int input, int baseTo, char *result) {
    int i = 0;
    while (input > 0) {
        int remainder = input % baseTo;
        result[i++] = valueToChar(remainder);
        input /= baseTo;
    }
    result[i] = '\0';
    // Reverse the result string
    for (int j = 0; j < i / 2; j++) {
        char temp = result[j];
        result[j] = result[i - j - 1];
        result[i - j - 1] = temp;
    }
}

void integerConversion(const char *input, int baseFrom, int baseTo, char *result) {
    if (baseFrom < 2 || baseTo < 2 || baseFrom > 36 || baseTo > 36) {
        printf("Error: Base must be between 2 and 36.\n");
        exit(1);
    }
    // Convert from the source base to decimal
    int decimalValue = toDecimal(input, baseFrom);
    // Convert from decimal to the target base
    if (decimalValue == 0) {
        result[0] = '0';
        result[1] = '\0';
    } else {
        fromDecimal(decimalValue, baseTo, result);
    }
}

int main() {

    return 0;
}
