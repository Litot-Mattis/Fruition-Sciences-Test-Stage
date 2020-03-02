#include "include/my.h"

int count_c(char *str, char c)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] == c)
            count += 1;
    }
    return (count);
}

int my_strlen(char const *str)
{
    int i = 0;
    
    while(str[i] != '\0') {
        i = i + 1;
    }
    return(i);
}

int count_line(char *str)
{
    int count = 0;

    for (int i = 0; str[i] != ' ' && str[i] != '\n'; i += 1)
        count += 1;
    return (count);
}

char *my_strndup(char *str, int a)
{
    char *dest = malloc(sizeof(char) * (a + 1));
    int i = 0;

    while (str[i] != ' ' && i < a) {
        dest[i] = str[i];
        i += 1;
    }
    dest[a] = '\0';
    return (dest);
}

char **str_to_word_array(char *str, char c)
{
    char **tableau = malloc(sizeof(char **) * (count_c(str, c) + 2));
    int i = 0;

    for (int j = 0; j < my_strlen(str); j += 1) {
        tableau[i] = my_strndup(str + j, count_line(str + j));
        i += 1;
        j += count_line(str + j);
    }
    tableau[i] = NULL;
    return (tableau);
}