#include <mylibc.h>

char *my_strtrim(const char *s, const char *set) {
    size_t len = my_strlen(s);
    size_t start = 0;
    size_t end = len;

    if (s == NULL || set == NULL)
        return NULL;

    while (start < len && my_strchr(set, s[start]) != NULL)
        start++;
    while (end > start && my_strchr(set, s[end - 1]) != NULL)
        end--;

    return my_substr(s, start, end - start);
}