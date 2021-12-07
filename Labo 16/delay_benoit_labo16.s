	.file	"delay_benoit_labo16.cpp"
	.text
	.section .rdata,"dr"
_ZStL19piecewise_construct:
	.space 1
.lcomm _ZStL8__ioinit,1,1
_ZStL13allocator_arg:
	.space 1
_ZStL6ignore:
	.space 1
	.text
	.def	time;	.scl	3;	.type	32;	.endef
	.seh_proc	time
time:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rcx
	movq	__imp__time64(%rip), %rax
	call	*%rax
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
	.align 4
_ZL9MAX_VALUE:
	.long	2147483647
	.def	__main;	.scl	2;	.type	32;	.endef
	.align 8
.LC0:
	.ascii "Veuillez entre 2 nombre premier: \0"
	.align 8
.LC1:
	.ascii "Veuillez entrer un nombre premier et inferieur a (p - 1 ) * (q - 1): \0"
	.align 8
.LC2:
	.ascii "Bien ouej mec je sais pas comment ta fais mais ta trouver des bons nombres\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	call	__main
	movl	$0, -4(%rbp)
.L8:
	leaq	.LC0(%rip), %rdx
	movq	.refptr._ZSt4cout(%rip), %rcx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	leaq	-8(%rbp), %rax
	movq	%rax, %rdx
	movq	.refptr._ZSt3cin(%rip), %rcx
	call	_ZNSirsERi
	movq	%rax, %rcx
	leaq	-12(%rbp), %rax
	movq	%rax, %rdx
	call	_ZNSirsERi
	movl	-8(%rbp), %edx
	movl	-12(%rbp), %eax
	cmpl	%eax, %edx
	je	.L4
	movl	-8(%rbp), %eax
	movl	%eax, %ecx
	call	_Z7isPrimei
	xorl	$1, %eax
	testb	%al, %al
	jne	.L4
	movl	-12(%rbp), %eax
	movl	%eax, %ecx
	call	_Z7isPrimei
	xorl	$1, %eax
	testb	%al, %al
	je	.L5
.L4:
	movl	$1, %eax
	jmp	.L6
.L5:
	movl	$0, %eax
.L6:
	testb	%al, %al
	je	.L7
	jmp	.L8
.L7:
	leaq	.LC1(%rip), %rdx
	movq	.refptr._ZSt4cout(%rip), %rcx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	leaq	-16(%rbp), %rax
	movq	%rax, %rdx
	movq	.refptr._ZSt3cin(%rip), %rcx
	call	_ZNSirsERi
	movl	-16(%rbp), %eax
	cmpl	$2147483647, %eax
	je	.L9
	movl	-8(%rbp), %eax
	leal	-1(%rax), %edx
	movl	-12(%rbp), %eax
	subl	$1, %eax
	imull	%eax, %edx
	movl	-16(%rbp), %eax
	cmpl	%eax, %edx
	jle	.L9
	movl	-8(%rbp), %eax
	leal	-1(%rax), %edx
	movl	-12(%rbp), %eax
	subl	$1, %eax
	imull	%eax, %edx
	movl	-16(%rbp), %eax
	movl	%eax, %ecx
	call	_Z11pgdcEuclideii
	cmpl	$1, %eax
	je	.L10
.L9:
	movl	$1, %eax
	jmp	.L11
.L10:
	movl	$0, %eax
.L11:
	testb	%al, %al
	je	.L12
	jmp	.L7
.L12:
	leaq	.LC2(%rip), %rdx
	movq	.refptr._ZSt4cout(%rip), %rcx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movq	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_(%rip), %rdx
	movq	%rax, %rcx
	call	_ZNSolsEPFRSoS_E
	movl	$0, %eax
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	_Z6expModiii
	.def	_Z6expModiii;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z6expModiii
_Z6expModiii:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movl	%r8d, 32(%rbp)
	movl	$1, -4(%rbp)
.L18:
	cmpl	$0, 24(%rbp)
	jle	.L15
	movl	24(%rbp), %eax
	andl	$1, %eax
	testl	%eax, %eax
	jne	.L16
	movl	16(%rbp), %eax
	imull	%eax, %eax
	cltd
	idivl	32(%rbp)
	movl	%edx, 16(%rbp)
	movl	24(%rbp), %eax
	movl	%eax, %edx
	shrl	$31, %edx
	addl	%edx, %eax
	sarl	%eax
	movl	%eax, 24(%rbp)
	jmp	.L18
.L16:
	movl	-4(%rbp), %eax
	imull	16(%rbp), %eax
	cltd
	idivl	32(%rbp)
	movl	%edx, -4(%rbp)
	subl	$1, 24(%rbp)
	jmp	.L18
.L15:
	movl	-4(%rbp), %eax
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	_Z7isPrimei
	.def	_Z7isPrimei;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z7isPrimei
_Z7isPrimei:
	pushq	%rbp
	.seh_pushreg	%rbp
	movl	$5072, %eax
	call	___chkstk_ms
	subq	%rax, %rsp
	.seh_stackalloc	5072
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.seh_endprologue
	movl	%ecx, 4960(%rbp)
	movl	$0, %ecx
	call	time
	movl	%eax, %edx
	leaq	2416(%rbp), %rax
	movq	%rax, %rcx
	call	_ZNSt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEC1Ej
	movl	4960(%rbp), %eax
	leal	-1(%rax), %edx
	leaq	4920(%rbp), %rax
	movl	%edx, %r8d
	movl	$1, %edx
	movq	%rax, %rcx
	call	_ZNSt24uniform_int_distributionIiEC1Eii
	leaq	-96(%rbp), %rax
	leaq	2416(%rbp), %rcx
	leaq	4920(%rbp), %rdx
	movq	%rcx, %r8
	movq	%rax, %rcx
	call	_ZSt4bindISt24uniform_int_distributionIiEJSt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEENSt12_Bind_helperIXsrSt5__or_IJSt11is_integralINSt5decayIT_E4typeEESt7is_enumISA_EEE5valueES8_JDpT0_EE4typeEOS8_DpOSF_
	cmpl	$1, 4960(%rbp)
	jg	.L21
	movl	$0, %eax
	jmp	.L30
