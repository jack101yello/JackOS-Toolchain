#ifndef __signal_H
#define __signal_H

#include <sys/types.h>
#include <errno.h>

typedef uint32_t sig_atomic_t;

typedef void (*sighandler_t)(int);

sighandler_t signal(int, sighandler_t);
int raise(int);

#endif