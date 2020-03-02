##
## EPITECH PROJECT, 2019
## makefile infin_add
## File description:
## compile lib etc
##

SRC	=	$(wildcard src/*.c) \

OBJ	=	$(SRC:.c=.o)

NAME	=	vacuum

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(TEST) -W -Wall -Wextra -g3
clean:
	rm -f $(OBJ)
fclean:	clean
	rm -f $(NAME)
re:	fclean all