#variable mapping 
lo -> $s0
hi -> $s1
matched -> $s3
str[0] -> $s4
size -> $s5

    li $s0, 0           # lo = 0
    add $s1, $s5, -1    # hi = size - 1, $s5 contains size
    li $s3, 1           # matched = 1 (assume it's a palindrome initially)

Loop:
    # bge $s0, $s1, Exit      # if lo >= hi, exit the loop // psedo
    add $t1, $s4, $s0       # store the address of str[lo]
    add $t3, $s4, $s1       # store the address of str[hi]
    slt $t0, $t1, $t3       # compare the address of str[lo] and str[hi] instead of index

    beq $t0, $zero, Exit    # if lo >= hi, $t0 is 0, exit the loop
    beq $s3, $zero, Exit    # if matched == 0, exit the loop
    # Load str[lo] into $t0
    add $t0, $s4, $s0       # $t0 = base address + lo
    lb $t0, 0($t0)          # load byte at str[lo] into $t0

    # Load str[hi] into $t1
    add $t1, $s4, $s1       # $t1 = base address + hi
    lb $t1, 0($t1)          # load byte at str[hi] into $t1

    # Compare str[lo] and str[hi]
    bne $t0, $t1, Mismatch  # if str[lo] != str[hi], jump to Mismatch
    addi $s0, $s0, 1        # lo++
    addi $s1, $s1, -1       # hi--
    j Loop                  # Jump back to the beginning of the loop
Mismatch:
    li $s3, 0               # matched = 0
    j Loop                  # Continue the loop to check the condition again
Exit:
    # $s3 contains the final result: 1 (palindrome) or 0 (not palindrome)
    # Program continues or you can handle the result here
