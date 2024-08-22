#include <mylibc.h>

/// @brief      Check if the character is a digit
/// @param c    The character to check
/// @return     Non-zero if the character is a digit, 0 otherwise
int isdigit(int c){
    return c >= '0' && c <= '9';
}