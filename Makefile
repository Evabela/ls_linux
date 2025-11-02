##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makefile with principal rules
##

SRC = 	count_flags.c \
	my_putchar.c \
	main.c

OBJ =	$(SRC:.c=.o)

NAME =	my_ls

all:	$(NAME)

$(NAME):	$(OBJ)
	epiclang -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: fclean clean all
