#ifndef __stdlib_H
#define __stdlib_H

#include "sys/types.h"
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stddef.h>

typedef struct {
    int quot;
    int rem;
} div_t;

typedef struct {
    long quot;
    long rem;
} ldiv_t;

void abort(void);
void* malloc(uint32_t size);
void* calloc(uint32_t num, uint32_t size);
void free(void* ptr);
int atexit(void (*)(void));
int atoi(const char* str);
char* getenv(const char* msg);
void* calloc(uint32_t num, uint32_t size);
int abs(int n);
double atof(const char*);
long atol(const char*);
void* bsearch(const void*, const void*, size_t, size_t, int (*)(const void*, const void*));
div_t div(int, int);
void exit(int);
long labs(long);
ldiv_t ldiv(long, long);
void qsort(void*, size_t, size_t, int(*)(const void*, const void*));
int rand(void);
void* realloc(void*, uint32_t);
void srand(unsigned);
double strtod(const char*__restrict, char**__restrict);
long strtol(const char*__restrict, char**__restrict, int);
float strtof(const char*__trstrict, char**__restrict);
unsigned long strtoul(const char*__restrict, char **__restrict, int);
int system(const char*);

#endif