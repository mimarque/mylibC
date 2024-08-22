#include <mylibc.h>

/// @brief          Scans the initial n bytes of s for the first instance of c
/// @param ptr      Pointer to the memory area to be scanned
/// @param value    The byte value to be searched
/// @param num      Number of bytes to be scanned
/// @return         A pointer to the matching byte or NULL if the character does not occur in the given memory area
const void *memchr(const void *ptr, int value, size_t num) {
    const unsigned char *p = (const unsigned char *) ptr;
    unsigned char uc = (unsigned char) value;

    if (ptr == NULL || num == 0) return NULL;

    while(num--) {
        if(*p == uc)
            return p;
        p++;
    }
    return NULL;
}