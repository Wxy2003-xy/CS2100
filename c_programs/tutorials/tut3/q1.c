char str[size] = { ... }; // some string
int lo, hi, matched;
// Translate to MIPS from this point onwards
lo = 0;
hi = size-1;
matched = 1; // assume this is a palindrome
// In C, 1 means true and 0 means false
while ((lo < hi) && matched) {
    if (str[lo] != str[hi])
        matched = 0; // found a mismatch
    else {
        lo++;
        hi--;
    }
}
// "matched" = 1 (palindrome) or 0 (not palindrome)
lo -> $s0;
hi -> $s1;
matched -> $s3;
base address of str[] -> $s4;
size -> $s5
(a) Translate the C code into MIPS code by keeping track of the indices.
(b) Translate the C code into MIPS code by using the idea of “array pointer”. 
Basically, we keep track of the actual addresses of the elements to be accessed, 
rather than the indices. 
Refer to lecture set #8, slide 34 for an example
Note: Recall the “short circuit” logical AND operation in C. 
Given condition (A && B), condition B will not be checked if A is found to be false.
