#include <mylibc.h>

/// @brief      Compares up to n characters of the C string s1 to those of the C string s2
/// @param s1   C string to be compared
/// @param s2   C string to be compared
/// @param n    Maximum number of characters to compare
/// @return     Returns an integral value indicating the relationship between the strings:
///             A zero value indicates that the characters compared in both strings form the same string.
///             A value greater than zero indicates that the first character that does not match has a greater value in str1 than in str2
///             A value less than zero indicates the opposite or error
int strncmp(const char *s1, const char *s2, size_t n) {
    if (s1 == NULL || s2 == NULL || n == 0) return -1;
    
    while (n--) {
        if (*s1 != *s2) 
            return *s1 - *s2;
        if (*s1 == '\0') 
            return 0;
        s1++;
        s2++;
    }
    //in case str in not null terminated
    return -1;
}