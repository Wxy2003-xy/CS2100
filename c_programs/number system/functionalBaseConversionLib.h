#ifndef MY_FUNCTIONS_H
#define MY_FUNCTIONS_H
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
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

// Function to convert a number from base 'fromBase' to base 10
int toBase10(const char *number, int fromBase) {
    int length = strlen(number);
    int result = 0;
    int power = 1;

    for (int i = length - 1; i >= 0; i--) {
        int value = charToValue(number[i]);
        if (value < 0 || value >= fromBase) {
            printf("Invalid digit '%c' for base %d\n", number[i], fromBase);
            return -1;
        }
        result += value * power;
        power *= fromBase;
    }
    return result;
}

// Function to convert a number from base 10 to base 'toBase'
char* fromBase10(int number, int toBase) {
    char *result = malloc(100 * sizeof(char)); // Dynamically allocate memory for the result
    int index = 0;

    do {
        result[index++] = valueToChar(number % toBase);
        number /= toBase;
    } while (number > 0);

    result[index] = '\0';

    // Reverse the result string
    for (int i = 0; i < index / 2; i++) {
        char temp = result[i];
        result[i] = result[index - i - 1];
        result[index - i - 1] = temp;
    }

    return result; // Return the result string
}

// Function to convert a number from 'fromBase' to 'toBase'
char* convertBase(const char *number, int fromBase, int toBase) {
    int base10 = toBase10(number, fromBase);
    if (base10 >= 0) {
        return fromBase10(base10, toBase);
    }
    return NULL;
}
#endif