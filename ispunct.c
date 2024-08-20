#include <mylibc.h>

/// @brief      Check if the character is a punctuation character
/// @param c    The character to check
/// @return     Non-zero if the character is a punctuation character, 0 otherwise
int ispunct(int c){
    return isgraph(c) && !isalnum(c);
}