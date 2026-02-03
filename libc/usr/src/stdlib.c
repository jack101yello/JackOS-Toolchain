#include <stdlib.h>

int fflush(FILE* file) {
    return -1;
}

int fprintf(FILE* file, const char* msg, ...) {
    return -1;
}

int atoi(const char* str) {
    return -1;
}

int fclose(FILE* file) {
    return -1;
}

FILE* fopen(const char* filename, const char* mode) {
    return (FILE*)0;
}

uint32_t fread(void* ptr, uint32_t size, uint32_t nmemb, FILE* file) {
    return -1;
}

int fseek(FILE* file, long offset, int whence) {
    return -1;
}

long ftell(FILE* file) {
    return -1;
}

uint32_t fwrite(const void* ptr, uint32_t size, uint32_t nmemb, FILE* file) {
    return -1;
}

void setbuf(FILE* file, char* str) {
    return;
}

extern void _fini(void);
void exit(int status) {
    _fini();
    asm volatile(
        "int $0x80"
        :
        : "a"(0x5)
    );
    while(1);
}