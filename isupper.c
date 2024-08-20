#include <mylibc.h>

/// @brief      Check if the character is an upper case letter
/// @param c    The character to check
/// @return     Non-zero if the character is an upper case letter, 0 otherwise
int isupper(int c){
    return c >= 'A' && c <= 'Z';
}