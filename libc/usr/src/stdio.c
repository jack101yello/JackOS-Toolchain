#include <stdio.h>

int puts(const char* message) {
    return printf(message);
}

int printf(const char* message, ...) {
    asm volatile(
        "int $0x80"
        :
        : "a"(0x0), "c"(message)
    );
    return 0;
}

int fflush(FILE* file) {
    return -1;
}

int fprintf(FILE* file, const char* msg, ...) {
    return -1;
}

int getchar() {
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

char* fgets(char* buffer, int linenumber, FILE* file) {
	return (char*)0;
}

int ferror(FILE* file) {
	return 0;
}

int fileno(FILE* file) {
	return 0;
}

FILE* stdin = NULL;
FILE* stdout = NULL;
FILE* stderr = NULL;
