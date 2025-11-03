##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makefile
##


SRC = 	my_len.c \
	my_strcmp.c \
	my_strdup.c \
	my_putchar.c

OBJ =	$(SRC:.c=.o)

NAME =	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: fclean clean all

