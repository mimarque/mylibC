#include <mylibc.h>

/// @brief          Appends the string pointed to by src to the end of the string pointed to by dest
/// @param dest     Pointer to the destination array, which should contain a C string,
///                 and be large enough to contain the concatenated resulting string
/// @param src      C string to be appended
/// @param n        The maximum number of characters to append
/// @return         A pointer to the resulting string dest
char *strncat(char *dest, const char *src, size_t n) {
    char *temp = dest;

    if (n > 0) {
        while (*dest)
            dest++;
        while (*src && n--){
            *dest++ = *src++;
        }
        *dest = '\0';
    }
    return dest;
}