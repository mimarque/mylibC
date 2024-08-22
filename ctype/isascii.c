#include <mylibc.h>

/// @brief      Check if the character is an ASCII character
/// @param c    The character to check
/// @return     Non-zero if the character is an ASCII character, 0 otherwise
int isascii(int c){
    return c >= 0 && c <= 127;
}