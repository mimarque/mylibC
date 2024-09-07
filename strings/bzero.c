#include <mylibc.h>

/// @brief      Sets the first n bytes of the block of memory pointed by s to zero
/// @param s    Pointer to the block of memory to fill
/// @param n    Number of bytes to be set to zero
void my_bzero(void *s, size_t n)
{
    my_memset(s, 0, n);
}