#include <mylibc.h>

/// @brief      Outputs the integer n to the file descriptor fd
/// @param n    The integer to be output
/// @param fd   The file descriptor to output to
void putnbr_fd(int n, int fd) {
    char *str = itoa(n);
    if (str == NULL)
        return;
    putstr_fd(str, fd);
    free(str);
}