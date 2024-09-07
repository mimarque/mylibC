#include <mylibc.h>

/// @brief      Check if the character is a printable character
/// @param c    The character to check
/// @return     Non-zero if the character is a printable character, 0 otherwise
int my_isprint(int c){
    return c >= ' ' && c < 127;
}