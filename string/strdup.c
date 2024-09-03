#include <mylibc.h>

/// @brief      Duplicates the string pointed to by s as a new string, allocated with malloc
/// @param s    Pointer to the null-terminated byte string to be copied
/// @return     A pointer to the newly allocated string, or a null pointer if the allocation fails
/// NOTE:       The returned string must be freed by the user
/// NOT MEMORY SAFE!!! STRING MUST BE NUL TERMINATED!
char *strdup(const char *s) {
    size_t len = strlen(s);
    char *dup = calloc(len + 1, sizeof(char));
    if (dup == NULL)
        return NULL;

    memcpy(dup, s, len);
    return dup;
}