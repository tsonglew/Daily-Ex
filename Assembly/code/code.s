	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 12
	.globl	_sum
	.align	4, 0x90
_sum:                                   ## @sum
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp0:
	.cfi_def_cfa_offset 16
Ltmp1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp2:
	.cfi_def_cfa_register %rbp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	-4(%rbp), %esi
	addl	-8(%rbp), %esi
	movl	%esi, -12(%rbp)
	movl	-12(%rbp), %esi
	addl	_accum(%rip), %esi
	movl	%esi, _accum(%rip)
	movl	-12(%rbp), %eax
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_accum                  ## @accum
.zerofill __DATA,__common,_accum,4,2

.subsections_via_symbols
