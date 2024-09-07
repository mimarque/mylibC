#include <mylibc.h>

static int my_word_count(const char *str, char delim){
    size_t len = my_strlen(str);
    size_t word_cnt = 0;
    bool in_word = false;
    //count how many "words" are between the delimiters
    for (size_t i = 0; i < len; i++){
        if (str[i] == delim) {
            in_word = false;
        } else if (str[i] != delim && !in_word) {
            in_word = true;
            word_cnt++;
        }
    }
    return word_cnt;
}

static size_t my_word_length(const char *str, char delim){
    size_t len = 0;
    while (str[len] != delim && str[len] != '\0')
        len++;
    return len;
}

void my_free_split(char **arr){
    for (size_t i = 0; arr[i] != NULL; i++)
        free(arr[i]);
    free(arr);
}

char **split(const char *str, char delim) {
    size_t word_cnt = my_word_count(str, delim);
    char **arr = my_calloc(word_cnt + 1, sizeof(char *));
    if (arr == NULL)
        return NULL;
    
    //allocate memory for each word and add it to arr
    size_t i = 0;
    size_t len = 0;
    while (*str != '\0') {
        if (*str == delim) {
            str++;
        } else {
            len = my_word_length(str, delim);
            arr[i] = my_substr(str, 0, len);
            if (arr[i] == NULL) {
                my_free_split(arr);
                return NULL;
            }
            str += len;
            i++;
        }
    }
}

