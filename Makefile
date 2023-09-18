##
## EPITECH PROJECT, 2023
## grade_de
## File description:
## Makefile
##

SRC		=   $(wildcard src/controller/manager/*.c)								\
			$(wildcard src/controller/scene/gamePacman/*.c)						\
			$(wildcard src/controller/scene/menuChooseGame/gameSlot/*.c)		\
			$(wildcard src/controller/scene/menuChooseGame/*.c)					\
			$(wildcard src/controller/scene/menuSetting/settingsSections/*.c)	\
			$(wildcard src/controller/scene/menuSetting/*.c)					\
			$(wildcard src/controller/scene/menuStats/credentials/*.c)			\
			$(wildcard src/controller/scene/menuStats/statsSections/*.c)		\
			$(wildcard src/controller/scene/menuStats/*.c)						\
			$(wildcard src/provider/button/*.c)									\
			$(wildcard src/provider/cursor/*.c)									\
			$(wildcard src/provider/font/*.c)									\
			$(wildcard src/provider/mazeGenerator/*.c)							\
			$(wildcard src/provider/music/*.c)									\
			$(wildcard src/provider/scene/*.c)									\
			$(wildcard src/provider/sound/*.c)									\
			$(wildcard src/provider/system/*.c)									\
			$(wildcard src/provider/transition/*.c)								\
			$(wildcard src/service/csfml/*.c)									\
			$(wildcard src/service/files/*.c)									\
			$(wildcard src/service/math/*.c)									\
			$(wildcard src/service/text/*.c)									\
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

LIB	=	-lcsfml-graphics	\
		-lcsfml-window		\
		-lcsfml-system		\
		-lcsfml-audio		\
		-lm

COMP	=	gcc

$(NAME):	$(OBJ)
	@echo -ne " >> Compilation des sources...\n"
	@$(COMP) -o $(NAME) $(OBJ) $(FLAGS) $(LIB)
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
	@$(COMP) -o $(NAME) $(OBJ) $(FLAGS) $(LIB) -g3
	@make clean
	@valgrind -s ./$(NAME) $(ARGS)

valgrind_plus $(ARGS):
	@$(COMP) -o $(NAME) $(OBJ) $(FLAGS) $(LIB) -g3
	@make clean
	@valgrind -s --leak-check=full --show-leak-kinds=all ./$(NAME)

debug:
	@$(COMP) -o $(NAME) $(OBJ) $(FLAGS) $(LIB) -g3

object/%.o: src/%.c
	@mkdir -p $(@D)
	@$(COMP) $(FLAGS) $(CSFML) -c -o $@ $<
