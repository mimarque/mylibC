#include <mylibc.h>

/// @brief      Check if the character is a lower case letter
/// @param c    The character to check
/// @return     Non-zero if the character is a lower case letter, 0 otherwise
int islower(int c){
    return c >= 'a' && c <= 'z';
}