#include <mylibc.h>

/// @brief      Check if the character is a blank character
/// @param c    The character to check
/// @return     Non-zero if the character is a blank character, 0 otherwise
int isblank(int c){
    return c == ' ' || c == '\t';
}