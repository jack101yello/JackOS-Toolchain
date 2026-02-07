#include <locale.h>

char* setlocale(int category, const char* locale) {
    return (char*)0;
}

struct lconv* localeconv(void) {
    return (struct lconv*)0;
}