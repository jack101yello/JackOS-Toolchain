.global _start
.extern main
.extern _init
.extern _fini
.section .text
_start:
    xor %ebp, %ebp
    and $-16, %esp

    call _init # Call global constructors

    push $0
    push $0
    push $0
    call main

    push %eax
    call _fini
    pop %eax

    push %eax
    call exit

1:
    hlt
    jmp 1b
