	.file	"vtable.cpp"
	.text
	.section .rdata,"dr"
_ZStL19piecewise_construct:
	.space 1
.lcomm _ZStL8__ioinit,1,1
.LC0:
	.ascii "A\0"
	.section	.text$_ZN1A5printEv,"x"
	.linkonce discard
	.align 2
	.globl	_ZN1A5printEv
	.def	_ZN1A5printEv;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN1A5printEv
_ZN1A5printEv:
.LFB1578:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	leaq	.LC0(%rip), %rdx
	movq	.refptr._ZSt4cout(%rip), %rcx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movq	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_(%rip), %rdx
	movq	%rax, %rcx
	call	_ZNSolsEPFRSoS_E
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC1:
	.ascii "B\0"
	.section	.text$_ZN1B5printEv,"x"
	.linkonce discard
	.align 2
	.globl	_ZN1B5printEv
	.def	_ZN1B5printEv;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN1B5printEv
_ZN1B5printEv:
.LFB1579:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	leaq	.LC1(%rip), %rdx
	movq	.refptr._ZSt4cout(%rip), %rcx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movq	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_(%rip), %rdx
	movq	%rax, %rcx
	call	_ZNSolsEPFRSoS_E
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC2:
	.ascii "C\0"
	.section	.text$_ZN1C5printEv,"x"
	.linkonce discard
	.align 2
	.globl	_ZN1C5printEv
	.def	_ZN1C5printEv;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN1C5printEv
_ZN1C5printEv:
.LFB1580:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	leaq	.LC2(%rip), %rdx
	movq	.refptr._ZSt4cout(%rip), %rcx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movq	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_(%rip), %rdx
	movq	%rax, %rcx
	call	_ZNSolsEPFRSoS_E
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZN1AC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	_ZN1AC2Ev
	.def	_ZN1AC2Ev;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN1AC2Ev
_ZN1AC2Ev:
.LFB1585:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	leaq	16+_ZTV1A(%rip), %rdx
	movq	16(%rbp), %rax
	movq	%rdx, (%rax)
	nop
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZN1BC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	_ZN1BC2Ev
	.def	_ZN1BC2Ev;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN1BC2Ev
_ZN1BC2Ev:
.LFB1587:
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
	call	_ZN1AC2Ev
	leaq	16+_ZTV1B(%rip), %rdx
	movq	16(%rbp), %rax
	movq	%rdx, (%rax)
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZN1CC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	_ZN1CC1Ev
	.def	_ZN1CC1Ev;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN1CC1Ev
_ZN1CC1Ev:
.LFB1590:
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
	call	_ZN1BC2Ev
	leaq	16+_ZTV1C(%rip), %rdx
	movq	16(%rbp), %rax
	movq	%rdx, (%rax)
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB1581:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$72, %rsp
	.seh_stackalloc	72
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.seh_endprologue
	call	__main
	movl	$8, %ecx
	call	_Znwm
	movq	%rax, %rbx
	movq	$0, (%rbx)
	movq	%rbx, %rcx
	call	_ZN1CC1Ev
	movq	%rbx, -72(%rbp)
	movq	-72(%rbp), %rax
	movq	(%rax), %rax
	movq	(%rax), %rdx
	movq	-72(%rbp), %rax
	movq	%rax, %rcx
	call	*%rdx
	movq	-72(%rbp), %rax
	movq	%rax, -80(%rbp)
	movq	-80(%rbp), %rax
	movq	(%rax), %rax
	movq	(%rax), %rdx
	movq	-80(%rbp), %rax
	movq	%rax, %rcx
	call	*%rdx
	movq	-80(%rbp), %rax
	movq	%rax, -88(%rbp)
	movq	-88(%rbp), %rax
	movq	(%rax), %rax
	movq	(%rax), %rdx
	movq	-88(%rbp), %rax
	movq	%rax, %rcx
	call	*%rdx
	movl	$0, %eax
	addq	$72, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.globl	_ZTV1C
	.section	.rdata$_ZTV1C,"dr"
	.linkonce same_size
	.align 8
