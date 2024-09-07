#include <mylibc.h>

/// @brief          Joins two strings together with malloc
/// @param s1       The first string
/// @param s2       The second string
/// @return         A pointer to the joined string
char *my_strjoin(const char *s1, const char *s2) {
    size_t s1_len = my_strlen(s1);
    size_t s2_len = my_strlen(s2);

    char *result = my_calloc(s1_len + s2_len + 1, sizeof(char));
    if (result == NULL)
        return NULL;

    my_fast_memcpy(result, s1, s1_len);
    my_fast_memcpy(result + s1_len, s2, s2_len + 1);
    return result;
}