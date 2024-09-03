#include <mylibc.h>

size_t strlcpy(char *dest, const char *src, size_t dstsize) {
    size_t srclen = strlen(src);
    if (srclen + 1 < dstsize) {
        fast_memcpy(dest, src, srclen + 1);
    } else if (dstsize != 0) {
        fast_memcpy(dest, src, dstsize - 1);
        dest[dstsize - 1] = '\0';
    }
    return srclen;
}