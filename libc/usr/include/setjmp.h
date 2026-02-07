#ifndef __setjmp_H
#define __setjmp_H

typedef void* jmp_buf[10];

int setjmp(jmp_buf);
void longjmp(jmp_buf, int);

#endif