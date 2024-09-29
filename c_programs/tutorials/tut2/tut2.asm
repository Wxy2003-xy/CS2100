add $t0, $s0, $zero    # 1. Copy the value in $s0 to $t0
lui $t1, 0x8000        # 2. Load the upper immediate 0x8000 into $t1 -> $t1 = 0x80000000

lp: beq $t0, $zero, e  # 3. If $t0 == 0, jump to label 'e' (end)
andi $t2, $t0, 1       # 4. $t2 = $t0 & 1 (extract the least significant bit of $t0)
beq $t2, $zero, s      # 5. If $t2 == 0, jump to label 's'
xor $s0, $s0, $t1      # 6. $s0 = $s0 ^ $t1 (flip the bit at the position of $t1 in $s0)

s: srl $t0, $t0, 1     # 7. Logical right shift $t0 by 1 (divide by 2, effectively moving to the next bit)
j lp                   # 8. Jump to label 'lp' (loop)

e:                     # 9. Label 'e' marks the end of the loop

s0 = 31 =       0000 0000 0000 0000 0000 0000 0001 1111
t0 = s0 + 1 =   0000 0000 0000 0000 0000 0000 0001 1111
ld up t1 =      1000 0000 0000 0000 0000 0000 0000 0000

looping: 
if t0 = 0 -> exit;  (No)
else 
t2 = t0 & 1 =   0000 0000 0000 0000 0000 0000 0001 1111
              & 0000 0000 0000 0000 0000 0000 0000 0001
              = 0000 0000 0000 0000 0000 0000 0000 0001
if t2 = 0 -> skip next (No)
else 
s0 = s0 ^ t1=   0000 0000 0000 0000 0000 0000 0001 1111
              ^ 1000 0000 0000 0000 0000 0000 0000 0000
              = 1000 0000 0000 0000 0000 0000 0001 1111 # s0 at the end of iteration 1
t0 = t0 srl 1 = 0000 0000 0000 0000 0000 0000 0001 1111 >> 1
              = 0000 0000 0000 0000 0000 0000 0000 1111 # t0 at the end of iteraton 1
j loop (end of iteration 1)

if t0 = 0 -> exit; (No)
else 
t2 = t0 & 1 =   0000 0000 0000 0000 0000 0000 0000 1111
              & 0000 0000 0000 0000 0000 0000 0000 0001

