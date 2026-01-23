#ifndef __string_H
#define __string_H

#include "sys/types.h"

void* memcpy(void* dest, const void* src, uint32_t len);
void* memset(void* dest, uint8_t val, uint32_t len);
int strlen(const char* str);
char* strcpy(char* dest, const char* src);
void *memchr(const void*, int, uint32_t);
int memcmp(const void*, const void*, uint32_t);
void *memmove(void*, const void*, uint32_t);
char* strcat(char *__restrict, const char*__restrict);
int strcmp(const char*, const char*);
int strcoll(const char*, const char*);
uint32_t strcspn(const char*, const char*);
char* strerror(int);
char* strncat(char *__restrict, const char*__restrict, uint32_t)__attribute__((__bounded__(__string__,1,3)));
int strncmp(const char*, const char*, uint32_t);
char* strncpy(char *__restrict, const char *__restrict, uint32_t);
uint32_t strspn(const char*, const char*);
char* strtok(char *__restrict, const char *__restrict);
uint32_t strxfrm(char *__restrict, const char *__restrict, uint32_t)__attribute__((__bounded__(__string,1,3)));
char* strchr(const char*, int);
char* strpbrk(const char*, const char*);
char* strrchr(const char*, int);
char* strstr(const char*, const char*);

#endif