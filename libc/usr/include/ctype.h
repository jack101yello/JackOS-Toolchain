#ifndef __ctype_H
#define __ctype_H

#define _U 0x01
#define _L 0x02
#define _N 0x04
#define _S 0x08
#define _P 0x10
#define _C 0x20
#define _X 0x40
#define _B 0x80

int isalnum(int);
int isalpha(int);
int iscntrl(int);
int isdigit(int);
int isgraph(int);
int islower(int);
int ispunct(int);
int isprint(int);
int isspace(int);
int isupper(int);
int isxdigit(int);
int tolower(int);
int toupper(int);
int isblank(int);

extern const char* _ctype_;

#endif
