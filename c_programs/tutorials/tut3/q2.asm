You accidentally spilled coffee on your best friend’s MIPS assembly code printout.
Fortunately, there are enough hints for you to reconstruct the code. Fill in the missing lines
(shaded cells) below to save your friendship.
Answer:
Instruction
Encoding
MIPS Code
# $s1 stores the result, $t0 stores a non-negative number
            addi $s1, $zero, 0 #Inst. address is 0x00400028
            001000 00000 10001 0000 0000 0000 0000
            2 0 1 1 0 0 0 0 _{16}
0x00084042  loop: srl $t0, $t0, 1
0x11000002
0001 0001 0000 0000 0000 0000 0000 0010
000100 01000 00000 0000000000000010
beq     $t0   $zero  (PC + 4) + 2 * 4 => exit
0x22310001
0010 0010 0011 0001 0000 0000 0000 0001
001000 10001 10001 0000 0000 0000 0001
            addi $s1, $s1, 1
            j loop
000010 0x00400028 + 4
000010 0000 0000 0100 0000 0000 0000 0010 11(00)
 
exit:
(b) Give a simple mathematic expression for the relationship between $s1 and $t0 as calculated
in the code