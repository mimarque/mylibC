#include <mylibc.h>

/// @brief          Appends a copy of the string pointed to by src to the end of the string pointed to by dest
/// @param dest     Pointer to the destination array, which should contain a C string, and be large enough to contain the concatenated resulting string
/// @param src      C string to be appended
/// @return         A pointer to the resulting string dest
/// @note           NOT SAFE! dest must be large enough to contain the concatenated resulting string
char *my_strcat(char *dest, const char *src) {
    size_t dest_len = my_strlen(dest);
    size_t src_len = my_strlen(src);

    my_fast_memcpy(dest + dest_len, src, src_len + 1);
    return dest;
}