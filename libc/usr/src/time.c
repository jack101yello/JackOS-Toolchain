#include <sys/time.h>
#include <sys/select.h>

int select(int nfds, fd_set* r, fd_set* w, fd_set* e, struct timeval* tv) {
	return 0;
}

int gettimeofday(struct timeval* tv, struct timezone* tz) {
	return (int)tv -> tv_sec;
}
