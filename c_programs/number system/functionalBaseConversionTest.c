#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functionalBaseConversionLib.h" // Assume this includes the functional version of convertBase

void runTest(const char *inputFileName, const char *outputFileName) {
    FILE *inputFile = fopen(inputFileName, "r");
    FILE *outputFile = fopen(outputFileName, "r");

    if (!inputFile || !outputFile) {
        printf("Error: Could not open input or output file.\n");
        exit(1);
    }

    char input[256], expectedOutput[256];
    int baseFrom, baseTo;
    int line = 1;

    while (fscanf(inputFile, "%s %d %s %d", input, &baseFrom, expectedOutput, &baseTo) == 4) {
        // Perform the base conversion
        char *result = convertBase(input, baseFrom, baseTo);

        // Compare the result with the expected output
        if (strcmp(result, expectedOutput) != 0) {
            printf("Test failed on line %d:\n", line);
            printf("Input: %s, BaseFrom: %d, Expected: %s, Got: %s, BaseTo: %d\n",
                   input, baseFrom, expectedOutput, result, baseTo);
        } else {
            printf("Test passed on line %d.\n", line);
        }

        // Free the dynamically allocated result
        free(result);

        line++;
    }

    fclose(inputFile);
    fclose(outputFile);
}

int main() {
    runTest("input.txt", "output.txt");
    char binaryArray[256] = {
    '0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0',
    '0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0',
    '0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0',
    '0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0',
    '0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0',
    '0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0',
    '0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0',
    '0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0',
    '0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0',
    '0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0',
    '0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0',
    '0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0',
    '0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0',
    '0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0',
    '0','0','0','0','0','0','0','0','0','0','0','0','0','0','1','1',
    '1','1','0','1','1','1'
    };
    char binaryString[257];

    // Copy the contents of binaryArray to binaryString
    memcpy(binaryString, binaryArray, 256);

    // Add the null terminator at the end
    binaryString[256] = '\0';
    printf("%s", convertBase(binaryArray, 2, 10));
    return 0;
}
