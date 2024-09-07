#include <mylibc.h>

/// @brief      Returns the length of the given string
/// @param s    The string to be measured
/// @return     The length of the string
size_t my_strlen(const char *s)
{
    size_t len = 0;
    while (*s++)
        len++;
    return len;
}

/// @brief          returns the length of the given string excluding the NUL, but at most maxlen
/// @param s        The string to be measured
/// @param maxlen   The maximum length to be measured
/// @return         The length of the string
size_t my_strnlen(const char *s, size_t maxlen)
{
    size_t len = 0;
    while (len < maxlen && *s++)
        len++;
    return len;
}