#include <mylibc.h>

/// @brief      Copies n bytes from memory area src to memory area dst,
/// stopping when the character c is found, or after n characters are copied,
/// whichever comes first. If copying takes place between objects that overlap, the behavior is undefined.
/// @param dst  The pointer to the destination array where the content is to be copied
/// @param src  The pointer to the source of data to be copied
/// @param c    The character to be searched for
/// @param n    The number of bytes to copy
/// @return     A pointer to the next character in dst after c, or NULL if c was not found in the first n bytes of src
void *my_memccpy(void *dst, const void *src, int c, size_t n) {
    unsigned char *d = (unsigned char *)dst;
    const unsigned char *s = (const unsigned char *)src;
    unsigned char uc = (unsigned char)c;

    if (dst == NULL || src == NULL || n == 0) return NULL;

    while (n--) {
        *d++ = *s++;
        if (*(d - 1) == uc)
            return d + 1;
    }
    return NULL;
}