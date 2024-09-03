#include <mylibc.h>

/// @brief          Converts an integer value to a null-terminated string using the specified base and stores the result in the array given by buf
/// @param value    Value to be converted to a string
/// @return         A pointer to the resulting null-terminated string
/// NOTE: The returned string is allocated with malloc and must be freed by the user
char *itoa(int value) {
    int is_negative = value < 0;
    int num_digits = count_digits(value);

    char *buf = malloc(num_digits + is_negative + 1);
    if (buf == NULL)
        return NULL;

    char *pointer = buf + num_digits + is_negative; // points to the end
    *pointer = '\0';

    if (!is_negative) {
        do {
            *--pointer = value % 10 + '0';
            value /= 10;
        } while (value);
    } else {
        do {
            *--pointer = -(value % 10) + '0';
            value /= 10;
        } while (value);
        *--pointer = '-';
    }
    return buf;
}

char *uitoa(unsigned int value) {
    int num_digits = count_digits(value);

    char *buf = malloc(num_digits + 1);
    if (buf == NULL)
        return NULL;

    char *pointer = buf + num_digits; // points to the end
    *pointer = '\0';

    do {
        *--pointer = value % 10 + '0';
        value /= 10;
    } while (value);

    return buf;
}

char *itoa_base(int value, int base) {
    int is_negative = value < 0;
    int num_digits = count_digits_in_base(value, base);
    int digit;

    char *buf = malloc(num_digits + is_negative + 1);
    if (buf == NULL)
        return NULL;

    char *pointer = buf + num_digits + is_negative; // points to the end
    *pointer = '\0';

    if (!is_negative) {
        do {
            digit = value % base;
            if (digit < 10)
                *--pointer = digit + '0';
            else
                *--pointer = digit - 10 + 'A';
            value /= base;
        } while (value);
    } else {
        do {
            digit = value % base;
            if (digit < 10)
                *--pointer = digit + '0';
            else
                *--pointer = digit - 10 + 'A';
            value /= base;
        } while (value);
        *--pointer = '-';
    }
    return buf;
}

char *uitoa_base(unsigned int value, int base) {
    int num_digits = count_digits_in_base(value, base);
    int digit;

    char *buf = malloc(num_digits + 1);
    if (buf == NULL)
        return NULL;

    char *pointer = buf + num_digits; // points to the end
    *pointer = '\0';

    do {
        digit = value % base;
        if (digit < 10)
            *--pointer = digit + '0';
        else
            *--pointer = digit - 10 + 'A';
        value /= base;
    } while (value);

    return buf;
}