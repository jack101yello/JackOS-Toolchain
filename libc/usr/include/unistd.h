#ifndef __unistd_H
#define __unistd_H

#include "sys/types.h"
#include "fcntl.h"

typedef int pid_t;
typedef int32_t ssize_t;
typedef int32_t intptr_t;

#define STDIN_FILENO    0
#define STDOUT_FILENO   1
#define STDERR_FILENO   2
#define F_OK 0

pid_t fork(void);
int execv(const char* path, char *const argv[]);
int execve(const char* path, char *const argv[], char *const envp[]);
int execvp(const char* path, char *const argv[]);
ssize_t write(int, const void*, uint32_t);
ssize_t read(int, void*, size_t)__attribute__((__bounded__(__buffer__,2,3)));
off_t lseek(int, off_t, int);
int open(const char*, int flags, ...);
int close(int);
void _exit(int status);

#endif
