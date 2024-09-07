#include <mylibc.h>

/// @brief      Applies a function to each character of a string and retuns a new allocated string
/// @param s    The string to apply the function to
/// @param f    The function to apply to each character
/// @return     A new allocated string
char *strmapi(const char *s, char (*f)(unsigned int, char)) {
    size_t len = strlen(s);
    char *result = calloc(len + 1, sizeof(char));
    if (result == NULL)
        return NULL;

    for (size_t i = 0; i < len; i++)
        result[i] = f(i, s[i]);
    return result;
}