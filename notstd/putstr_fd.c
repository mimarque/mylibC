#include <mylibc.h>

/// @brief      Outputs the string s to the file descriptor fd
/// @param s    The string to be output
/// @param fd   The file descriptor to output to
void my_putstr_fd(const char *s, int fd) {
    if (s == NULL)
        return;
    write(fd, s, strlen(s));
}