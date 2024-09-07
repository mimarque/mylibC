#ifndef MYLIBC_H
#define MYLIBC_H
#include <sys/types.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

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

//notstd.h
void putbnbr_fd(int n, int base, int fd);
void putchar_fd(char c, int fd);
void putendl_fd(const char *str, int fd);
void putnbr_fd(int n, int fd);
void putstr_fd(const char *str, int fd);
char **split(const char *str, char delim);
void free_split(char **arr);
char *strjoin(const char *s1, const char *s2);
char *substr(const char *str, size_t start, size_t len);

//stdlib.h
long atol(const char *str);
int atoi(const char *str);
unsigned long atoul(const char *str);
unsigned int atoui(const char *str);
void *calloc(size_t num, size_t size);
char *itoa(int value);
char *uitoa(unsigned int value);
char *itoa_base(int value, int base);
char *uitoa_base(unsigned int value, int base);
//utils.c
int count_digits(int value);
int count_digits_in_base(int value, int base);
//int count_digits_in_base_log(int value, int base); //needs #include <math.h> and uncomment
int hexvalue(char c);

//string.h
char *strchr(const char *s, int c);
char *strcpy(char *dest, const char *src);
char *strdup(const char *s);
size_t strlcpy(char *dest, const char *src, size_t dstsize);
size_t strlen(const char *s);
size_t strnlen(const char *s, size_t maxlen);


//strings.h
void bzero(void *s, size_t n);
void *memccpy(void *dest, const void *src, int c, size_t n);
void *memchr(const void *s, int c, size_t n);
int memcmp(const void *ptr1, const void *ptr2, size_t num);
void *memcpy(void *dest, const void *src, size_t n);
void *fast_memcpy(void *dest, const void *src, size_t n);
void *memmove(void *dest, const void *src, size_t num);
void *memset(void *s, int c, size_t n);

//non-standard functions
void *fast_memcpy(void *dest, const void *src, size_t n);
char *itoa(int value);
char *uitoa(unsigned int value);


//axiliary functions
int hexvalue(char c);
int count_digits(int value);
int count_digits_in_base(int value, int base);
//int count_digits_in_base_log(int value, int base); //needs #include <math.h> and uncomment


#endif // MYLIBC_H