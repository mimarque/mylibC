#include <mylibc.h>

/// @brief      Returns the length of the given string
/// @param s    The string to be measured
/// @return     The length of the string
size_t strlen(const char *s)
{
    size_t len = 0;
    while (*s++)
        len++;
    return len;
}