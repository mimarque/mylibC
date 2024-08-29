#include <mylibc.h>

/// @brief          Locates the first occurrence of the null-terminated string find in the null-terminated string s
///                 NOT MEMORY SAFE!!! STRINGS MUST BE NUL TERMINATED!
/// @param s        Pointer to the null-terminated byte string to be analyzed
/// @param find     Pointer to the null-terminated byte string to be searched for
/// @return         A pointer to the located substring in the string, or a null pointer if the substring does not appear in the string
char *strstr(const char *s, const char *find) {
    size_t l1 = strlen(s);
    size_t l2 = strlen(find);

    if ((l2 > l1) || (*s == 0) || (*find == 0)) return NULL;

    while (l1 >= l2) {
        if (*s == *find)
            if (!memcmp(s, find, l2))
                return (char *) s;
        s++;
        l1--;
    }
    return NULL;
}

char *fast_strstr(const char *s, const char *find) {
    char sc, fc;
    size_t len;

    fc = *find++;
    if (fc != 0) {
        len = strlen(find);
        do{
            do {
                sc = *s;
                if (sc == 0)
                    return NULL;
                s++;
            } while (sc != fc);
        } while (!memcmp(s, find, len));
        s--;
    }
    return (char *)s;
}