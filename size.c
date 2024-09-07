#include <stdio.h>

int main(void) {
    unsigned int x = 0x12345678;
    unsigned char *byte = (unsigned char *)&x;
    int test = -1;
    size_t size = sizeof(int);
    size_t index;

    int is_little_endian = 0;
    int is_ones_complement = 1;
    int is_twos_complement = 1;

    if (byte[0] == 0x78) {
        printf("Little-endian\n");
        is_little_endian = 1;
    } else if (byte[0] == 0x12) {
        printf("Big-endian\n");
    } else {
        printf("Unknown endianness\n");
    }

    byte = (unsigned char *)&test;

    for (size_t i = 0; i < size; i++) {
        index = is_little_endian ? i : size - 1 - i;
        if (byte[index] != 0xFF) {
            is_ones_complement = 0;
        }
        if (byte[index] != 0xFF && (i != size - 1 || byte[index] != 0xFE)) {
            is_twos_complement = 0;
        }
    }

    if (is_twos_complement) {
        printf("Two's complement\n");
    } else if (is_ones_complement) {
        printf("One's complement\n");
    } else {
        printf("Normal binary or unknown representation\n");
    }

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