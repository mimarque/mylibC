#ifndef MYLIBC_H
#define MYLIBC_H
#include <sys/types.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

int my_isalnum(int c);
int my_isalpha(int c);
int my_isascii(int c);
int my_isblank(int c);
int my_iscntrl(int c);
int my_isdigit(int c);
int my_isgraph(int c);
int my_islower(int c);
int my_isprint(int c);
int my_ispunct(int c);
int my_isspace(int c);
int my_isupper(int c);
int my_isxdigit(int c);
int my_tolower(int c);
int my_toupper(int c);


//notstd.h
void my_putbnbr_fd(int n, int base, int fd);
void my_putchar_fd(char c, int fd);
void my_putendl_fd(const char *str, int fd);
void my_putnbr_fd(int n, int fd);
void my_putstr_fd(const char *str, int fd);
char **my_split(const char *str, char delim);
void my_free_split(char **arr);
char *my_strjoin(const char *s1, const char *s2);
char *my_strmapi(const char *s, char (*f)(unsigned int, char));
char *my_strtrim(const char *s, const char *set);
char *my_substr(const char *str, size_t start, size_t len);


//stdlib.h
long my_atol(const char *str);
int my_atoi(const char *str);
unsigned long my_atoul(const char *str);
unsigned int my_atoui(const char *str);
void *my_calloc(size_t num, size_t size);
char *my_itoa(int value);
char *my_uitoa(unsigned int value);
char *my_itoa_base(int value, int base);
char *my_uitoa_base(unsigned int value, int base);
//utils.c
int my_count_digits(int value);
int my_count_digits_in_base(int value, int base);
//int my_count_digits_in_base_log(int value, int base); //needs #include <math.h> and uncomment
int my_hexvalue(char c);


//string.h
char *my_strcat(char *dest, const char *src);
char *my_strchr(const char *s, int c);
int my_strcmp(const char *s1, const char *s2);
char *my_strcpy(char *dest, const char *src);
char *my_strdup(const char *s);
size_t my_strlcat(char *dest, const char *src, size_t dstsize);
size_t my_strlcpy(char *dest, const char *src, size_t dstsize);
size_t my_strlen(const char *s);
size_t my_strnlen(const char *s, size_t maxlen);
char *my_strncat(char *dest, const char *src, size_t n);
int my_strncmp(const char *s1, const char *s2, size_t n);
char *my_strncpy(char *dest, const char *src, size_t n);
char *my_strndup(const char *s, size_t n);
char *my_strnstr(const char *haystack, const char *needle, size_t len);
char *my_strrchr(const char *s, int c);
char *my_strstr(const char *s, const char *find);


//strings.h
void my_bzero(void *s, size_t n);
void *my_memccpy(void *dest, const void *src, int c, size_t n);
void *my_memchr(const void *s, int c, size_t n);
int my_memcmp(const void *ptr1, const void *ptr2, size_t num);
void *my_memcpy(void *dest, const void *src, size_t n);
void *my_fast_memcpy(void *dest, const void *src, size_t n);
void *my_memmove(void *dest, const void *src, size_t num);
void *my_memset(void *s, int c, size_t n);


#endif // MYLIBC_H