#include <mylibc.h>

/// @brief      Outputs the number n to the file descriptor fd in the given base
/// @param n    The number to be output
/// @param base The base to output the number in
/// @param fd   The file descriptor to output to
void putbnbr_fd(int n, int base, int fd) {
    char *str = itoa_base(n, base);
    if (str == NULL)
        return;
    putstr_fd(str, fd);
    free(str);
}