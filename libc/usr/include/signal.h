#ifndef __signal_H
#define __signal_H

#include <sys/types.h>
#include <errno.h>

#define SIGHUP 1
#define SIGINT 2
#define SIGTERM 15
#define SIG_DFL (void (*)(int)) 0

typedef uint32_t sig_atomic_t;

typedef void (*sighandler_t)(int);

sighandler_t signal(int, sighandler_t);
int raise(int);

#endif
