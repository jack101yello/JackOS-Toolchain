#include "../include/string.h"

void* memcpy(void* dest, const void* src, uint32_t len) {
    const uint8_t* sp = (const uint8_t*)src;
    uint8_t* dp = (uint8_t*)dest;
    for(; len != 0; len--) {
        *dp++ = *sp++;
    }
    return dest;
}

void* memset(void* dest, uint8_t val, uint32_t len) {
    uint8_t* temp = (uint8_t*)dest;
    for(; len != 0; len--) {
        *temp++ = val;
    }
    return dest;
}

int strlen(const char* str) {
    return sizeof(str) / sizeof(const char);
}

char* strcpy(char* dest, const char* src) {
    return (char*)0;
}