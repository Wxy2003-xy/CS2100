#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myFunctions.h"

void runTest(const char *inputFileName, const char *outputFileName) {
    FILE *inputFile = fopen(inputFileName, "r");
    FILE *outputFile = fopen(outputFileName, "r");

    if (!inputFile || !outputFile) {
        printf("Error: Could not open input or output file.\n");
        exit(1);
    }

    char input[256], expectedOutput[256], result[256];
    int baseFrom, baseTo;
    int line = 1;

    while (fscanf(inputFile, "%s %d %s %d", input, &baseFrom, expectedOutput, &baseTo) == 4) {
        // Perform the integer conversion
        integerConversion(input, baseFrom, baseTo, result);

        // Compare the result with the expected output
        if (strcmp(result, expectedOutput) != 0) {
            printf("Test failed on line %d:\n", line);
            printf("Input: %s, BaseFrom: %d, Expected: %s, Got: %s, BaseTo: %d\n",
                   input, baseFrom, expectedOutput, result, baseTo);
        } else {
            printf("Test passed on line %d.\n", line);
        }

        line++;
    }

    fclose(inputFile);
    fclose(outputFile);
}

int main() {
    runTest("input.txt", "output.txt");
    return 0;
}
