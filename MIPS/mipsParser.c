#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define a structure to represent a MIPS instruction
typedef struct {
    char opcode[10];
    char rd[5];
    char rs[5];
    char rt[5];
    int immediate;
} MIPSInstruction;

// Function to parse a single line of MIPS instruction
void parseMIPSInstruction(char *line, MIPSInstruction *instruction) {
    char *token = strtok(line, " ,()\n");

    if (token == NULL) return;

    // Parse the opcode
    strcpy(instruction->opcode, token);
    token = strtok(NULL, " ,()\n");

    // Parse different instruction formats
    if (strcmp(instruction->opcode, "add") == 0 || strcmp(instruction->opcode, "sub") == 0) {
        // Format: add rd, rs, rt
        strcpy(instruction->rd, token);
        token = strtok(NULL, " ,()\n");
        strcpy(instruction->rs, token);
        token = strtok(NULL, " ,()\n");
        strcpy(instruction->rt, token);
    } else if (strcmp(instruction->opcode, "lw") == 0 || strcmp(instruction->opcode, "sw") == 0) {
        // Format: lw/sw rt, offset(rs)
        strcpy(instruction->rt, token);
        token = strtok(NULL, " ,()\n");
        instruction->immediate = atoi(token);
        token = strtok(NULL, " ,()\n");
        strcpy(instruction->rs, token);
    } else {
        printf("Unknown opcode: %s\n", instruction->opcode);
    }
}

// Function to display the parsed instruction
void displayInstruction(MIPSInstruction *instruction) {
    printf("Opcode: %s\n", instruction->opcode);
    if (strlen(instruction->rd) > 0) printf("rd: %s\n", instruction->rd);
    if (strlen(instruction->rs) > 0) printf("rs: %s\n", instruction->rs);
    if (strlen(instruction->rt) > 0) printf("rt: %s\n", instruction->rt);
    if (instruction->immediate != 0) printf("Immediate: %d\n", instruction->immediate);
    printf("\n");
}

int main() {
    // Open the MIPS instruction file
    FILE *file = fopen("MIPS_input.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    char line[100];
    MIPSInstruction instruction;

    // Read the file line by line
    while (fgets(line, sizeof(line), file)) {
        // Initialize the instruction structure
        memset(&instruction, 0, sizeof(MIPSInstruction));

        // Parse the line
        parseMIPSInstruction(line, &instruction);

        // Display the parsed instruction
        displayInstruction(&instruction);
    }

    fclose(file);
    return 0;
}
