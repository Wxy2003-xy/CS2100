import * as fs from 'fs';

/**
 * Converts a given number to a specified base.
 * 
 * @param num - The number to convert.
 * @param base - The base to convert the number to (2 to 36).
 * @returns The number as a string in the specified base.
 */
function convertToBase(num: number, base: number): string {
    if (base < 2 || base > 36) {
        throw new Error("Base must be in the range 2-36.");
    }

    return num.toString(base).toUpperCase(); // Convert and return in uppercase
}

/**
 * Generates a random integer within a given range.
 * 
 * @param min - Minimum number (inclusive).
 * @param max - Maximum number (inclusive).
 * @returns A random integer between min and max.
 */
function randomInt(min: number, max: number): number {
    return Math.floor(Math.random() * (max - min + 1)) + min;
}

/**
 * Generates a random test case for base conversion.
 * 
 * @returns An object containing the input value, baseFrom, and baseTo.
 */
function generateTestCase(): { inputValue: string; baseFrom: number; baseTo: number } {
    const baseFrom = randomInt(2, 36);
    const baseTo = randomInt(2, 36);
    const inputValue = randomInt(1, 1000000).toString(baseFrom).toUpperCase();  // Convert random number to baseFrom string

    return { inputValue, baseFrom, baseTo };
}

/**
 * Main function to run the test generation and record results.
 */
function main() {
    const inputFilePath = 'input.txt';
    const outputFilePath = 'output.txt';

    // Clear the files if they exist
    fs.writeFileSync(inputFilePath, '');
    fs.writeFileSync(outputFilePath, '');

    for (let i = 0; i < 1000; i++) {
        const { inputValue, baseFrom, baseTo } = generateTestCase();
        
        // Convert the inputValue string back to a number from baseFrom, then convert to baseTo
        const decimalValue = parseInt(inputValue, baseFrom);
        const outputStr = convertToBase(decimalValue, baseTo);  // Convert input to baseTo

        // Write the input and base information to input.txt
        fs.appendFileSync(inputFilePath, `${inputValue} ${baseFrom} ${outputStr} ${baseTo}\n`);

        // Write the output to output.txt
        fs.appendFileSync(outputFilePath, `${outputStr}\n`);
    }

    console.log('Test cases generated and recorded in input.txt and output.txt.');
}

main();
