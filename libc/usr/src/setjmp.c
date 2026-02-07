#include <setjmp.h>

int setjmp(jmp_buf buf) {
    (void)buf;
    asm(
        "mov (%esp), %eax\n\t"
        "mov %eax, 0(%ecx)\n\t"
        "lea 8(%esp), %eax\n\t"
        "mov %eax, 8(%ecx)\n\t"
        "mov %ebp, 16(%ecx)\n\t"
        "mov %ebx, 24(%ecx)\n\t"
        "mov %edi, 32(%ecx)\n\t"
        "mov %esi, 40(%ecx)\n\t"
        "xor %eax, %eax\n\t"
        "ret\n"
    );
}

void longjmp(jmp_buf buf, int ret) {
    (void)buf;
    (void)ret;
    asm(
        "mov 40(%ecx), %esi\n"
        "mov 32(%ecx), %edi\n"
        "mov 24(%ecx), %ebx\n"
        "mov 16(%ecx), %ebp\n"
        "mov  8(%ecx), %esp\n"
        "mov %edx, %eax\n"
        "jmp *0(%ecx)\n"
    );
}