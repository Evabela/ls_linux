##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makefile with principal rules
##

SRC = 	count_flags.c \
	display_ls.c \
	errors.c \
	flags/flag_a.c \
	flags/flag_d.c \
	flags/flag_l.c \
	flags/flag_ru.c \
	flags/flag_t.c \
	normal_ls.c \
	main.c

OBJ =	$(SRC:.c=.o)

NAME =	my_ls

all:	$(NAME)

$(NAME):	$(OBJ)
	cd lib && $(MAKE)
	epiclang -o $(NAME) $(OBJ) -Llib -lmy

clean:
	rm -f $(OBJ)
	cd lib && $(MAKE) clean

fclean:	clean
	rm -f $(NAME)
	cd lib && $(MAKE) fclean

re:	fclean all

.PHONY: fclean clean all
