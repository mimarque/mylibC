#include <mylibc.h>

/// @brief      Outputs the string s to the file descriptor fd followed by a newline
/// @param s    The string to be output
/// @param fd   The file descriptor to output to
void my_putendl_fd(const char *s, int fd) {
    if (s == NULL)
        return;
    write(fd, s, strlen(s));
    write(fd, "\n", 1);
}