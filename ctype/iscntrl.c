#include <mylibc.h>

/// @brief      Check if the character is a control character
/// @param c    The character to check
/// @return     Non-zero if the character is a control character, 0 otherwise
int my_iscntrl(int c){
    return (c >= 0 && c <= 31) || c == 127;
}