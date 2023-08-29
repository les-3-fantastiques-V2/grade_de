##
## EPITECH PROJECT, 2023
## minishell2
## File description:
## Makefile
##

SRC		=   $(wildcard src/controller/manager/*.c)				\
			$(wildcard src/controller/scene/MenuChooseGame/*.c)	\
			$(wildcard src/controller/scene/MenuSettings/*.c)	\
			$(wildcard src/provider/cursor/*.c)					\
			$(wildcard src/provider/font/*.c)					\
			$(wildcard src/provider/gameSlot/*.c)				\
			$(wildcard src/provider/scene/*.c)					\
			$(wildcard src/provider/system/*.c)					\
			$(wildcard src/service/csfml/*.c)					\
			$(wildcard src/service/math/*.c)					\
			$(wildcard src/service/text/*.c)					\
			$(wildcard src/*.c)

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

CSFML	=	-lcsfml-graphics	\
			-lcsfml-window		\
			-lcsfml-system		\
			-lcsfml-audio

COMP	=	gcc

$(NAME):	$(OBJ)
	@echo -ne " >> Compilation des sources...\n"
	@$(COMP) -o $(NAME) $(OBJ) $(FLAGS) $(CSFML)
	@echo -ne " >> Compilation réussi !\n"

all:	$(NAME)

clean:
	@rm -rf vgcore*
	@rm -rf $(OBJ)
	@rm -rf object

fclean: clean
	@rm -rf $(NAME)

re: fclean all

valgrind $(ARGS):
	@$(COMP) -o $(NAME) $(SRC) $(FLAGS) $(CSFML) -g3
	@make clean
	@valgrind -s ./$(NAME) $(ARGS)

valgrind_plus $(ARGS):
	@$(COMP) -o $(NAME) $(SRC) $(FLAGS) $(CSFML) -g3
	@make clean
	@valgrind -s --leak-check=full --show-leak-kinds=all ./$(NAME)

debug:
	@$(COMP) -o $(NAME) $(SRC) $(FLAGS) $(CSFML) -g3

object/%.o: src/%.c
	@mkdir -p $(@D)
	@$(COMP) $(FLAGS) $(CSFML) -c -o $@ $<