.L21:
	cmpl	$2, 4960(%rbp)
	jne	.L23
	movl	$1, %eax
	jmp	.L30
.L23:
	movl	$0, 4940(%rbp)
.L29:
	cmpl	$9, 4940(%rbp)
	jg	.L24
	leaq	-96(%rbp), %rax
	movq	%rax, %rcx
	call	_ZNSt5_BindIFSt24uniform_int_distributionIiESt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEEclIJEiEET0_DpOT_
	movl	%eax, 4928(%rbp)
	movl	4960(%rbp), %eax
	leal	-1(%rax), %edx
	movl	4928(%rbp), %eax
	movl	4960(%rbp), %r8d
	movl	%eax, %ecx
	call	_Z6expModiii
	cmpl	$1, %eax
	setne	%al
	testb	%al, %al
	je	.L25
	movl	$0, %eax
	jmp	.L30
.L25:
	movl	$1, 4936(%rbp)
	movl	4960(%rbp), %eax
	subl	$1, %eax
	movl	%eax, 4932(%rbp)
.L28:
	movl	4932(%rbp), %eax
	andl	$1, %eax
	testl	%eax, %eax
	jne	.L26
	cmpl	$1, 4936(%rbp)
	jne	.L26
	movl	4932(%rbp), %eax
	movl	%eax, %edx
	shrl	$31, %edx
	addl	%edx, %eax
	sarl	%eax
	movl	%eax, 4932(%rbp)
	movl	4932(%rbp), %edx
	movl	4928(%rbp), %eax
	movl	4960(%rbp), %r8d
	movl	%eax, %ecx
	call	_Z6expModiii
	movl	%eax, 4936(%rbp)
	cmpl	$1, 4936(%rbp)
	je	.L28
	movl	4960(%rbp), %eax
	subl	$1, %eax
	cmpl	%eax, 4936(%rbp)
	je	.L28
	movl	$0, %eax
	jmp	.L30
.L26:
	addl	$1, 4940(%rbp)
	jmp	.L29
.L24:
	movl	$1, %eax
.L30:
	addq	$5072, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	_Z11pgdcEuclideii
	.def	_Z11pgdcEuclideii;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z11pgdcEuclideii
_Z11pgdcEuclideii:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movl	$0, -4(%rbp)
.L33:
	cmpl	$0, 24(%rbp)
	je	.L32
	movl	24(%rbp), %eax
	movl	%eax, -4(%rbp)
	movl	16(%rbp), %eax
	cltd
	idivl	24(%rbp)
	movl	%edx, 24(%rbp)
	movl	-4(%rbp), %eax
	movl	%eax, 16(%rbp)
	jmp	.L33
.L32:
	movl	16(%rbp), %eax
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	_Z15extentedEuclideiiRiS_
	.def	_Z15extentedEuclideiiRiS_;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z15extentedEuclideiiRiS_
_Z15extentedEuclideiiRiS_:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movq	%r8, 32(%rbp)
	movq	%r9, 40(%rbp)
	movq	40(%rbp), %rax
	movl	16(%rbp), %edx
	movl	%edx, (%rax)
	movl	24(%rbp), %eax
	movl	%eax, -4(%rbp)
	movq	32(%rbp), %rax
	movl	$0, (%rax)
	movl	$1, -8(%rbp)
	movl	$0, -12(%rbp)
