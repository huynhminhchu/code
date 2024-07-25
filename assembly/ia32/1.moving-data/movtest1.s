.section .data
value:
  .int 1

.section .text
.globl _start
_start:
  movl value, %eax
  movl $1, %eax
  movl $0, %ebx
  int $0x80

