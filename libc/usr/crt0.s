.global _start
.extern main
.section .text
_start:
    xor %ebp, %ebp
    and $-16, %esp

    push $0
    push $0
    push $0
    call main
    push %eax
    call exit

1:
    hlt
    jmp 1b
