"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var fs = require("fs");
// Function to generate a random binary string of length 256
function generateBinaryString(length) {
    if (length === void 0) { length = 256; }
    var result = '';
    for (var i = 0; i < length; i++) {
        result += Math.random() < 0.5 ? '0' : '1';
    }
    return result;
}
// Function to generate pairs of binary strings
function generateBinaryPairs(numPairs) {
    var pairs = [];
    for (var i = 0; i < numPairs; i++) {
        var binary1 = generateBinaryString();
        var binary2 = generateBinaryString();
        pairs.push("".concat(binary1, ",").concat(binary2));
    }
    return pairs;
}
// Function to write the binary pairs to a file
function writeBinaryPairsToFile(filename, pairs) {
    var fileContent = pairs.join('\n');
    fs.writeFileSync(filename, fileContent);
    console.log("Binary pairs written to ".concat(filename));
}
// Generate 10 pairs of binary strings
var numPairs = 100;
var binaryPairs = generateBinaryPairs(numPairs);
// Write the pairs to 'binaryInput.txt'
writeBinaryPairsToFile('binaryInput.txt', binaryPairs);
