#include <mylibc.h>

int my_count_digits(int value) {
    int count = 0;
    if (value < 0) {
        count++;
        value = -value;
    }
    while (value) {
        count++;
        value /= 10;
    }
    return count;
}

int my_count_digits_in_base(int value, int base) {
    int count = 0;
    if (value < 0) {
        count++;
        value = -value;
    }
    while (value) {
        count++;
        value /= base;
    }
    return count;
}

//needs #include <math.h>
/* int my_count_digits_in_base_log(int value, int base) {
    int count = 0;
    if (value < 0) {
        count++;
        value = -value;
    }
    // use logarithm to calculate the number of digits
    count += (int) (log(value) / log(base)) + 1;
    return count;
}*/

int my_hexvalue(char c) {
    if (c >= '0' && c <= '9')
        return c - '0';
    if (c >= 'A' && c <= 'F')
        return c - 'A' + 10;
    if (c >= 'a' && c <= 'f')
        return c - 'a' + 10;
    return 0;
}