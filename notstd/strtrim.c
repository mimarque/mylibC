#include <mylibc.h>

char *strtrim(const char *s, const char *set) {
    size_t len = strlen(s);
    size_t start = 0;
    size_t end = len;

    if (s == NULL || set == NULL)
        return NULL;

    while (start < len && strchr(set, s[start]) != NULL)
        start++;
    while (end > start && strchr(set, s[end - 1]) != NULL)
        end--;

    return substr(s, start, end - start);
}