#include <mylibc.h>

/// @brief          Copies n bytes from memory area src to memory area dest
/// Copies the values of num bytes from the location pointed by source to the memory block pointed by destination. 
/// Copying takes place as if an intermediate buffer were used, allowing the destination and source to overlap.
/// The underlying type of the objects pointed by both the source and destination pointers are irrelevant for this function;
/// The result is a binary copy of the data. The function does not check for any terminating null character in source - 
/// it always copies exactly num bytes. To avoid overflows, the size of the arrays pointed by both the destination and source parameters,
/// shall be at least num bytes.
/// @param dest     Pointer to the destination array where the content is to be copied
/// @param src      Pointer to the source of data to be copied
/// @param num      Number of bytes to copy
/// @return         A pointer to the destination
void *my_memmove(void *dest, const void *src, size_t num) {
    if ((dest == NULL || src == NULL) || (dest == src) || (num == 0))
        return dest;
    
    return my_fast_memcpy(dest, src, num); // this is a memory safe version of memcpy
}