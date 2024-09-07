#include <mylibc.h>

/// @brief      Compares two null-terminated byte strings
/// @param s1   The first string to be compared
/// @param s2   The second string to be compared
/// @return     Returns an int value indicating the relationship between the strings:
///             A zero value indicates that the strings are equal.
///             A value different than zero indicates that the strings are different
/// @note       NOT MEMORY SAFE!!! STRINGS MUST BE NUL TERMINATED!
///             This function does not check for null pointers
int my_strcmp(const char *s1, const char *s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(const unsigned char *)s1 - *(const unsigned char *)s2;
}