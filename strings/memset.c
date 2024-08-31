#include <mylibc.h>

/// @brief          Fills the first num bytes of the memory area pointed to by ptr with the constant byte value
/// @param ptr      Pointer to the memory area to be filled
/// @param value    The byte value to be set
/// @param num      Number of bytes to be set to the value
/// @return         A pointer to the memory area ptr
void* memset( void *ptr, int value, size_t num ){
    unsigned char *p = (unsigned char *) ptr;
    while(num-- > 0){
        *p++ = (unsigned char)value;
    }
}