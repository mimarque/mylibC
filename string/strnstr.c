#include <mylibc.h>


/// @brief              Returns a pointer to the first occurrence of the string needle in the string haystack,
///                     where not more than len characters are searched.
/// @param haystack     The string to be searched
/// @param needle       The string to search for
/// @param len          The number of characters to search
/// @return             A pointer to the found string or NULL if the string is not found
char *strnstr(const char *haystack, const char *needle, size_t len) {
    size_t i;
    size_t needle_len = strnlen(needle, len);

    if (needle_len == 0)
        return (char *)haystack;

    for(i = 0; i <= len - needle_len; i++) {
        if ((haystack[i] == needle[0]) &&
            memcmp(&haystack[i], needle, needle_len) == 0)
            return (char *)&haystack[i];
    }
    return NULL;
}