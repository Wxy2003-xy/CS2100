
compiled:	file format mach-o arm64

Disassembly of section __TEXT,__text:

0000000100003f44 <_main>:
100003f44: d100c3ff    	sub	sp, sp, #48
100003f48: a9027bfd    	stp	x29, x30, [sp, #32]
100003f4c: 910083fd    	add	x29, sp, #32
100003f50: 52800008    	mov	w8, #0
100003f54: b90013e8    	str	w8, [sp, #16]
100003f58: b81fc3bf    	stur	wzr, [x29, #-4]
100003f5c: bc5f83a0    	ldur	s0, [x29, #-8]
100003f60: 1e2e1001    	fmov	s1, #1.00000000
100003f64: 1e212800    	fadd	s0, s0, s1
100003f68: 1e22c000    	fcvt	d0, s0
100003f6c: 910003e8    	mov	x8, sp
100003f70: fd000100    	str	d0, [x8]
100003f74: 90000000    	adrp	x0, 0x100003000 <_main+0x30>
100003f78: 913e7000    	add	x0, x0, #3996
100003f7c: 94000005    	bl	0x100003f90 <_printf+0x100003f90>
100003f80: b94013e0    	ldr	w0, [sp, #16]
100003f84: a9427bfd    	ldp	x29, x30, [sp, #32]
100003f88: 9100c3ff    	add	sp, sp, #48
100003f8c: d65f03c0    	ret

Disassembly of section __TEXT,__stubs:

0000000100003f90 <__stubs>:
100003f90: b0000010    	adrp	x16, 0x100004000 <__stubs+0x4>
100003f94: f9400210    	ldr	x16, [x16]
100003f98: d61f0200    	br	x16
