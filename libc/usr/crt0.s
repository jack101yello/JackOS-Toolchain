.global _start
.extern main
.extern _init
.extern _fini
.section .text
_start:
    # Set up user-mode data segments
    mov $0x2B, %ax
    mov %ax, %ds
    mov %ax, %es
    mov %ax, %fs
    mov %ax, %gs

	mov 4(%esp), %esi ;# argc
	mov 8(%esp), %edi ;# argv

    xor %ebp, %ebp
    and $-16, %esp

    call _init # Call global constructors

    push %edi
    push %esi
    call main
	add $8, %esp

    push %eax
    call _fini
    pop %eax

    push %eax
    call exit

1:
    hlt
    jmp 1b
