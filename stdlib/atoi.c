#include <mylibc.h>

long atol(const char *str) {
    long value = 0;
    int sign = 1;
    
    while (isspace(*str))
        str++;
    if (*str == '-' || *str == '+')
        if (*str++ == '-')
            sign = -1;
    while (*str && isdigit(*str)) {
        //if it could overflow clip to bonds of long
        if (value >= (LONG_MAX / 10) || value >= (-LONG_MIN / 10)){
            int digit = *str - '0';
            if (sign == 1 && (value > (LONG_MAX - digit) / 10)) {
                return LONG_MAX;
            }
            if (sign == -1 && (value > (-(LONG_MIN + digit)) / 10)) {
                return LONG_MIN;
            }
        }            
        value = value * 10 + (*str - '0');
        str++;
    }
    return (value * sign);
}

int atoi(const char *str) {
    long val = atol(str);
    //clip to bonds of int
    if (val > INT_MAX){
        return INT_MAX;
    } else if (val < INT_MIN) {
        return INT_MIN;
    }
    return (int) val;
}

unsigned long atoul(const char *str) {
    unsigned long value = 0;
    
    while (isspace(*str))
        str++;
    while (*str && isdigit(*str)) {
        //clip to bonds of long
        if (value >= ULONG_MAX / 10){
            if (value > (ULONG_MAX - (*str - '0')) / 10)
                return ULONG_MAX;
        }
        value = value * 10 + (*str - '0');
        str++;
    }
    return value;
}

unsigned int atoui(const char *str) {
    unsigned long val = atoul(str);
    //clip to bonds of int
    if (val > UINT_MAX)
       val = UINT_MAX;
    return (unsigned int) val;
}