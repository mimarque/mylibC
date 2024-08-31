#include <stdio.h>
#include <time.h>



/// @brief      Returns the length of the given string
/// @param s    The string to be measured
/// @return     The length of the string
size_t strlen(const char *s)
{
    size_t len = 0;
    while (*s++)
        len++;
    return len;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num) {
    const unsigned char *p1 = ptr1;
    const unsigned char *p2 = ptr2;
    
    while(num--) {
        if(*p1 != *p2)
            return *p1 - *p2;
        p1++;
        p2++;
    }
    return 0;
}

int strncmp(const char *s1, const char *s2, size_t n) {
    if (s1 == NULL || s2 == NULL || n == 0) return -1;
    
    while (n--) {
        if (*s1 != *s2) 
            return *s1 - *s2;
        if (*s1 == '\0') 
            return 0;
        s1++;
        s2++;
    }
    //in case str in not null terminated
    return -1;
}

/// @brief          Locates the first occurrence of the null-terminated string find in the null-terminated string s
///                 NOTE: if find is an empty string, the function returns s
///                 NOT MEMORY SAFE!!! STRINGS MUST BE NUL TERMINATED!
/// @param s        Pointer to the null-terminated byte string to be analyzed
/// @param find     Pointer to the null-terminated byte string to be searched for
/// @return         A pointer to the located substring in the string, or a null pointer if the substring does not appear in the string
char *strstr(const char *s, const char *find) {
    size_t l1 = strlen(s);
    size_t l2 = strlen(find);

    if (l2 == 0) return NULL;

    while (l1 >= l2) {
        if (*s == *find)
            if (!memcmp(s, find, l2))
                return (char *) s;
        s++;
        l1--;
    }
    return NULL;
}

char *fast_strstr(const char *s, const char *find) {
    char fc;
    size_t len;

    fc = *find++;
    if (fc != 0) {
        len = strlen(find);
        do{
            do {
                if (*s == 0)
                    return NULL;
            } while (*s++ != fc);
        } while (memcmp(s, find, len) != 0);
        s--;
    }
    return (char *)s;
}

char *toofast_strstr(const char *s, const char *find) {
    char c, sc;
    size_t len;

    if ((c = *find++) != 0) {
        len = strlen(find);
        do {
            do {
                if ((sc = *s++) == 0)
                    return NULL;
            } while (sc != c);
        } while (strncmp(s, find, len) != 0);
        s--;
    }
    return (char *)s;
}

/// test the strstr function  
void test_strstr(int ver) {
    const char *s = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. "
                    "Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. "
                    "Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. "
                    "Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. "
                    "Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";
    const char *find = "voluptate";
    if (ver == 0) {
        char *result = strstr(s, find);
    } else if (ver == 1) {
        char *result = fast_strstr(s, find);
    } else if (ver == 2) {
        char *result = toofast_strstr(s, find);
    }
    //printf("Result: %s\n", result);
}

void repeat_strstr(int ver) {
    for(int i = 0; i < 100000; i++) {
        test_strstr(ver);
    }
}

int main(void){
    clock_t start, end; //clock_t is a long int
    double cpu_time_used;
    double average = 0;

    //try different versions of strstr
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
    }

    return 0;
}