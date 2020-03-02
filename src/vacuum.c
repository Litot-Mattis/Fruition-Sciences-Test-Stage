#include "include/my.h"

int deplacement(char *command, int line, int dir, coord_t *coord)
{
    if (command[line] == 'A') {
        if (dir == 0)
            coord->y += 1;
        if (dir == 1)
            coord->x += 1;
        if (dir == 2)
            coord->y -= 1;
        if (dir == 3)
            coord->x -= 1;
    }
    if (dir == 4)
        dir = 0;
    return (dir);
}

int get_orientation(int dir)
{
    if (dir == 0)
        printf("N\n");
    if (dir == 1)
        printf("E\n");
    if (dir == 3)
        printf("W\n");
    if (dir == 4)
        printf("S\n");
}

int error_handling(coord_t *coord)
{
    if (coord->x > my_getnbr(coord->get_board_size[0]) || coord->y > my_getnbr(coord->get_board_size[0])) {
        printf("The Vacuum is out of the range.\n");
        return (84);
    }
    return (0);
}

int command(char *command, coord_t *coord)
{
    int cmd = 0;
    int dir = 0;
    char direction;

    for (int line = 0; command[line] != '\0'; line += 1) {
        if (command[line] == 'D') {
            cmd += 1;
            dir += 1;
        }
        else if (command[line] == 'G') {
            cmd = 2;
            dir -= 1;
        }
        dir = deplacement(command, line, dir, coord);
    }
    if (error_handling(coord) == 84)
        return(84);
    printf("Vacuum robot finish is operation perfectly!\n");
    printf("The vacuum cleaner is on the position: ");
    printf("%d", coord->x);
    printf(" %d ", coord->y);
    get_orientation(dir);
}

void documentation(void)
{
    printf("~~~USAGE~~~\nTo launch the program vacuum, use de command:\n./vacuum Test_file\n");
}

int main(int ac, char **av)
{
    coord_t coord;
    char *str = "DADADADAA";

    if (my_strcmp(av[1], "-h") == 0) {
        documentation();
        return (0);
    }
    if (read_info_file(av[1],&coord) == 84)
        return (84);
    coord.x = my_getnbr(coord.get_pos[0]);
    coord.y = my_getnbr(coord.get_pos[1]);
    command(str, &coord);
}