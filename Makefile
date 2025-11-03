##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makefile with principal rules
##

SRC = 	count_flags.c \
	main.c

OBJ =	$(SRC:.c=.o)

NAME =	my_ls

all:	$(NAME)

$(NAME):	$(OBJ)
	cd lib && $(MAKE)
	epiclang -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
	cd lib && $(MAKE) clean

fclean:	clean
	rm -f $(NAME)
	cd lib && $(MAKE) fclean

re:	fclean all

.PHONY: fclean clean all
