	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 13, 0	sdk_version 14, 0
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
Lloh0:
	adrp	x0, _array@PAGE
Lloh1:
	add	x0, x0, _array@PAGEOFF
	mov	w1, #2
	b	_sum
	.loh AdrpAdd	Lloh0, Lloh1
	.cfi_endproc
                                        ; -- End function
	.section	__DATA,__data
	.globl	_array                          ; @array
	.p2align	2, 0x0
_array:
	.long	1                               ; 0x1
	.long	2                               ; 0x2
	.long	3                               ; 0x3

.subsections_via_symbols
