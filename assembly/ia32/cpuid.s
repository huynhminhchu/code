#cpuid.s Sample program to extract the processor Vendor ID

.section .data
  # initialized data here
output:
  .ascii "The processor Vendor ID is 'xxxxxxxxxxxx'\n"
msg:
  .ascii "hello darkness my old friend\n"
buffer:
  .fill 10000

.section .bss
  # Uninitialized data here
# assign a 10000 byte memory area to the buffer label, local common can be accessed only in the function declared
.lcomm buffer, 10000

.section .text
.globl _start
_start:
  movl $0, %eax
  cpuid
  movl $output, %edi
  movl %ebx, 28(%edi)
  movl %edx, 32(%edi)
  movl %ecx, 36(%edi)
  movl $4, %eax
  movl $1, %ebx
  movl $output, %ecx
  movl $42, %edx
  int $0x80
  movl $4, %eax
  movl $1, %ebx
  movl $msg, %ecx
  movl $29, %edx
  int $0x80
  movl $1, %eax
  movl $0, %ebx
  int $0x80