.L37:
	cmpl	$0, -4(%rbp)
	je	.L36
	movq	40(%rbp), %rax
	movl	(%rax), %eax
	cltd
	idivl	-4(%rbp)
	movl	%eax, -12(%rbp)
	movq	40(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, -16(%rbp)
	movq	32(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, -20(%rbp)
	movq	40(%rbp), %rax
	movl	-4(%rbp), %edx
	movl	%edx, (%rax)
	movq	32(%rbp), %rax
	movl	-8(%rbp), %edx
	movl	%edx, (%rax)
	movl	-12(%rbp), %eax
	imull	-4(%rbp), %eax
	movl	%eax, %edx
	movl	-16(%rbp), %eax
	subl	%edx, %eax
	movl	%eax, -4(%rbp)
	movl	-12(%rbp), %eax
	imull	-8(%rbp), %eax
	movl	%eax, %edx
	movl	-20(%rbp), %eax
	subl	%edx, %eax
	movl	%eax, -8(%rbp)
	jmp	.L37
.L36:
	movq	32(%rbp), %rax
	movl	(%rax), %eax
	testl	%eax, %eax
	jns	.L39
	movq	32(%rbp), %rax
	movl	(%rax), %edx
	movl	16(%rbp), %eax
	addl	%eax, %edx
	movq	32(%rbp), %rax
	movl	%edx, (%rax)
.L39:
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZNSt24uniform_int_distributionIiEC1Eii,"x"
	.linkonce discard
	.align 2
	.globl	_ZNSt24uniform_int_distributionIiEC1Eii
	.def	_ZNSt24uniform_int_distributionIiEC1Eii;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt24uniform_int_distributionIiEC1Eii
_ZNSt24uniform_int_distributionIiEC1Eii:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movl	%r8d, 32(%rbp)
	movq	16(%rbp), %rax
	movl	32(%rbp), %ecx
	movl	24(%rbp), %edx
	movl	%ecx, %r8d
	movq	%rax, %rcx
	call	_ZNSt24uniform_int_distributionIiE10param_typeC1Eii
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZNSt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEC1Ej,"x"
	.linkonce discard
	.align 2
	.globl	_ZNSt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEC1Ej
	.def	_ZNSt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEC1Ej;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEC1Ej
_ZNSt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEC1Ej:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movl	24(%rbp), %eax
	movl	%eax, %edx
	movq	16(%rbp), %rcx
	call	_ZNSt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EE4seedEj
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZSt4bindISt24uniform_int_distributionIiEJSt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEENSt12_Bind_helperIXsrSt5__or_IJSt11is_integralINSt5decayIT_E4typeEESt7is_enumISA_EEE5valueES8_JDpT0_EE4typeEOS8_DpOSF_,"x"
	.linkonce discard
	.globl	_ZSt4bindISt24uniform_int_distributionIiEJSt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEENSt12_Bind_helperIXsrSt5__or_IJSt11is_integralINSt5decayIT_E4typeEESt7is_enumISA_EEE5valueES8_JDpT0_EE4typeEOS8_DpOSF_
	.def	_ZSt4bindISt24uniform_int_distributionIiEJSt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEENSt12_Bind_helperIXsrSt5__or_IJSt11is_integralINSt5decayIT_E4typeEESt7is_enumISA_EEE5valueES8_JDpT0_EE4typeEOS8_DpOSF_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt4bindISt24uniform_int_distributionIiEJSt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEENSt12_Bind_helperIXsrSt5__or_IJSt11is_integralINSt5decayIT_E4typeEESt7is_enumISA_EEE5valueES8_JDpT0_EE4typeEOS8_DpOSF_
_ZSt4bindISt24uniform_int_distributionIiEJSt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEENSt12_Bind_helperIXsrSt5__or_IJSt11is_integralINSt5decayIT_E4typeEESt7is_enumISA_EEE5valueES8_JDpT0_EE4typeEOS8_DpOSF_:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$40, %rsp
	.seh_stackalloc	40
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.seh_endprologue
	movq	%rcx, -64(%rbp)
	movq	%rdx, -56(%rbp)
	movq	%r8, -48(%rbp)
	movq	-48(%rbp), %rax
	movq	%rax, %rcx
	call	_ZSt7forwardISt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEOT_RNSt16remove_referenceIS2_E4typeE
	movq	%rax, %rbx
	movq	-56(%rbp), %rax
	movq	%rax, %rcx
	call	_ZSt7forwardISt24uniform_int_distributionIiEEOT_RNSt16remove_referenceIS2_E4typeE
	movq	%rbx, %r8
	movq	%rax, %rdx
	movq	-64(%rbp), %rcx
	call	_ZNSt5_BindIFSt24uniform_int_distributionIiESt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEEC1IJS3_EEEOS1_DpOT_
	movq	-64(%rbp), %rax
	addq	$40, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZNSt5_BindIFSt24uniform_int_distributionIiESt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEEclIJEiEET0_DpOT_,"x"
	.linkonce discard
	.align 2
	.globl	_ZNSt5_BindIFSt24uniform_int_distributionIiESt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEEclIJEiEET0_DpOT_
	.def	_ZNSt5_BindIFSt24uniform_int_distributionIiESt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEEclIJEiEET0_DpOT_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt5_BindIFSt24uniform_int_distributionIiESt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEEclIJEiEET0_DpOT_
_ZNSt5_BindIFSt24uniform_int_distributionIiESt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEEclIJEiEET0_DpOT_:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$56, %rsp
	.seh_stackalloc	56
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.seh_endprologue
	movq	%rcx, -48(%rbp)
	call	_ZSt16forward_as_tupleIJEESt5tupleIJDpOT_EES3_
	leaq	-81(%rbp), %rax
	movl	%ebx, %r8d
	movq	%rax, %rdx
	movq	-48(%rbp), %rcx
	call	_ZNSt5_BindIFSt24uniform_int_distributionIiESt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEE6__callIiJEJLy0EEEET_OSt5tupleIJDpT0_EESt12_Index_tupleIJXspT1_EEE
	addq	$56, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZNSt24uniform_int_distributionIiE10param_typeC1Eii,"x"
	.linkonce discard
	.align 2
	.globl	_ZNSt24uniform_int_distributionIiE10param_typeC1Eii
	.def	_ZNSt24uniform_int_distributionIiE10param_typeC1Eii;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt24uniform_int_distributionIiE10param_typeC1Eii
_ZNSt24uniform_int_distributionIiE10param_typeC1Eii:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movl	%r8d, 32(%rbp)
	movq	16(%rbp), %rax
	movl	24(%rbp), %edx
	movl	%edx, (%rax)
	movq	16(%rbp), %rax
	movl	32(%rbp), %edx
	movl	%edx, 4(%rax)
	nop
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZNSt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EE4seedEj,"x"
	.linkonce discard
	.align 2
	.globl	_ZNSt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EE4seedEj
	.def	_ZNSt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EE4seedEj;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EE4seedEj
_ZNSt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EE4seedEj:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movl	24(%rbp), %eax
	movl	%eax, %ecx
	call	_ZNSt8__detail5__modIjLj0ELj1ELj0EEET_S1_
	movq	16(%rbp), %rdx
	movl	%eax, (%rdx)
	movq	$1, -8(%rbp)
.L49:
	cmpq	$623, -8(%rbp)
	ja	.L48
	movq	-8(%rbp), %rax
	leaq	-1(%rax), %rdx
	movq	16(%rbp), %rax
	movl	(%rax,%rdx,4), %eax
	movl	%eax, -12(%rbp)
	movl	-12(%rbp), %eax
	shrl	$30, %eax
	xorl	%eax, -12(%rbp)
	movl	-12(%rbp), %eax
	imull	$1812433253, %eax, %eax
	movl	%eax, -12(%rbp)
	movq	-8(%rbp), %rax
	movl	%eax, %ecx
	call	_ZNSt8__detail5__modIjLj624ELj1ELj0EEET_S1_
	addl	%eax, -12(%rbp)
	movl	-12(%rbp), %eax
	movl	%eax, %ecx
	call	_ZNSt8__detail5__modIjLj0ELj1ELj0EEET_S1_
	movq	16(%rbp), %rdx
	movq	-8(%rbp), %rcx
	movl	%eax, (%rdx,%rcx,4)
	addq	$1, -8(%rbp)
	jmp	.L49
.L48:
	movq	16(%rbp), %rax
	movq	$624, 2496(%rax)
	nop
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZSt7forwardISt24uniform_int_distributionIiEEOT_RNSt16remove_referenceIS2_E4typeE,"x"
	.linkonce discard
	.globl	_ZSt7forwardISt24uniform_int_distributionIiEEOT_RNSt16remove_referenceIS2_E4typeE
	.def	_ZSt7forwardISt24uniform_int_distributionIiEEOT_RNSt16remove_referenceIS2_E4typeE;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt7forwardISt24uniform_int_distributionIiEEOT_RNSt16remove_referenceIS2_E4typeE
_ZSt7forwardISt24uniform_int_distributionIiEEOT_RNSt16remove_referenceIS2_E4typeE:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rax
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZSt7forwardISt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEOT_RNSt16remove_referenceIS2_E4typeE,"x"
	.linkonce discard
	.globl	_ZSt7forwardISt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEOT_RNSt16remove_referenceIS2_E4typeE
	.def	_ZSt7forwardISt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEOT_RNSt16remove_referenceIS2_E4typeE;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt7forwardISt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEOT_RNSt16remove_referenceIS2_E4typeE
_ZSt7forwardISt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEOT_RNSt16remove_referenceIS2_E4typeE:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rax
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZNSt5_BindIFSt24uniform_int_distributionIiESt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEEC1IJS3_EEEOS1_DpOT_,"x"
	.linkonce discard
	.align 2
	.globl	_ZNSt5_BindIFSt24uniform_int_distributionIiESt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEEC1IJS3_EEEOS1_DpOT_
	.def	_ZNSt5_BindIFSt24uniform_int_distributionIiESt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEEC1IJS3_EEEOS1_DpOT_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt5_BindIFSt24uniform_int_distributionIiESt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEEC1IJS3_EEEOS1_DpOT_
_ZNSt5_BindIFSt24uniform_int_distributionIiESt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEEC1IJS3_EEEOS1_DpOT_:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$40, %rsp
	.seh_stackalloc	40
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.seh_endprologue
	movq	%rcx, -64(%rbp)
	movq	%rdx, -56(%rbp)
	movq	%r8, -48(%rbp)
	movq	-56(%rbp), %rax
	movq	%rax, %rcx
	call	_ZSt4moveIRSt24uniform_int_distributionIiEEONSt16remove_referenceIT_E4typeEOS4_
	movq	-64(%rbp), %rdx
	movq	(%rax), %rax
	movq	%rax, (%rdx)
	movq	-64(%rbp), %rax
	leaq	8(%rax), %rbx
	movq	-48(%rbp), %rax
	movq	%rax, %rcx
	call	_ZSt7forwardISt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEOT_RNSt16remove_referenceIS2_E4typeE
	movq	%rax, %rdx
	movq	%rbx, %rcx
	call	_ZNSt5tupleIJSt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEEC1IJS1_ELb1ELb1EEEDpOT_
	nop
	addq	$40, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZNSt11_Tuple_implILy0EJSt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEE7_M_headERS2_,"x"
	.linkonce discard
	.globl	_ZNSt11_Tuple_implILy0EJSt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEE7_M_headERS2_
	.def	_ZNSt11_Tuple_implILy0EJSt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEE7_M_headERS2_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt11_Tuple_implILy0EJSt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEE7_M_headERS2_
_ZNSt11_Tuple_implILy0EJSt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEE7_M_headERS2_:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rax
	movq	%rax, %rcx
	call	_ZNSt10_Head_baseILy0ESt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EELb0EE7_M_headERS2_
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZNSt10_Head_baseILy0ESt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EELb0EEC2IS1_EEOT_,"x"
	.linkonce discard
	.align 2
	.globl	_ZNSt10_Head_baseILy0ESt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EELb0EEC2IS1_EEOT_
	.def	_ZNSt10_Head_baseILy0ESt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EELb0EEC2IS1_EEOT_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt10_Head_baseILy0ESt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EELb0EEC2IS1_EEOT_
_ZNSt10_Head_baseILy0ESt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EELb0EEC2IS1_EEOT_:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 32(%rbp)
	movq	%rdx, 40(%rbp)
	movq	40(%rbp), %rax
	movq	%rax, %rcx
	call	_ZSt7forwardISt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEOT_RNSt16remove_referenceIS2_E4typeE
	movq	32(%rbp), %rdx
	movq	%rax, %r8
	movl	$313, %eax
	movq	%rdx, %rdi
	movq	%r8, %rsi
	movq	%rax, %rcx
	rep movsq
	nop
	addq	$32, %rsp
	popq	%rsi
	popq	%rdi
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZSt16forward_as_tupleIJEESt5tupleIJDpOT_EES3_,"x"
	.linkonce discard
	.globl	_ZSt16forward_as_tupleIJEESt5tupleIJDpOT_EES3_
	.def	_ZSt16forward_as_tupleIJEESt5tupleIJDpOT_EES3_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt16forward_as_tupleIJEESt5tupleIJDpOT_EES3_
_ZSt16forward_as_tupleIJEESt5tupleIJDpOT_EES3_:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	nop
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZNSt5_BindIFSt24uniform_int_distributionIiESt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEE6__callIiJEJLy0EEEET_OSt5tupleIJDpT0_EESt12_Index_tupleIJXspT1_EEE,"x"
	.linkonce discard
	.align 2
	.globl	_ZNSt5_BindIFSt24uniform_int_distributionIiESt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEE6__callIiJEJLy0EEEET_OSt5tupleIJDpT0_EESt12_Index_tupleIJXspT1_EEE
	.def	_ZNSt5_BindIFSt24uniform_int_distributionIiESt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEE6__callIiJEJLy0EEEET_OSt5tupleIJDpT0_EESt12_Index_tupleIJXspT1_EEE;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt5_BindIFSt24uniform_int_distributionIiESt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEE6__callIiJEJLy0EEEET_OSt5tupleIJDpT0_EESt12_Index_tupleIJXspT1_EEE
_ZNSt5_BindIFSt24uniform_int_distributionIiESt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEE6__callIiJEJLy0EEEET_OSt5tupleIJDpT0_EESt12_Index_tupleIJXspT1_EEE:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movq	16(%rbp), %rax
	addq	$8, %rax
	movq	%rax, %rcx
	call	_ZSt3getILy0EJSt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERS6_
	movq	%rax, %rdx
	movq	24(%rbp), %rcx
	leaq	-1(%rbp), %rax
	movq	%rcx, %r8
	movq	%rax, %rcx
	call	_ZNVKSt3_MuISt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EELb0ELb0EEclIRS1_St5tupleIJEEEEOT_S8_RT0_
	movq	%rax, %rdx
	movq	16(%rbp), %rax
	movq	%rax, %rcx
	call	_ZSt8__invokeIRSt24uniform_int_distributionIiEJRSt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEENSt15__invoke_resultIT_JDpT0_EE4typeEOS7_DpOS8_
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZNSt8__detail5__modIjLj0ELj1ELj0EEET_S1_,"x"
	.linkonce discard
	.globl	_ZNSt8__detail5__modIjLj0ELj1ELj0EEET_S1_
	.def	_ZNSt8__detail5__modIjLj0ELj1ELj0EEET_S1_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt8__detail5__modIjLj0ELj1ELj0EEET_S1_
_ZNSt8__detail5__modIjLj0ELj1ELj0EEET_S1_:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movl	16(%rbp), %ecx
	call	_ZNSt8__detail4_ModIjLj0ELj1ELj0ELb1ELb0EE6__calcEj
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZNSt8__detail5__modIjLj624ELj1ELj0EEET_S1_,"x"
	.linkonce discard
	.globl	_ZNSt8__detail5__modIjLj624ELj1ELj0EEET_S1_
	.def	_ZNSt8__detail5__modIjLj624ELj1ELj0EEET_S1_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt8__detail5__modIjLj624ELj1ELj0EEET_S1_
_ZNSt8__detail5__modIjLj624ELj1ELj0EEET_S1_:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movl	16(%rbp), %ecx
	call	_ZNSt8__detail4_ModIjLj624ELj1ELj0ELb1ELb1EE6__calcEj
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZSt4moveIRSt24uniform_int_distributionIiEEONSt16remove_referenceIT_E4typeEOS4_,"x"
	.linkonce discard
	.globl	_ZSt4moveIRSt24uniform_int_distributionIiEEONSt16remove_referenceIT_E4typeEOS4_
	.def	_ZSt4moveIRSt24uniform_int_distributionIiEEONSt16remove_referenceIT_E4typeEOS4_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt4moveIRSt24uniform_int_distributionIiEEONSt16remove_referenceIT_E4typeEOS4_
_ZSt4moveIRSt24uniform_int_distributionIiEEONSt16remove_referenceIT_E4typeEOS4_:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rax
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZNSt5tupleIJSt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEEC1IJS1_ELb1ELb1EEEDpOT_,"x"
	.linkonce discard
	.align 2
	.globl	_ZNSt5tupleIJSt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEEC1IJS1_ELb1ELb1EEEDpOT_
	.def	_ZNSt5tupleIJSt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEEC1IJS1_ELb1ELb1EEEDpOT_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt5tupleIJSt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEEC1IJS1_ELb1ELb1EEEDpOT_
_ZNSt5tupleIJSt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEEC1IJS1_ELb1ELb1EEEDpOT_:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$40, %rsp
	.seh_stackalloc	40
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.seh_endprologue
	movq	%rcx, -64(%rbp)
	movq	%rdx, -56(%rbp)
	movq	-64(%rbp), %rbx
	movq	-56(%rbp), %rax
	movq	%rax, %rcx
	call	_ZSt7forwardISt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEOT_RNSt16remove_referenceIS2_E4typeE
	movq	%rax, %rdx
	movq	%rbx, %rcx
	call	_ZNSt11_Tuple_implILy0EJSt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEEC2IS1_EEOT_
	nop
	addq	$40, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZNSt10_Head_baseILy0ESt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EELb0EE7_M_headERS2_,"x"
	.linkonce discard
	.globl	_ZNSt10_Head_baseILy0ESt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EELb0EE7_M_headERS2_
	.def	_ZNSt10_Head_baseILy0ESt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EELb0EE7_M_headERS2_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt10_Head_baseILy0ESt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EELb0EE7_M_headERS2_
_ZNSt10_Head_baseILy0ESt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EELb0EE7_M_headERS2_:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rax
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZSt3getILy0EJSt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERS6_,"x"
	.linkonce discard
	.globl	_ZSt3getILy0EJSt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERS6_
	.def	_ZSt3getILy0EJSt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERS6_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt3getILy0EJSt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERS6_
_ZSt3getILy0EJSt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERS6_:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rax
	movq	%rax, %rcx
	call	_ZSt12__get_helperILy0ESt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEJEERT0_RSt11_Tuple_implIXT_EJS2_DpT1_EE
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZNVKSt3_MuISt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EELb0ELb0EEclIRS1_St5tupleIJEEEEOT_S8_RT0_,"x"
	.linkonce discard
	.align 2
	.globl	_ZNVKSt3_MuISt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EELb0ELb0EEclIRS1_St5tupleIJEEEEOT_S8_RT0_
	.def	_ZNVKSt3_MuISt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EELb0ELb0EEclIRS1_St5tupleIJEEEEOT_S8_RT0_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNVKSt3_MuISt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EELb0ELb0EEclIRS1_St5tupleIJEEEEOT_S8_RT0_
_ZNVKSt3_MuISt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EELb0ELb0EEclIRS1_St5tupleIJEEEEOT_S8_RT0_:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movq	%r8, 32(%rbp)
	movq	24(%rbp), %rax
	movq	%rax, %rcx
	call	_ZSt7forwardIRSt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEOT_RNSt16remove_referenceIS3_E4typeE
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZSt8__invokeIRSt24uniform_int_distributionIiEJRSt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEENSt15__invoke_resultIT_JDpT0_EE4typeEOS7_DpOS8_,"x"
	.linkonce discard
	.globl	_ZSt8__invokeIRSt24uniform_int_distributionIiEJRSt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEENSt15__invoke_resultIT_JDpT0_EE4typeEOS7_DpOS8_
	.def	_ZSt8__invokeIRSt24uniform_int_distributionIiEJRSt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEENSt15__invoke_resultIT_JDpT0_EE4typeEOS7_DpOS8_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt8__invokeIRSt24uniform_int_distributionIiEJRSt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEENSt15__invoke_resultIT_JDpT0_EE4typeEOS7_DpOS8_
_ZSt8__invokeIRSt24uniform_int_distributionIiEJRSt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEENSt15__invoke_resultIT_JDpT0_EE4typeEOS7_DpOS8_:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 32(%rbp)
	movq	%rdx, 40(%rbp)
	movq	40(%rbp), %rax
	movq	%rax, %rcx
	call	_ZSt7forwardIRSt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEOT_RNSt16remove_referenceIS3_E4typeE
	movq	%rax, %rbx
	movq	32(%rbp), %rcx
	call	_ZSt7forwardIRSt24uniform_int_distributionIiEEOT_RNSt16remove_referenceIS3_E4typeE
	movq	%rbx, %r8
	movq	%rax, %rdx
	movl	%esi, %ecx
	call	_ZSt13__invoke_implIiRSt24uniform_int_distributionIiEJRSt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEET_St14__invoke_otherOT0_DpOT1_
	addq	$32, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZNSt8__detail4_ModIjLj0ELj1ELj0ELb1ELb0EE6__calcEj,"x"
	.linkonce discard
	.globl	_ZNSt8__detail4_ModIjLj0ELj1ELj0ELb1ELb0EE6__calcEj
	.def	_ZNSt8__detail4_ModIjLj0ELj1ELj0ELb1ELb0EE6__calcEj;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt8__detail4_ModIjLj0ELj1ELj0ELb1ELb0EE6__calcEj
_ZNSt8__detail4_ModIjLj0ELj1ELj0ELb1ELb0EE6__calcEj:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movl	16(%rbp), %eax
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZNSt8__detail4_ModIjLj624ELj1ELj0ELb1ELb1EE6__calcEj,"x"
	.linkonce discard
	.globl	_ZNSt8__detail4_ModIjLj624ELj1ELj0ELb1ELb1EE6__calcEj
	.def	_ZNSt8__detail4_ModIjLj624ELj1ELj0ELb1ELb1EE6__calcEj;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt8__detail4_ModIjLj624ELj1ELj0ELb1ELb1EE6__calcEj
_ZNSt8__detail4_ModIjLj624ELj1ELj0ELb1ELb1EE6__calcEj:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movl	16(%rbp), %eax
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	movl	%eax, %edx
	shrl	$4, %edx
	movl	%edx, %edx
	imulq	$440509467, %rdx, %rdx
	shrq	$32, %rdx
	shrl	$2, %edx
	imull	$624, %edx, %edx
	subl	%edx, %eax
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZNSt11_Tuple_implILy0EJSt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEEC2IS1_EEOT_,"x"
	.linkonce discard
	.align 2
	.globl	_ZNSt11_Tuple_implILy0EJSt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEEC2IS1_EEOT_
	.def	_ZNSt11_Tuple_implILy0EJSt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEEC2IS1_EEOT_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt11_Tuple_implILy0EJSt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEEC2IS1_EEOT_
_ZNSt11_Tuple_implILy0EJSt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEEC2IS1_EEOT_:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$40, %rsp
	.seh_stackalloc	40
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.seh_endprologue
	movq	%rcx, -64(%rbp)
	movq	%rdx, -56(%rbp)
	movq	-64(%rbp), %rbx
	movq	-56(%rbp), %rax
	movq	%rax, %rcx
	call	_ZSt7forwardISt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEOT_RNSt16remove_referenceIS2_E4typeE
	movq	%rax, %rdx
	movq	%rbx, %rcx
	call	_ZNSt10_Head_baseILy0ESt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EELb0EEC2IS1_EEOT_
	nop
	addq	$40, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZSt12__get_helperILy0ESt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEJEERT0_RSt11_Tuple_implIXT_EJS2_DpT1_EE,"x"
	.linkonce discard
	.globl	_ZSt12__get_helperILy0ESt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEJEERT0_RSt11_Tuple_implIXT_EJS2_DpT1_EE
	.def	_ZSt12__get_helperILy0ESt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEJEERT0_RSt11_Tuple_implIXT_EJS2_DpT1_EE;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt12__get_helperILy0ESt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEJEERT0_RSt11_Tuple_implIXT_EJS2_DpT1_EE
_ZSt12__get_helperILy0ESt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEJEERT0_RSt11_Tuple_implIXT_EJS2_DpT1_EE:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rcx
	call	_ZNSt11_Tuple_implILy0EJSt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEE7_M_headERS2_
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZSt7forwardIRSt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEOT_RNSt16remove_referenceIS3_E4typeE,"x"
	.linkonce discard
	.globl	_ZSt7forwardIRSt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEOT_RNSt16remove_referenceIS3_E4typeE
	.def	_ZSt7forwardIRSt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEOT_RNSt16remove_referenceIS3_E4typeE;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt7forwardIRSt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEOT_RNSt16remove_referenceIS3_E4typeE
_ZSt7forwardIRSt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEOT_RNSt16remove_referenceIS3_E4typeE:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rax
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZSt7forwardIRSt24uniform_int_distributionIiEEOT_RNSt16remove_referenceIS3_E4typeE,"x"
	.linkonce discard
	.globl	_ZSt7forwardIRSt24uniform_int_distributionIiEEOT_RNSt16remove_referenceIS3_E4typeE
	.def	_ZSt7forwardIRSt24uniform_int_distributionIiEEOT_RNSt16remove_referenceIS3_E4typeE;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt7forwardIRSt24uniform_int_distributionIiEEOT_RNSt16remove_referenceIS3_E4typeE
_ZSt7forwardIRSt24uniform_int_distributionIiEEOT_RNSt16remove_referenceIS3_E4typeE:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rax
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZSt13__invoke_implIiRSt24uniform_int_distributionIiEJRSt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEET_St14__invoke_otherOT0_DpOT1_,"x"
	.linkonce discard
	.globl	_ZSt13__invoke_implIiRSt24uniform_int_distributionIiEJRSt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEET_St14__invoke_otherOT0_DpOT1_
	.def	_ZSt13__invoke_implIiRSt24uniform_int_distributionIiEJRSt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEET_St14__invoke_otherOT0_DpOT1_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt13__invoke_implIiRSt24uniform_int_distributionIiEJRSt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEET_St14__invoke_otherOT0_DpOT1_
_ZSt13__invoke_implIiRSt24uniform_int_distributionIiEJRSt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEET_St14__invoke_otherOT0_DpOT1_:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$40, %rsp
	.seh_stackalloc	40
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.seh_endprologue
	movq	%rdx, -64(%rbp)
	movq	%r8, -56(%rbp)
	movq	-64(%rbp), %rcx
	call	_ZSt7forwardIRSt24uniform_int_distributionIiEEOT_RNSt16remove_referenceIS3_E4typeE
	movq	%rax, %rbx
	movq	-56(%rbp), %rax
	movq	%rax, %rcx
	call	_ZSt7forwardIRSt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEOT_RNSt16remove_referenceIS3_E4typeE
	movq	%rax, %rdx
	movq	%rbx, %rcx
	call	_ZNSt24uniform_int_distributionIiEclISt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEEiRT_
	addq	$40, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZNSt24uniform_int_distributionIiEclISt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEEiRT_,"x"
	.linkonce discard
	.align 2
	.globl	_ZNSt24uniform_int_distributionIiEclISt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEEiRT_
	.def	_ZNSt24uniform_int_distributionIiEclISt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEEiRT_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt24uniform_int_distributionIiEclISt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEEiRT_
_ZNSt24uniform_int_distributionIiEclISt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEEiRT_:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movq	16(%rbp), %rdx
	movq	24(%rbp), %rax
	movq	%rdx, %r8
	movq	%rax, %rdx
	movq	16(%rbp), %rcx
	call	_ZNSt24uniform_int_distributionIiEclISt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEEiRT_RKNS0_10param_typeE
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZNSt24uniform_int_distributionIiEclISt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEEiRT_RKNS0_10param_typeE,"x"
	.linkonce discard
	.align 2
	.globl	_ZNSt24uniform_int_distributionIiEclISt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEEiRT_RKNS0_10param_typeE
	.def	_ZNSt24uniform_int_distributionIiEclISt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEEiRT_RKNS0_10param_typeE;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt24uniform_int_distributionIiEclISt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEEiRT_RKNS0_10param_typeE
_ZNSt24uniform_int_distributionIiEclISt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEEEiRT_RKNS0_10param_typeE:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$88, %rsp
	.seh_stackalloc	88
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.seh_endprologue
	movq	%rcx, -16(%rbp)
	movq	%rdx, -8(%rbp)
	movq	%r8, 0(%rbp)
	movl	$0, -56(%rbp)
	movl	$-1, -60(%rbp)
	movl	$-1, -64(%rbp)
	movq	0(%rbp), %rax
	movq	%rax, %rcx
	call	_ZNKSt24uniform_int_distributionIiE10param_type1bEv
	movl	%eax, %ebx
	movq	0(%rbp), %rax
	movq	%rax, %rcx
	call	_ZNKSt24uniform_int_distributionIiE10param_type1aEv
	movl	%eax, %edx
	movl	%ebx, %eax
	subl	%edx, %eax
	movl	%eax, -68(%rbp)
	cmpl	$-1, -68(%rbp)
	je	.L93
	movl	-68(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movl	$-1, %eax
	movl	$0, %edx
	divl	-72(%rbp)
	movl	%eax, -76(%rbp)
	movl	-72(%rbp), %eax
	imull	-76(%rbp), %eax
	movl	%eax, -80(%rbp)
.L95:
	movq	-8(%rbp), %rax
	movq	%rax, %rcx
	call	_ZNSt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEclEv
	movl	%eax, -52(%rbp)
	movl	-52(%rbp), %eax
	cmpl	-80(%rbp), %eax
	jb	.L94
	jmp	.L95
.L94:
	movl	-52(%rbp), %eax
	movl	$0, %edx
	divl	-76(%rbp)
	movl	%eax, -52(%rbp)
	jmp	.L96
.L93:
	movq	-8(%rbp), %rax
	movq	%rax, %rcx
	call	_ZNSt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEclEv
	movl	%eax, -52(%rbp)
.L96:
	movq	0(%rbp), %rax
	movq	%rax, %rcx
	call	_ZNKSt24uniform_int_distributionIiE10param_type1aEv
	movl	%eax, %edx
	movl	-52(%rbp), %eax
	addl	%edx, %eax
	addq	$88, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZNKSt24uniform_int_distributionIiE10param_type1bEv,"x"
	.linkonce discard
	.align 2
	.globl	_ZNKSt24uniform_int_distributionIiE10param_type1bEv
	.def	_ZNKSt24uniform_int_distributionIiE10param_type1bEv;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNKSt24uniform_int_distributionIiE10param_type1bEv
_ZNKSt24uniform_int_distributionIiE10param_type1bEv:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rax
	movl	4(%rax), %eax
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZNKSt24uniform_int_distributionIiE10param_type1aEv,"x"
	.linkonce discard
	.align 2
	.globl	_ZNKSt24uniform_int_distributionIiE10param_type1aEv
	.def	_ZNKSt24uniform_int_distributionIiE10param_type1aEv;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNKSt24uniform_int_distributionIiE10param_type1aEv
_ZNKSt24uniform_int_distributionIiE10param_type1aEv:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rax
	movl	(%rax), %eax
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZNSt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEclEv,"x"
	.linkonce discard
	.align 2
	.globl	_ZNSt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEclEv
	.def	_ZNSt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEclEv;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEclEv
_ZNSt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EEclEv:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rax
	movq	2496(%rax), %rax
	cmpq	$623, %rax
	jbe	.L103
	movq	16(%rbp), %rcx
	call	_ZNSt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EE11_M_gen_randEv
.L103:
	movq	16(%rbp), %rax
	movq	2496(%rax), %rax
	leaq	1(%rax), %rcx
	movq	16(%rbp), %rdx
	movq	%rcx, 2496(%rdx)
	movq	16(%rbp), %rdx
	movl	(%rdx,%rax,4), %eax
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	shrl	$11, %eax
	xorl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	sall	$7, %eax
	andl	$-1658038656, %eax
	xorl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	sall	$15, %eax
	andl	$-272236544, %eax
	xorl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	shrl	$18, %eax
	xorl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZNSt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EE11_M_gen_randEv,"x"
	.linkonce discard
	.align 2
	.globl	_ZNSt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EE11_M_gen_randEv
	.def	_ZNSt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EE11_M_gen_randEv;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EE11_M_gen_randEv
_ZNSt23mersenne_twister_engineIjLy32ELy624ELy397ELy31ELj2567483615ELy11ELj4294967295ELy7ELj2636928640ELy15ELj4022730752ELy18ELj1812433253EE11_M_gen_randEv:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	$-2147483648, -20(%rbp)
	movl	$2147483647, -24(%rbp)
	movq	$0, -8(%rbp)
.L109:
	cmpq	$226, -8(%rbp)
	ja	.L106
	movq	16(%rbp), %rax
	movq	-8(%rbp), %rdx
	movl	(%rax,%rdx,4), %eax
	andl	$-2147483648, %eax
	movl	%eax, %ecx
	movq	-8(%rbp), %rax
	leaq	1(%rax), %rdx
	movq	16(%rbp), %rax
	movl	(%rax,%rdx,4), %eax
	andl	$2147483647, %eax
	orl	%ecx, %eax
	movl	%eax, -28(%rbp)
	movq	-8(%rbp), %rax
	leaq	397(%rax), %rdx
	movq	16(%rbp), %rax
	movl	(%rax,%rdx,4), %edx
	movl	-28(%rbp), %eax
	shrl	%eax
	xorl	%eax, %edx
	movl	-28(%rbp), %eax
	andl	$1, %eax
	testl	%eax, %eax
	je	.L107
	movl	$-1727483681, %eax
	jmp	.L108
.L107:
	movl	$0, %eax
.L108:
	xorl	%edx, %eax
	movl	%eax, %ecx
	movq	16(%rbp), %rax
	movq	-8(%rbp), %rdx
	movl	%ecx, (%rax,%rdx,4)
	addq	$1, -8(%rbp)
	jmp	.L109
.L106:
	movq	$227, -16(%rbp)
.L113:
	cmpq	$622, -16(%rbp)
	ja	.L110
	movq	16(%rbp), %rax
	movq	-16(%rbp), %rdx
	movl	(%rax,%rdx,4), %eax
	andl	$-2147483648, %eax
	movl	%eax, %ecx
	movq	-16(%rbp), %rax
	leaq	1(%rax), %rdx
	movq	16(%rbp), %rax
	movl	(%rax,%rdx,4), %eax
	andl	$2147483647, %eax
	orl	%ecx, %eax
	movl	%eax, -32(%rbp)
	movq	-16(%rbp), %rax
	leaq	-227(%rax), %rdx
	movq	16(%rbp), %rax
	movl	(%rax,%rdx,4), %edx
	movl	-32(%rbp), %eax
	shrl	%eax
	xorl	%eax, %edx
	movl	-32(%rbp), %eax
	andl	$1, %eax
	testl	%eax, %eax
	je	.L111
	movl	$-1727483681, %eax
	jmp	.L112
.L111:
	movl	$0, %eax
.L112:
	xorl	%edx, %eax
	movl	%eax, %ecx
	movq	16(%rbp), %rax
	movq	-16(%rbp), %rdx
	movl	%ecx, (%rax,%rdx,4)
	addq	$1, -16(%rbp)
	jmp	.L113
.L110:
	movq	16(%rbp), %rax
	movl	2492(%rax), %eax
	andl	$-2147483648, %eax
	movl	%eax, %edx
	movq	16(%rbp), %rax
	movl	(%rax), %eax
	andl	$2147483647, %eax
	orl	%edx, %eax
	movl	%eax, -36(%rbp)
	movq	16(%rbp), %rax
	movl	1584(%rax), %edx
	movl	-36(%rbp), %eax
	shrl	%eax
	xorl	%eax, %edx
	movl	-36(%rbp), %eax
	andl	$1, %eax
	testl	%eax, %eax
	je	.L114
	movl	$-1727483681, %eax
	jmp	.L115
.L114:
	movl	$0, %eax
.L115:
	xorl	%eax, %edx
	movq	16(%rbp), %rax
	movl	%edx, 2492(%rax)
	movq	16(%rbp), %rax
	movq	$0, 2496(%rax)
	nop
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.text
	.def	__tcf_0;	.scl	3;	.type	32;	.endef
	.seh_proc	__tcf_0
__tcf_0:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	leaq	_ZStL8__ioinit(%rip), %rcx
	call	_ZNSt8ios_base4InitD1Ev
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	_Z41__static_initialization_and_destruction_0ii;	.scl	3;	.type	32;	.endef
	.seh_proc	_Z41__static_initialization_and_destruction_0ii
_Z41__static_initialization_and_destruction_0ii:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movl	%edx, 24(%rbp)
	cmpl	$1, 16(%rbp)
	jne	.L119
	cmpl	$65535, 24(%rbp)
	jne	.L119
	leaq	_ZStL8__ioinit(%rip), %rcx
	call	_ZNSt8ios_base4InitC1Ev
	leaq	__tcf_0(%rip), %rcx
	call	atexit
.L119:
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	_GLOBAL__sub_I_main;	.scl	3;	.type	32;	.endef
	.seh_proc	_GLOBAL__sub_I_main
_GLOBAL__sub_I_main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movl	$65535, %edx
	movl	$1, %ecx
	call	_Z41__static_initialization_and_destruction_0ii
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.ctors,"w"
	.align 8
	.quad	_GLOBAL__sub_I_main
	.ident	"GCC: (GNU) 10.2.0"
	.def	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc;	.scl	2;	.type	32;	.endef
	.def	_ZNSirsERi;	.scl	2;	.type	32;	.endef
	.def	_ZNSolsEPFRSoS_E;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	atexit;	.scl	2;	.type	32;	.endef
	.section	.rdata$.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, "dr"
	.globl	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	.linkonce	discard
.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_:
	.quad	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	.section	.rdata$.refptr._ZSt3cin, "dr"
	.globl	.refptr._ZSt3cin
	.linkonce	discard
.refptr._ZSt3cin:
	.quad	_ZSt3cin
	.section	.rdata$.refptr._ZSt4cout, "dr"
	.globl	.refptr._ZSt4cout
	.linkonce	discard
.refptr._ZSt4cout:
	.quad	_ZSt4cout
