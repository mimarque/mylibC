#ifndef MYLIBC_H
#define MYLIBC_H
#include <sys/types.h>
#include <stdlib.h>
#include <stdbool.h>

// ctype.h
int isalnum(int c);
int isalpha(int c);
int isascii(int c);
int isblank(int c);
int iscntrl(int c);
int isdigit(int c);
int isgraph(int c);
int islower(int c);
int isprint(int c);
int ispunct(int c);
int isspace(int c);
int isupper(int c);
int isxdigit(int c);
int tolower(int c);
int toupper(int c);

//stdlib.h
void *calloc(size_t num, size_t size);

//strings.h
void bzero(void *s, size_t n);
void *memccpy(void *dest, const void *src, int c, size_t n);
void *memchr(const void *s, int c, size_t n);
int memcmp(const void *ptr1, const void *ptr2, size_t num);
void *memcpy(void *dest, const void *src, size_t n);
void *memmove(void *dest, const void *src, size_t num);
void *memset(void *s, int c, size_t n);

//string.h



#endif // MYLIBC_H