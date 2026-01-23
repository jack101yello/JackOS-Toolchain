#ifndef __stdio_H
#define __stdio_H

#include "sys/types.h"

#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2
#define EOF (-1)
typedef struct { int unused; } FILE;
extern FILE* stderr;
extern FILE* stdin;
extern FILE* stdout;
typedef void* __va_list;
#define BUFSIZ 1024
#define _IOFBF 0
#define _IOLBF 1
#define _IONBF 2
#define NULL 0

int fflush(FILE* file);
int fprintf(FILE* file, const char* msg, ...);
int fclose(FILE* file);
FILE* fopen(const char* filename, const char* mode);
FILE* fdopen(int, const char*);
uint32_t fread(void* ptr, uint32_t size, uint32_t nmemb, FILE* file);
int fseek(FILE* file, long offset, int whence);
long ftell(FILE* file);
uint32_t fwrite(const void* ptr, uint32_t size, uint32_t nmemb, FILE* file);
void setbuf(FILE* file, char* str);
void clearerr(FILE*);
int feof(FILE*);
int ferror(FILE*);
int fgetc(FILE*);
int fgetpos(FILE*, fpos_t*);
char* fgets(char*, int, FILE*)__attribute__((__bounded__(__string__,1,2)));
int fputc(int, FILE*);
int fputs(const char*, FILE*);
FILE* freopen(const char*, const char*, FILE*);
int fscanf(FILE*, const char*, ...);
int fsetpos(FILE*, const fpos_t*);
int getc(FILE*);
int getchar(void);
void perror(const char*);
int printf(const char* __restrict, ...);
int putc(int, FILE*);
int putchar(int);
int puts(const char*);
int remove(const char*);
int rename(const char*, const char*);
void rewind(FILE*);
int scanf(const char*, ...);
int setvbuf(FILE*, char*, int, uint32_t);
int sprintf(char * __restrict, const char* __restrict, ...);
int sscanf(const char*, const char *, ...);
FILE* tmpfile(void);
int ungetc(int, FILE*);
int vfprintf(FILE*, const char * __restrict, __va_list);
int vprintf(const char* __restrict, __va_list);
int vsprintf(const * __restrict, const char * __restrict, __va_list);
int fputs(const char*, FILE*);
int fileno(FILE*);

#endif