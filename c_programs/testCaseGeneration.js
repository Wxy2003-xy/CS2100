"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var fs = require("fs");
/**
 * Converts a given number to a specified base.
 *
 * @param num - The number to convert.
 * @param base - The base to convert the number to (2 to 36).
 * @returns The number as a string in the specified base.
 */
function convertToBase(num, base) {
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
function randomInt(min, max) {
    return Math.floor(Math.random() * (max - min + 1)) + min;
}
/**
 * Generates a random test case for base conversion.
 *
 * @returns An object containing the input value, baseFrom, and baseTo.
 */
function generateTestCase() {
    var baseFrom = randomInt(2, 36);
    var baseTo = randomInt(2, 36);
    var inputValue = randomInt(1, 1000000).toString(baseFrom).toUpperCase(); // Convert random number to baseFrom string
    return { inputValue: inputValue, baseFrom: baseFrom, baseTo: baseTo };
}
/**
 * Main function to run the test generation and record results.
 */
function main() {
    var inputFilePath = 'input.txt';
    var outputFilePath = 'output.txt';
    // Clear the files if they exist
    fs.writeFileSync(inputFilePath, '');
    fs.writeFileSync(outputFilePath, '');
    for (var i = 0; i < 1000; i++) {
        var _a = generateTestCase(), inputValue = _a.inputValue, baseFrom = _a.baseFrom, baseTo = _a.baseTo;
        // Convert the inputValue string back to a number from baseFrom, then convert to baseTo
        var decimalValue = parseInt(inputValue, baseFrom);
        var outputStr = convertToBase(decimalValue, baseTo); // Convert input to baseTo
        // Write the input and base information to input.txt
        fs.appendFileSync(inputFilePath, "".concat(inputValue, " ").concat(baseFrom, " ").concat(outputStr, " ").concat(baseTo, "\n"));
        // Write the output to output.txt
        fs.appendFileSync(outputFilePath, "".concat(outputStr, "\n"));
    }
    console.log('Test cases generated and recorded in input.txt and output.txt.');
}
main();
