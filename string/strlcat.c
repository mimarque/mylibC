#include <mylibc.h>

size_t my_strlcat(char *dest, const char *src, size_t dstsize) {
    size_t dlen = my_strnlen(dest, dstsize); //if dest is bigger than dstsize, dlen will be capped at dstsize
    size_t slen = my_strlen(src);

    if (dlen == dstsize)        // == instead of >= because its already capped;
        return dstsize + slen;  // if dest is already full, return the total length of the string we tried to create
    if (slen < dstsize - dlen) {
        my_fast_memcpy(dest + dlen, src, slen + 1);
    } else {
        my_fast_memcpy(dest + dlen, src, dstsize - dlen - 1);
        dest[dstsize - 1] = '\0';
    }
    return dlen + slen;
}