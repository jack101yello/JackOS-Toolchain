#include "../include/unistd.h"

pid_t fork(void) {
    return -1;
}

int execv(const char* path, char *const argv[]) {
    return -1;
}

int execve(const char* path, char *const argv[], char *const envp[]) {
    return -1;
}

int execvp(const char* path, char *const argv[]) {
    return -1;
}

void _exit(int status) {
	return;
}