_ZTV1C:
	.quad	0
	.quad	_ZTI1C
	.quad	_ZN1C5printEv
	.globl	_ZTV1B
	.section	.rdata$_ZTV1B,"dr"
	.linkonce same_size
	.align 8
_ZTV1B:
	.quad	0
	.quad	_ZTI1B
	.quad	_ZN1B5printEv
	.globl	_ZTV1A
	.section	.rdata$_ZTV1A,"dr"
	.linkonce same_size
	.align 8
_ZTV1A:
	.quad	0
	.quad	_ZTI1A
	.quad	_ZN1A5printEv
	.globl	_ZTI1C
	.section	.rdata$_ZTI1C,"dr"
	.linkonce same_size
	.align 8
_ZTI1C:
	.quad	_ZTVN10__cxxabiv120__si_class_type_infoE+16
	.quad	_ZTS1C
	.quad	_ZTI1B
	.globl	_ZTS1C
	.section	.rdata$_ZTS1C,"dr"
	.linkonce same_size
_ZTS1C:
	.ascii "1C\0"
	.globl	_ZTI1B
	.section	.rdata$_ZTI1B,"dr"
	.linkonce same_size
	.align 8
_ZTI1B:
	.quad	_ZTVN10__cxxabiv120__si_class_type_infoE+16
	.quad	_ZTS1B
	.quad	_ZTI1A
	.globl	_ZTS1B
	.section	.rdata$_ZTS1B,"dr"
	.linkonce same_size
_ZTS1B:
	.ascii "1B\0"
	.globl	_ZTI1A
	.section	.rdata$_ZTI1A,"dr"
	.linkonce same_size
	.align 8
_ZTI1A:
	.quad	_ZTVN10__cxxabiv117__class_type_infoE+16
	.quad	_ZTS1A
	.globl	_ZTS1A
	.section	.rdata$_ZTS1A,"dr"
	.linkonce same_size
_ZTS1A:
	.ascii "1A\0"
	.text
	.def	_Z41__static_initialization_and_destruction_0ii;	.scl	3;	.type	32;	.endef
	.seh_proc	_Z41__static_initialization_and_destruction_0ii
_Z41__static_initialization_and_destruction_0ii:
.LFB2019:
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
	jne	.L11
	cmpl	$65535, 24(%rbp)
	jne	.L11
	leaq	_ZStL8__ioinit(%rip), %rcx
	call	_ZNSt8ios_base4InitC1Ev
	movq	.refptr.__dso_handle(%rip), %r8
	leaq	_ZStL8__ioinit(%rip), %rdx
	movq	.refptr._ZNSt8ios_base4InitD1Ev(%rip), %rcx
	call	__cxa_atexit
.L11:
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	_GLOBAL__sub_I_main;	.scl	3;	.type	32;	.endef
	.seh_proc	_GLOBAL__sub_I_main
_GLOBAL__sub_I_main:
.LFB2020:
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
	.def	_ZNSolsEPFRSoS_E;	.scl	2;	.type	32;	.endef
	.def	__real__Znwm;	.scl	2;	.type	32;	.endef
	.def	_Znwm;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	__cxa_atexit;	.scl	2;	.type	32;	.endef
	.section	.rdata$.refptr._ZNSt8ios_base4InitD1Ev, "dr"
	.globl	.refptr._ZNSt8ios_base4InitD1Ev
	.linkonce	discard
.refptr._ZNSt8ios_base4InitD1Ev:
	.quad	_ZNSt8ios_base4InitD1Ev
	.section	.rdata$.refptr.__dso_handle, "dr"
	.globl	.refptr.__dso_handle
	.linkonce	discard
.refptr.__dso_handle:
	.quad	__dso_handle
	.section	.rdata$.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, "dr"
	.globl	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	.linkonce	discard
.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_:
	.quad	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	.section	.rdata$.refptr._ZSt4cout, "dr"
	.globl	.refptr._ZSt4cout
	.linkonce	discard
.refptr._ZSt4cout:
	.quad	_ZSt4cout
