#include <stdio.h>

int main(void) {
    // Print sizes in bytes
    printf("Size of char:      %zu bytes (%zu bits)\n", sizeof(char), sizeof(char) * 8);
    printf("Size of short:     %zu bytes (%zu bits)\n", sizeof(short), sizeof(short) * 8);
    printf("Size of int:       %zu bytes (%zu bits)\n", sizeof(int), sizeof(int) * 8);
    printf("Size of long:      %zu bytes (%zu bits)\n", sizeof(long), sizeof(long) * 8);
    printf("Size of long long: %zu bytes (%zu bits)\n", sizeof(long long), sizeof(long long) * 8);
    printf("Size of float:     %zu bytes (%zu bits)\n", sizeof(float), sizeof(float) * 8);
    printf("Size of double:    %zu bytes (%zu bits)\n", sizeof(double), sizeof(double) * 8);
    printf("Size of void*:     %zu bytes (%zu bits)\n", sizeof(void*), sizeof(void*) * 8);
    printf("Size of size_t:    %zu bytes (%zu bits)\n", sizeof(size_t), sizeof(size_t) * 8);
    printf("Size of unsigned char:  %zu bytes (%zu bits)\n", sizeof(unsigned char), sizeof(unsigned char) * 8);
    printf("Size of unsigned short: %zu bytes (%zu bits)\n", sizeof(unsigned short), sizeof(unsigned short) * 8);
    printf("Size of unsigned int:   %zu bytes (%zu bits)\n", sizeof(unsigned int), sizeof(unsigned int) * 8);
    printf("Size of unsigned long:  %zu bytes (%zu bits)\n", sizeof(unsigned long), sizeof(unsigned long) * 8);
    printf("Size of unsigned long long: %zu bytes (%zu bits)\n", sizeof(unsigned long long), sizeof(unsigned long long) * 8);

    return 0;
}