#include <mylibc.h>

/// @brief          Copies up to dstsize - 1 characters from the string src to dest, null-terminating the result if dstsize is not 0
/// @param dest     The destination string
/// @param src      The source string
/// @param dstsize  The size of the destination buffer
/// @return         The total length of the string IT TRIED to create (not the length of the string it actually created)
///                 If the return value is >= dstsize, the output string was truncated
size_t my_strlcpy(char *dest, const char *src, size_t dstsize) {
    size_t srclen = my_strlen(src);
    if (srclen + 1 < dstsize) {
        my_fast_memcpy(dest, src, srclen + 1);
    } else if (dstsize != 0) {
        my_fast_memcpy(dest, src, dstsize - 1);
        dest[dstsize - 1] = '\0';
    }
    return srclen;
}