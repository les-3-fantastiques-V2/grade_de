##
## EPITECH PROJECT, 2023
## corewar
## File description:
## Makefile
##

SRC		=   $(wildcard src/*.c)

OBJ 	= 	$(patsubst src/%.c,object/%.o,$(SRC))

GREEN	=	"\033[32m"

BLUE	=	"\033[34m"

RED		=	"\033[31m"

NORMAL	=	"\033[0m"

BLING	=	"\033[5m"

BOLD	=	"\033[1m"

NAME	=	"runner"

FLAGS	=	-I./include			\
			-I../include		\
			-L../lib			\
			-llist				\
			-lcsfml-graphics	\
			-lcsfml-system		\
			-lcsfml-window		\
			-Wall 				\
			-Wextra				\
			-Wfloat-equal 		\
			-Wundef 			\
			-Wcast-align		\
			-Wshadow			\
			-Wlogical-op		\
			-Wredundant-decls

COMP	=	gcc

$(NAME):	$(OBJ)
	@make -C ../lib/list double
	$(COMP) -o $(NAME) $(SRC) $(SRC_OPT) $(FLAGS)

all:	$(NAME)

clean:
	@rm -rf vgcore*
	@rm -rf $(OBJ)
	@make -C ../lib/list fclean
	@rm -rf object

fclean: clean
	@rm -rf $(NAME)

re: fclean all

valgrind $(ARGS):
	@$(COMP) -o $(NAME) $(SRC) $(FLAGS) -g3
	@make clean
	@valgrind -s ./$(NAME) $(ARGS)

valgrind_plus $(ARGS):
	@$(COMP) -o $(NAME) $(SRC) $(FLAGS) -g3
	@make clean
	@valgrind -s --leak-check=full --show-leak-kinds=all ./$(NAME)

debug:
	@$(COMP) -o $(NAME) $(SRC) $(FLAGS) -g3

object/%.o: src/%.c
	@mkdir -p $(@D)
	@$(COMP) $(FLAGS) -c -o $@ $<