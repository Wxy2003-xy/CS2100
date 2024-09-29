address of array[]  $s0
target  $s1 // value to look for in array
lo  $s2 // lower bound of the subarray
hi  $s3 // upper bound of the subarray
mid  $s4 // middle index of the subarray
ans  $s5 // index of the target if found, ‐1 otherwise. Initialized to ‐1.

loop:
slt $t9, $s3, $s2
bne $t9, $zero, end
add $s4, $s2, $s3
[srl $s4, $s4, 1 ] # mid = (lo + hi)/ 2
sll $t0, $s4, 2
add $t0, $s0, $t0
[lw $t1, 0($t0) ]
slt $t9, $s1, $t1
beq $t9, $zero, bigger # if (target < array[mid])
addi $s3, $s4, -1
j loopEnd # hi = mid – 1
bigger:
[slt $t9, $t1, $s1 ]
[beq $t9, $zero, equal ]
addi $s2, $s4, 1
j loopEnd # lo = mid + 1
equal:
add $s5, $s4, $zero
[j end ]
ans = mid
break
loopEnd:
[j loop ] #} //end of while-loop
end: