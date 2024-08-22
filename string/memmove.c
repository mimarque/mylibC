#include <mylibc.h>

void *memmove(void *dest, const void *src, size_t num) {
    if ((dest == NULL || src == NULL) || (dest == src) || (num == 0))
        return dest;
    
    return fast_memcpy(dest, src, num);
}