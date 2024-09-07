#include <mylibc.h>

/// @brief      Convert a character to uppercase only if it is a lowercase letter
/// @param c    The character to convert
/// @return     The uppercase character
int my_toupper(int c){
    if(c >= 'a' && c <= 'z'){
        return c - 32;
    }
    return c;
}