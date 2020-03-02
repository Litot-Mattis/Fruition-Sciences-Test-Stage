#include "include/my.h"

int my_getnbr(char *str)
{
    int minus_count = 0;
    int i = 0;
    int nb = 0;

    for (; str[i] == '-' || str[i] == '+'; i += 1) {
        if (str[i] == '-')
            minus_count += 1;
    }
    for (; str[i] != '\0'; i += 1) {
        if (str[i] < '0' || str[i] > '9')
        break;
        nb = nb * 10 + (str[i] - 48);
        }
        if (minus_count % 2 == 1)
            nb = nb * (-1);
        return (nb);
}

int read_info_file(char *av, coord_t *coord)
{
    int line = 0;
    char array[3][20];
    char *cmd;
    FILE *fp = fopen(av, "r");
   
    if(!fp) {
       printf("Error: unable to open the file.\n"); 
       return (84);
    }
    printf("File succesfully open!\n");
    while ((fgets(array[line],sizeof(array[line]), fp)) != NULL)
        fputs(array[line++], stdout);
    fclose(fp);
    printf("\n");
    coord->get_board_size = str_to_word_array(array[0], ' ');
    coord->get_pos = str_to_word_array(array[1], ' ');
    return (0);
}

int my_len(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        i += 1;
    }
    return (i);
}

int my_strcmp(char const *s1, char const *s2)
{
    int i = my_len(s1);
    int j = my_len(s2);
    int l = 0;
    int ret = i - j;
    if (ret < 0) {
        ret = i;
    } else {
        ret = j;
    }
    while (l <= ret) {
        if (s1[l] != s2[l]) {
            ret = s1[l] - s2[l];
            return ret;
        } else {
            l += 1;
        }
    }
    return (0);
}