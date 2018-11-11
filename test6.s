	.file	"test6.c"
	.comm	x,4,4
	.globl	q
	.data
	.align 4
	.type	q, @object
	.size	q, 4
q:
	.long	10
	.section	.rodata
.LC0:
	.string	"%d\n"
	.text
	.globl	fun
	.type	fun, @function
fun:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	x(%rip), %eax
	movl	%eax, %esi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	fun, .-fun
	.section	.rodata
.LC2:
	.string	"%d # %lu\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$40, %rsp
	.cfi_offset 3, -24
	movl	%edi, -36(%rbp)
	movq	%rsi, -48(%rbp)
	movss	.LC1(%rip), %xmm0
	movss	%xmm0, -24(%rbp)
	movl	$31, -20(%rbp)
	movl	$16, %ebx
	movl	$5, -28(%rbp)
	movss	-24(%rbp), %xmm0
	ucomiss	.LC1(%rip), %xmm0
	jp	.L3
	movss	-24(%rbp), %xmm0
	ucomiss	.LC1(%rip), %xmm0
	jne	.L3
	movl	-20(%rbp), %eax
	movl	$1, %edx
	movl	%eax, %esi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	movl	%ebx, %esi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
.L3:
	movl	$0, %eax
	call	fun
	movl	$0, %eax
	addq	$40, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.section	.rodata
	.align 4
.LC1:
	.long	1066192077
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.10) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
