#include <mylibc.h>

/// @brief      Compares up to n characters of the C string s1 to those of the C string s2
/// @param s1   C string to be compared
/// @param s2   C string to be compared
/// @param n    Maximum number of characters to compare
/// @return     Returns an integral value indicating the relationship between the strings:
///             A zero value indicates that the characters compared in both strings form the same string.
///             A value greater than zero indicates that the first character that does not match has a greater value in str1 than in str2
///             A value less than zero indicates the opposite
int my_strncmp(const char *s1, const char *s2, size_t n) {
    while (n-- && *s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    if (n == 0)
        return 0;
    else
        return *(const unsigned char *)s1 - *(const unsigned char *)s2;
}