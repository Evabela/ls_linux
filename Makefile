##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makefile with principal rules
##

SRC = 	count_flags.c \
	display_ls.c \
	errors.c \
	main.c

TESTS_SRC =	count_flags.c \
	errors.c \
	display_ls.c

OBJ =	$(SRC:.c=.o)

NAME =	my_ls

all:	$(NAME)

$(NAME):	$(OBJ)
	cd lib && $(MAKE)
	epiclang -o $(NAME) $(OBJ) -Llib -lmy

tests_run:
	cd lib && $(MAKE)
	epiclang -o unit_tests $(TESTS_SRC) tests/*.c -Llib -lmy --coverage -lcriterion -lgcov
	./unit_tests

gcovrex:	tests_run
	gcovr --gcov-executable "llvm-cov-20 gcov"
	gcovr --branches --gcov-executable "llvm-cov-20 gcov"

clean:
	rm -f $(OBJ)
	cd lib && $(MAKE) clean
	rm -f *.gcda
	rm -f *.gcno

fclean:	clean
	rm -f $(NAME)
	cd lib && $(MAKE) fclean
	rm -f unit_tests

re:	fclean all

.PHONY: fclean clean all
