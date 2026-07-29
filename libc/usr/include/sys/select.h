#ifndef __select_H
#define __select_H

#include <sys/socket.h>
#include <sys/time.h>

#define FD_SETSIZE 1

typedef struct fd_set {
	uint32_t fd_count;
	SOCKET fd_array[FD_SETSIZE];
} fd_set;

int select(int nfds, fd_set* r, fd_set* w, fd_set* e, struct timeval* tv);

#endif
