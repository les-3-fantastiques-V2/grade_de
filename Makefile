##
## EPITECH PROJECT, 2023
## corewar
## File description:
## Makefile
##

SRC		=   $(wildcard src/loader/*.c)						\
			$(wildcard src/games/runner/src/*.c)			\

OBJ 	= 	$(patsubst src/%.c,object/%.o,$(SRC))

NAME	=	"runner"

FLAGS	=	-I./include			\
			-I../include		\
			-L../lib			\
			-llist_d			\
			-lmap				\
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
	@make -C ../lib/map
	$(COMP) -o $(NAME) $(SRC) $(FLAGS)

all:	$(NAME)

clean:
	@rm -rf vgcore*
	@rm -rf $(OBJ)
	@make -C ../lib/list fclean
	@make -C ../lib/map fclean
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