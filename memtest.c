#include <stdio.h>
#include <time.h>

typedef long word;

/// @brief          Copies n bytes from memory area src to memory area dest
/// @param dest     Pointer to the destination array where the content is to be copied
/// @param src      Pointer to the source of data to be copied
/// @param n        Number of bytes to copy
void big_memcpy(void *dest, const void *src, size_t n){
    char *d = (char *)dest;
    const char *s = (const char *)src;
    size_t t;
    unsigned long wsize = sizeof(word);
    unsigned long wmask = (wsize - 1);

    if ((dest == NULL || src == NULL) || (dest == src || n == 0)) return;
    
    if ((unsigned long)d < (unsigned long)s){ // Copy from lower addresses to higher addresses doing this to avoid overwriting data
        t = (unsigned long)s;

        // we want to copy the data in word size chunks so it's faster
        // however, we need to check if the source and destination are aligned to the word size
        // if they are not, we need to copy the data byte by byte
        // in reality this only works if the adresses are minimally aligned with each other
        //
        // t:       0001 0000 0000 0011 (0x1003)
        // d:     | 0010 0000 0000 0101 (0x2005)
        // ---------------------------------------
        //          0011 0000 0000 0111 (0x3007)
        // wmask: & 0000 0000 0000 0111 (0x0007) assuming word size is 8 bytes
        // ---------------------------------------
        //          0000 0000 0000 0111 (0x0007)
        //
        // If the result is not zero, then the source and destination are not aligned to the word size
        // this works because the alignment works out to (address mod word size) = 0
        if ((t | (unsigned long)d) & wmask){
            // the XOR will return 0 if the source and destination bits are the same
            // if the soruce and destination are missaligned, ((t ^ d) & wmask) will return a non-zero value
            // XOR'ing the source and destination will give us the difference between the two addresses
            //
            // t:       0001 0000 0000 0011
            // d:     ^ 0010 0000 0000 0110
            // ----------------------------
            //          0011 0000 0000 0101
            // wmask: & 0000 0000 0000 0111
            // ----------------------------
            //          0000 0000 0000 0101 the addresses are not aligned to the word boundary
            //
            // n is length of the data to be copied if the length is less than the word size we can only copy byte by byte
            // if this condition is true, we can only copy byte by byte
            if ((t ^ (unsigned long)d) & wmask || n < wsize){
                t = n;
            } else { // if it is false, src and dest can be aligned easily or are aligned, we can copy the data in word size chunks
                t = wsize - (t & wmask); // determine how many bytes to copy to align the source
            }
            n -= t; // subtract the number of bytes to be copied from the total number of bytes to copy
            do {
                *d++ = *s++;
            } while (--t); // --t > 0
        }
        t = n / wsize; // determine how many words to copy
        if (t){
            do {
                *(word *)d = *(word *)s; // cast the source and destination to word and copy the data
                d += wsize; // increment the destination by the word size note that the destination is a char pointer
                s += wsize; // increment the source by the word size note that the source is a char pointer
            } while (--t); // --t > 0
        }
        t = n & wmask; // determine how many bytes are left to copy same as t = n % wsize
        if (t){
            do {
                *d++ = *s++; // copy the remaining bytes
            } while (--t); // --t > 0
        }
    } else {
        // basically the same as the above block but we copy from higher addresses to lower addresses
        s += n;
        d += n;
        t = (unsigned long)s;
        if ((t | (unsigned long)d) & wmask){
            if ((t ^ (unsigned long)d) & wmask || n <= wsize){
                t = n;
            } else {
                t &= wmask;
            }
            n -= t;
            do {
                *--d = *--s;
            } while (--t);
        }
        t = n / wsize;
        if (t){
            do {
                d -= wsize;
                s -= wsize;
                *(word *)d = *(word *)s;
            } while (--t);
        }
        t = n & wmask;
        if (t){
            do {
                *--d = *--s;
            } while (--t);
        }
    }
}

/// @brief          Copies n bytes from memory area src to memory area dest
/// @param dest     Pointer to the destination array where the content is to be copied
/// @param src      Pointer to the source of data to be copied
/// @param n        Number of bytes to copy
void *memcpy(void *dest, const void *src, size_t n){
    char *d = (char *)dest;
    const char *s = (const char *)src;

    if (dest == NULL || src == NULL || dest == src || n == 0) return dest;
    if ((unsigned long)dest < (unsigned long)src){
        do{
            *d++ = *s++;
        } while (--n);
    } else {
        s += n;
        d += n;
        do {
            *--d = *--s;
        } while (--n);
    }
    return dest;
}

//create memcmp function
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

//test memcpy in several ways
//test higer and lower addresses
//test long strings to test the speed of the function
void test_memcpy(void) {
    const char comp[64] = "This is a test string to test the speed of the memcpy function.";
    char dest[64];
    char dest2[64];
    char dest3[64];
    char src[64] = "This is a test string to test the speed of the memcpy function.";
    char dest4[64];
    char dest5[64];
    char dest6[64];

    //print addresses
    printf("Address src: %p - %p\n", src, src + 64);
    printf("Address dest: %p - %p\n", dest, dest + 64);
    printf("Address dest2: %p - %p\n", dest2, dest2 + 64);
    printf("Address dest3: %p - %p\n", dest3, dest3 + 64);
    printf("Address dest4: %p - %p\n", dest4, dest4 + 64);
    printf("Address dest5: %p - %p\n", dest5, dest5 + 64);
    printf("Address dest6: %p - %p\n", dest6, dest6 + 64);

    big_memcpy(dest, src, 64);
    if(memcmp(dest, comp, 64) != 0)
        printf("Test 1: Failed\nAddress src: %p - %p\nAddress dest: %p - %p", src, src + 64, dest, dest + 64);
    big_memcpy(dest2, src, 64);
    if(memcmp(dest2, comp, 64) != 0)
        printf("Test 2: Failed\nAddress src: %p - %p\nAddress dest: %p - %p", src, src + 64, dest2, dest2 + 64);
    big_memcpy(dest3, src, 64);
    if(memcmp(dest3, comp, 64) != 0)
        printf("Test 3: Failed\nAddress src: %p - %p\nAddress dest: %p - %p", src, src + 64, dest3, dest3 + 64);
    big_memcpy(dest4, src, 64);
    if(memcmp(dest4, comp, 64) != 0)
        printf("Test 4: Failed\nAddress src: %p - %p\nAddress dest: %p - %p", src, src + 64, dest4, dest4 + 64);
    big_memcpy(dest5, src, 64);
    if(memcmp(dest5, comp, 64) != 0)
        printf("Test 5: Failed\nAddress src: %p - %p\nAddress dest: %p - %p", src, src + 64, dest5, dest5 + 64);
    big_memcpy(dest6, src, 64);
    if(memcmp(dest6, comp, 64) != 0)
        printf("Test 6: Failed\nAddress src: %p - %p\nAddress dest: %p - %p", src, src + 64, dest6, dest6 + 64);
}

void repeat_memcpy(void) {
    for(int i = 0; i < 10000; i++) {
        test_memcpy();
    }
}

int main(void){
    clock_t start, end; //clock_t is a long int
    double cpu_time_used;

    start = clock();
    //repeat_memcpy();
    test_memcpy();
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC; //CLOCKS_PER_SEC is 1000
    printf("Time taken: %f\n", cpu_time_used);

    return 0;
}