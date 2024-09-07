#include <mylibc.h>

/// @brief          Allocates memory for an array of num objects of size and initializes all bytes in the allocated storage to zero.
/// @param num      number of Objects
/// @param size     size of each object
/// @return         A pointer to the memory block allocated by the function
void *my_calloc(size_t num, size_t size) {
    if (num == 0 || size == 0) return NULL;
    void *ptr = malloc(num * size);
    if (ptr == NULL)
        return NULL;
    return my_memset(ptr, 0, num * size); //using bzero just uses one more function call
}