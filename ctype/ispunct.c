#include <mylibc.h>

/// @brief      Check if the character is a punctuation character
/// @param c    The character to check
/// @return     Non-zero if the character is a punctuation character, 0 otherwise
int my_ispunct(int c){
    return my_isgraph(c) && !my_isalnum(c);
}