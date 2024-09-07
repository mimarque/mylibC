#include <mylibc.h>

/// @brief          Joins two strings together with malloc
/// @param s1       The first string
/// @param s2       The second string
/// @return         A pointer to the joined string
char *strjoin(const char *s1, const char *s2) {
    size_t s1_len = strlen(s1);
    size_t s2_len = strlen(s2);

    char *result = calloc(s1_len + s2_len + 1, sizeof(char));
    if (result == NULL)
        return NULL;

    fast_memcpy(result, s1, s1_len);
    fast_memcpy(result + s1_len, s2, s2_len + 1);
    return result;
}