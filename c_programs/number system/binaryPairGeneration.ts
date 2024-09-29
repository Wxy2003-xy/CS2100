import * as fs from 'fs';

// Function to generate a random binary string of length 256
function generateBinaryString(length: number = 256): string {
    let result = '';
    for (let i = 0; i < length; i++) {
        result += Math.random() < 0.5 ? '0' : '1';
    }
    return result;
}

// Function to generate pairs of binary strings
function generateBinaryPairs(numPairs: number): string[] {
    const pairs: string[] = [];
    for (let i = 0; i < numPairs; i++) {
        const binary1 = generateBinaryString();
        const binary2 = generateBinaryString();
        pairs.push(`${binary1},${binary2}`);
    }
    return pairs;
}

// Function to write the binary pairs to a file
function writeBinaryPairsToFile(filename: string, pairs: string[]): void {
    const fileContent = pairs.join('\n');
    fs.writeFileSync(filename, fileContent);
    console.log(`Binary pairs written to ${filename}`);
}

// Generate 10 pairs of binary strings
const numPairs = 100;
const binaryPairs = generateBinaryPairs(numPairs);

// Write the pairs to 'binaryInput.txt'
writeBinaryPairsToFile('binaryInput.txt', binaryPairs);
