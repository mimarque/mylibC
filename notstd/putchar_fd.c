#include <mylibc.h>

/// @brief      Outputs the character c to the file descriptor fd
/// @param c    The character to be output
/// @param fd   The file descriptor to output to
void putchar_fd(char c, int fd) {
    if (c == NULL)
        return;
    write(fd, &c, 1);
}