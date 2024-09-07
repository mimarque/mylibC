#include <mylibc.h>

/// @brief      Check if the character is a hexadecimal digit
/// @param c    The character to check
/// @return     Non-zero if the character is a hexadecimal digit, 0 otherwise
int my_isxdigit(int c){
    return my_isdigit(c) || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f');
}