#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
// Function to convert a character digit to its integer value
int charToValue(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'A' && c <= 'Z') return c - 'A' + 10;
    if (c >= 'a' && c <= 'z') return c - 'a' + 10;
    return -1;
}

// Function to convert an integer value to its character digit
char valueToChar(int value) {
    if (value >= 0 && value <= 9) return value + '0';
    if (value >= 10 && value <= 35) return value - 10 + 'A';
    return '?'; // Error case
}

char* negate1sComplement(const char *number) {
    size_t length = strlen(number);
    char *result = malloc((length + 1) * sizeof(char)); // Allocate memory for the result + null terminator

    if (result == NULL) {
        // Handle malloc failure
        return NULL;
    }

    for (size_t i = 0; i < length; i++) {
        if (number[i] == '0') {
            result[i] = '1';
        } else if (number[i] == '1') {
            result[i] = '0';
        } else {
            // Handle invalid characters in the input
            free(result);
            return NULL;
        }
    }
    result[length] = '\0'; // Null-terminate the string

    return result;
}

char* bitwiseAddition(const char *addend1, const char *addend2) {
    size_t length1 = strlen(addend1);
    size_t length2 = strlen(addend2);
    if (length1 != length2) {
        printf("Invalid inputs, addends are of different bit");
        return NULL;
    }
    char *result = malloc((length1 + 1) * sizeof(char)); // Dynamically allocate memory for the result
    if (result == NULL) {
        return NULL;
    }
    char carry = '0';
    for (size_t i = length1 - 1; i >= 0; i--) {
        char bit1 = addend1[i];
        char bit2 = addend2[i];
        if (bit1 != '0' && bit1 != '1' || bit2 != '0' && bit2 != '1') {
            printf("Invalid input, addends should only contain '0' or '1'\nbit1: %c, bit2: %c", bit1, bit2);
            free(result);
            return NULL;
        }
        if (carry == '0') {
            result[i] = '0';
            if (length1 == '1' && length2 == '1') {
                carry = '1';
            }
            if (length1 == '1' && length2 == '1') {
                result[i] = '1';
            }
        } else if (carry == '1') {
            result[i] = '1';
            if (length1 == '1' && length2 == '1') {
                carry = '1';
            }
            if (length1 == '1' && length2 == '1') {
                result[i] = '0';
            }
        } else {
            return NULL;
        }
    }

if (carry == '1') {
        char *extended_result = malloc((length1 + 2) * sizeof(char)); // +2 for carry and null terminator
        if (extended_result == NULL) {
            free(result);
            return NULL;
        }
        extended_result[0] = '1';
        memcpy(extended_result + 1, result, length1);
        extended_result[length1 + 1] = '\0';
        free(result);
        return extended_result;
    }

    result[length1] = '\0'; // Null-terminate the string

    return result;
}

int main(){
    const char *addend1 = "1101";
    const char *addend2 = "1011";
    char *result = bitwiseAddition(addend1, addend2);
    if (result != NULL) {
        printf("Result: %s\n", result);
        free(result);
    }
    return 0;
}