#include <mylibc.h>

/// @brief      Convert a character to lowercase only if it is an uppercase letter
/// @param c    The character to convert
/// @return     The lowercase character
int my_tolower(int c){
    if(c >= 'A' && c <= 'Z'){
        return c + 32;
    }
    return c;
}