#include <mylibc.h>

/// @brief      Check if the character is a hexadecimal digit
/// @param c    The character to check
/// @return     Non-zero if the character is a hexadecimal digit, 0 otherwise
int isxdigit(int c){
    return isdigit(c) || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f');
}