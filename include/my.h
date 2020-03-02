#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <stdarg.h>
#include <string.h>

#define MAXCHAR 1000

typedef struct coord_s
{
    int x;
    int y;
    char **get_board_size;
    char **get_pos;
    char *command_line;
}coord_t;

//str_to_word_array:
int my_strlen(char const *str);
int count_c(char *str, char c);
int count_line(char *str);
char *my_strndup(char *str, int a);
char **str_to_word_array(char *str, char c);

//my_lib:
int my_getnbr(char *str);
int read_info_file(char *av, coord_t *coord);
int my_len(char const *str);
int my_strcmp(char const *s1, char const *s2);

//vacuum:
int deplacement(char *command, int line, int dir, coord_t *coord);
int get_orientation(int dir);
int error_handling(coord_t *coord);
int command(char *command, coord_t *coord);
int main(int ac, char **av);