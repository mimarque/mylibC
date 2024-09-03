#include <mylibc.h>

/// @brief          Copies the string pointed to by src, including the null-terminator, to the buffer pointed to by dest
/// @param dest     Pointer to the destination array where the content is to be copied
/// @param src      Pointer to the source of data to be copied
/// @return         A pointer to the destination string dest
/// NOT MEMORY SAFE!!! STRINGS MUST BE NUL TERMINATED!
char *strcpy(char *dest, const char *src) {
    char *d = dest;
    const char *s = src;

    while ((*d++ = *s++));
    return dest;
}