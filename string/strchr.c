#include <mylibc.h>

/// @brief      Locates the first occurrence of c (converted to a char) in the string pointed to by s
///             NOT MEMORY SAFE!!! STRING MUST BE NUL TERMINATED!
/// @param s    Pointer to the null-terminated byte string to be analyzed
/// @param c    Character to be located
/// @return     A pointer to the located character in the string, or a null pointer if the character does not appear in the string
char *my_strchr(const char *s, int c) {
    if (s == NULL) return NULL;
    while(true) {
        if(*s == c)
            return (char *)s;
        if(*s == '\0')
            return NULL;
        s++;
    }
    //Never reached
}