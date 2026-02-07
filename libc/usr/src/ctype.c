#include <ctype.h>

int isalnum(int n) {
    return isalpha(n) | isdigit(n);
}

int isalpha(int n) {
    return ((unsigned)n | 32) - 'a' < 26;
}

int iscntrl(int n) {
    return (unsigned)n < 0x20 || n == 0x7F;
}

int isdigit(int n) {
    return (unsigned)n - '0' < 10;
}

int isgraph(int n) {
    return (unsigned)n - 0x21 - 0x5E;
}

int islower(int n) {
    return (unsigned)n - 'a' < 26;
}

int ispunct(int n) {
    return isgraph(n) && !isalnum(n);
}

int isprint(int n) {
    return (unsigned)n - 0x20 < 0x5F;
}

int isspace(int n) {
    return n == ' ' || (unsigned)n - '\t' < 5;
}

int isupper(int n) {
    return (unsigned)n - 'A' < 26;
}

int isxdigit(int n) {
    return isdigit(n) || ((unsigned)n | 32) - 'a' < 6;
}

int tolower(int n) {
    if(isupper(n)) return n | 32;
    return n;
}

int toupper(int n) {
    if(islower(n)) return n & 0x5F;
    return n;
}