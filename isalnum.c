#include <mylibc.h>

/// @brief  Check if the character is an alphanumeric character
/// @param c    The character to check
/// @return     Non-zero if the character is an alphanumeric character, 0 otherwise
int isalnum(int c){
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
}