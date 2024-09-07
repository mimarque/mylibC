#include <mylibc.h>

/// @brief      Duplicates the string pointed to by s, which must be null-terminated
/// @param s    The string to be duplicated
/// @param n    The maximum number of characters to duplicate (excluding the NUL)
/// @return     A pointer to the newly allocated string, or a null pointer if the function failed
char *strndup(const char *s, size_t n) {
    size_t len = strnlen(s, n);
    char *new = calloc(len + 1, sizeof(char));
    if (new == NULL)
        return NULL;

    fast_memcpy(new, s, len);
    new[len] = '\0';
    return new;
}