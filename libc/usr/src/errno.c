#include <errno.h>

int* __errno(void) {
	static int _errno = 0;
	return &_errno;
}
