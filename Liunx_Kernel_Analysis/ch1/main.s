g:
	pushl	%ebp
	movl	%esp, %ebp
	movl	8(%ebp), %eax
	addl	$210, %eax
	popl	%ebp
	ret
f:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	g
	leave
	ret
main:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$4, %esp
	movl	$210, (%esp)
	call	f
	addl	$210, %eax
	leave
	ret
