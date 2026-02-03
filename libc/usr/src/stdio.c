#include <stdio.h>

void abort(void) {

}

void* malloc(uint32_t size) {
    return (void*)0;
}

void free(void* ptr) {
    return;
}

int atexit(void (*)(void)) {
    return -1;
}

char* getenv(const char* msg) {
    return "\0";
}

void* calloc(uint32_t num, uint32_t size) {
    return (void*)0;
}

int abs(int n) {
    return (n >= 0) ? n : -n;
}

int puts(const char* message) {
    return printf(message);
}

int printf(const char* message, ...) {
    asm volatile(
        "int $0x80"
        :
        : "a"(0), "c"(message)
    );
    return 0;
}

int getchar() {
    return -1;
}

FILE* stdin = NULL;
FILE* stdout = NULL;
FILE* stderr = NULL;
