#include <mylibc.h>

/// @brief          Copies up to n characters from the string pointed to by src to dest
/// @param dest     The destination string
/// @param src      The source string
/// @param n        The maximum number of characters to copy
/// @return         The destination string with the copied characters
/// @note           If the length of src is less than n, the remaining characters in dest will be filled with NUL
///                 If the length of src is greater than or equal to n, the destination string will not be NUL-terminated   
char *strncpy(char *dest, const char *src, size_t n) {
    size_t i;

    for (i = 0; i < n && src[i] != '\0'; i++)
        dest[i] = src[i];
    while (i < n)
        dest[i++] = '\0';
    return dest;
}