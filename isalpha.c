#include <mylibc.h>

/// @brief Check if the character is an alphabetic character
/// @param c    The character to check
/// @return     Non-zero if the character is an alphabetic character, 0 otherwise
int isalpha(int c){
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}