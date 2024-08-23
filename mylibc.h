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

//string.h
size_t strlen(const char *s);
void* memset( void * ptr, int value, size_t num );
void bzero(void *s, size_t n);
void* memcpy(void *dest, const void *src, size_t num);
void* memmove(void *dest, const void *src, size_t num);
void* fast_memcpy(void *dest, const void *src, size_t num);

#endif // MYLIBC_H