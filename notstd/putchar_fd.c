#include <mylibc.h>

/// @brief      Outputs the character c to the file descriptor fd
/// @param c    The character to be output
/// @param fd   The file descriptor to output to
void my_putchar_fd(char c, int fd) {
    write(fd, &c, 1);
}