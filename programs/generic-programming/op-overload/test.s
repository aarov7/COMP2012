	.file	"test.cpp"
	.section .rdata,"dr"
__ZStL19piecewise_construct:
	.space 1
.lcomm __ZStL8__ioinit,1,1
	.align 4
LC0:
	.ascii "op[] const: invalid dimension!\12\0"
	.text
	.align 2
	.globl	__ZNK6VectorixEi
	.def	__ZNK6VectorixEi;	.scl	2;	.type	32;	.endef
__ZNK6VectorixEi:
LFB1448:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	8(%ebp), %eax
	testl	%eax, %eax
	je	L3
	cmpl	$1, %eax
	je	L4
	jmp	L6
L3:
	movl	-12(%ebp), %eax
	fldl	(%eax)
	jmp	L1
L4:
	movl	-12(%ebp), %eax
	fldl	8(%eax)
	jmp	L1
L6:
	movl	$LC0, 4(%esp)
	movl	$__ZSt4cerr, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	flds	LC1
	fstp	%st(0)
	flds	LC1
L1:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE1448:
	.section .rdata,"dr"
LC2:
	.ascii "op[]: invalid dimension!\12\0"
	.text
	.align 2
	.globl	__ZN6VectorixEi
	.def	__ZN6VectorixEi;	.scl	2;	.type	32;	.endef
__ZN6VectorixEi:
LFB1449:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	8(%ebp), %eax
	testl	%eax, %eax
	je	L9
	cmpl	$1, %eax
	je	L10
	jmp	L12
L9:
	movl	-12(%ebp), %eax
	jmp	L7
L10:
	movl	-12(%ebp), %eax
	addl	$8, %eax
	jmp	L7
L12:
	movl	$LC2, 4(%esp)
	movl	$__ZSt4cerr, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
L7:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE1449:
	.globl	__Z3foov
	.def	__Z3foov;	.scl	2;	.type	32;	.endef
__Z3foov:
LFB1450:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	leal	-12(%ebp), %eax
	movl	%eax, (%esp)
	movl	$__ZSt3cin, %ecx
	call	__ZNSirsERi
	subl	$4, %esp
	movl	-12(%ebp), %eax
	testl	%eax, %eax
	je	L14
	movl	-12(%ebp), %eax
	jmp	L13
L14:
L13:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1450:
	.def	___main;	.scl	2;	.type	32;	.endef
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB1451:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	call	___main
	call	__Z3foov
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1451:
	.def	___tcf_0;	.scl	3;	.type	32;	.endef
___tcf_0:
LFB1879:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	movl	$__ZStL8__ioinit, %ecx
	call	__ZNSt8ios_base4InitD1Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1879:
	.def	__Z41__static_initialization_and_destruction_0ii;	.scl	3;	.type	32;	.endef
__Z41__static_initialization_and_destruction_0ii:
LFB1878:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	cmpl	$1, 8(%ebp)
	jne	L21
	cmpl	$65535, 12(%ebp)
	jne	L21
	movl	$__ZStL8__ioinit, %ecx
	call	__ZNSt8ios_base4InitC1Ev
	movl	$___tcf_0, (%esp)
	call	_atexit
L21:
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1878:
	.def	__GLOBAL__sub_I__ZNK6VectorixEi;	.scl	3;	.type	32;	.endef
__GLOBAL__sub_I__ZNK6VectorixEi:
LFB1880:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$65535, 4(%esp)
	movl	$1, (%esp)
	call	__Z41__static_initialization_and_destruction_0ii
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1880:
	.section	.ctors,"w"
	.align 4
	.long	__GLOBAL__sub_I__ZNK6VectorixEi
	.section .rdata,"dr"
	.align 4
LC1:
	.long	2143289344
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc;	.scl	2;	.type	32;	.endef
	.def	__ZNSirsERi;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	_atexit;	.scl	2;	.type	32;	.endef
