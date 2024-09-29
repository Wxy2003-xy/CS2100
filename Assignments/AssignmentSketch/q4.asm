func:
    li $t0, 32
    add $v0, $zero, $zero
    j $L3
$L6:
    addi $v0, $v0, 1
    addi $t0, $t0, -1
$L7:
    beq $t0, $zero, $L8
    sll $a0, $a0, 1
$L3:
    slti $t1, $a0, 0
    beq $t1, $zero, $L6     
    addi $t0, $t0, -1
    j $L7
$L8:
    jr $ra