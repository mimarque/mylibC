#include <mylibc.h>

/// @brief      Outputs the integer n to the file descriptor fd
/// @param n    The integer to be output
/// @param fd   The file descriptor to output to
void my_putnbr_fd(int n, int fd) {
    char *str = my_itoa(n);
    if (str == NULL)
        return;
    my_putstr_fd(str, fd);
    free(str);
}