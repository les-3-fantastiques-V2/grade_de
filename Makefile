##
## EPITECH PROJECT, 2023
## minishell2
## File description:
## Makefile
##

GREEN	=	"\033[32m"
BLUE	=	"\033[34m"
RED		=	"\033[31m"
NORMAL	=	"\033[0m"
BLING	=	"\033[5m"
BOLD	=	"\033[1m"


SRC		=   $(wildcard src/*.c)

OBJ 	= 	$(patsubst src/%.c,object/%.o,$(SRC))

NAME	=	"grade_de"

FLAGS	=	-I./include			\
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
	@echo -ne " >> Compilation des sources...\n\n"
	@echo -ne $(NORMAL)
	$(COMP) -o $(NAME) $(OBJ) $(FLAGS)
	@echo -ne $(GREEN)
	@echo -ne $(BLING)
	@echo -ne $(BOLD)
	@echo -ne "\n >> Compilation réussi !\n"
	@echo -ne $(NORMAL)

all:	$(NAME)

clean:
	@rm -rf vgcore*
	@rm -rf $(OBJ)
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
