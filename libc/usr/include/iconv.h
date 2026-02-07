#ifndef __iconv_H
#define __iconv_H

#include <sys/types.h>

typedef void* iconv_t;
typedef uint32_t descriptor_type;

size_t iconv(iconv_t, char**, size_t*, char**, size_t*);
iconv_t iconv_open(const char* to_code, const char* from_code);
int iconv_close(iconv_t cd);

#endif
