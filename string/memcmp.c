#include <mylibc.h>

/// @brief          Compares the first num bytes of the block of memory pointed by ptr1 to the first num bytes pointed by ptr2
/// @param ptr1     Pointer to the first block of memory
/// @param ptr2     Pointer to the second block of memory
/// @param num      Number of bytes to compare
/// @return         An int equal to zero if the first num bytes of the block of memory pointed by ptr1 are equal to the first num bytes pointed by ptr2, a value greater or less than zero otherwise
int memcmp(const void *ptr1, const void *ptr2, size_t num) {
    const unsigned char *p1 = ptr1, *p2 = ptr2;
    while(num--) {
        if(*p1 != *p2)
            return *p1 - *p2;
        p1++;
        p2++;
    }
    return 0;
}