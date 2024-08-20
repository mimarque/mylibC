#include <mylibc.h>

/// @brief      Check if the character is a white space character
/// @param c    The character to check
/// @return     Non-zero if the character is a white space character, 0 otherwise
int isspace(int c){
    return c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r';
}