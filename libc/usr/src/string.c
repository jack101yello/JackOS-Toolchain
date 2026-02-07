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
    int index = 0;
    while(str[index] != '\0' && index < 1024*1024) index++;
    return index;
}

char* strcpy(char* dest, const char* src) {
    return (char*)0;
}