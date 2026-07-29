#ifndef __time_H
#define __time_H

#include "sys/types.h"
#include "sys/select.h"

typedef uint32_t clock_t;
typedef uint32_t time_t;
typedef uint32_t suseconds_t;

struct timeval {
	time_t tv_sec;
	suseconds_t tv_usec;
};

struct tm {
    int tm_sec;
    int tm_min;
    int tm_hour;
    int tm_mday;
    int tm_mon;
    int tm_year;
    int tm_wday;
    int tm_yday;
    int tm_isdst;
    long tm_gmtoff;
    const char* tm_zone;
};

clock_t clock(void);
double difftime(time_t, time_t);
time_t mktime(struct tm*);
char* asctime(const struct tm*);
char* ctime(const time_t*);
struct tm* gmtime(const time_t*);
struct tm* localtime(const time_t*);
size_t strftime(char *__restrict, size_t, const char *__restrict, const struct tm *__restrict)__attribute__((__bounded__(__string__,1,2)));
time_t time(time_t*);

#endif
