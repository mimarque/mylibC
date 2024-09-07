#include <mylibc.h>

/// @brief          Returns a substring of the given string allocated with malloc
/// @param str      The string to extract the substring from
/// @param start    The starting index of the substring
/// @param len      The length of the substring
/// @return         A pointer to the substring
char *substr(const char *str, size_t start, size_t len) {
    char *result = calloc(len + 1, sizeof(char));
    if (result == NULL)
        return NULL;
    fast_memcpy(result, str + start, len);
    return result;
}