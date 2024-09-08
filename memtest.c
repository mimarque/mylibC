#include <stdio.h>
#include <time.h>

typedef long word;

/// @brief      Returns the length of the given string
/// @param s    The string to be measured
/// @return     The length of the string
size_t my_strlen(const char *s)
{
    size_t len = 0;
    while (*s++)
        len++;
    return len;
}

size_t my_strnlen(const char *s, size_t maxlen)
{
    size_t len = 0;
    while (len < maxlen && *s++)
        len++;
    return len;
}

void *my_fast_memcpy(void *dest, const void *src, size_t n){
    char *d = (char *)dest;
    const char *s = (const char *)src;
    size_t t;
    uintptr_t d_ptr = (uintptr_t)d;
    uintptr_t s_ptr = (uintptr_t)s;
    size_t wsize = sizeof(word);
    uintptr_t wmask = wsize - 1;

    if ((dest == NULL || src == NULL) || (dest == src || n == 0)) return NULL;
    
    if (d_ptr < s_ptr) { // No overlap
        t = s_ptr;

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
        // same as ((s_address % wordsize) != 0 || (d_address % wordsize) != 0)
        if ((t | d_ptr) & wmask) {
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
            // same as ((t_address % wsize) != (d_address % wsize)) || n < wsize
            if ((t ^ d_ptr) & wmask || n < wsize) {
                t = n;
            } else { // if it is false, src and dest can be aligned easily or are aligned, we can copy the data in word size chunks
                t = wsize - (t & wmask); // determine how many bytes to copy to align the source
            }
            n -= t; //  this is here to prevent the next if's from being executed
                    //  meaning the data is all copied in this do-while loop below 
                    //  subtract the number of bytes to be copied from the total number of bytes to copy
            do {
                *d++ = *s++;
            } while (--t); // --t > 0
        }
        t = n / wsize; // determine how many words to copy
        if (t) {
            do {
                *(word *)d = *(const word *)s; // cast the source and destination to word and copy the data
                d += wsize; // increment the destination by the word size note that the destination is a char pointer
                s += wsize; // increment the source by the word size note that the source is a char pointer
            } while (--t); // --t > 0
        }
        t = n & wmask; // determine how many bytes are left to copy same as t = n % wsize
        if (t) {
            do {
                *d++ = *s++; // copy the remaining bytes
            } while (--t); // --t > 0
        }
    } else {
        // basically the same as the above block but we copy from higher addresses to lower addresses
        s += n;
        d += n;
        t = s_ptr;
        if ((t | d_ptr) & wmask) {
            if ((t ^ d_ptr) & wmask || n <= wsize) {
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
        if (t) {
            do {
                d -= wsize;
                s -= wsize;
                *(word *)d = *(const word *)s;
            } while (--t);
        }
        t = n & wmask;
        if (t) {
            do {
                *--d = *--s;
            } while (--t);
        }
    }
    return dest;
}

size_t strlcat(char *dest, const char *src, size_t dstsize) {
    size_t dlen = my_strnlen(dest, dstsize); //if dest is bigger than dstsize, dlen will be capped at dstsize
    size_t slen = my_strlen(src);

    if (dlen == dstsize)        // == instead of >= because its already capped;
        return dstsize + slen;  // if dest is already full, return the total length of the string we tried to create
    if (slen < dstsize - dlen) {
        my_fast_memcpy(dest + dlen, src, slen + 1);
    } else {
        my_fast_memcpy(dest + dlen, src, dstsize - dlen - 1);
        dest[dstsize - 1] = '\0';
    }
    return dlen + slen;
}

/// test the strstr function  
void test_strlcat() {
    char dest[13] = "batata";
    char src[7] = " frita";
    size_t dstsize = 13;
    size_t result = strlcat(dest, src, dstsize);
    printf("Result: %s\n len: %zu", dest, result);
}

/* void repeat_strstr(int ver) {
    for(int i = 0; i < 100000; i++) {
        test_strstr(ver);
    }
} */

int main(void){
    clock_t start, end; //clock_t is a long int
    double cpu_time_used;
    double average = 0;

    /* //try different versions of strstr
    for (int j = 0; j < 3; j++) {
        //make average of 100 runs
        for (int i = 0; i < 100; i++) {
            start = clock();
            repeat_strstr(j);
            end = clock();

            cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC; //CLOCKS_PER_SEC is 1000
            average += cpu_time_used;
        }
        printf("Average %d time taken: %f\n", j, average/100);
    } */
    test_strlcat();

    return 0;
}