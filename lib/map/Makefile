##
## EPITECH PROJECT, 2023
## corewar
## File description:
## Makefile
##

SRC		=   $(wildcard ./*.c)

OBJ		=	$(SRC:.c=.o)

NAME	=	"libmap.a"

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	mv $(NAME) ../
	cp map.h ../../include/
	rm -rf $(OBJ)

all:	$(NAME)

clean:
	rm -rf ../$(NAME)

fclean: clean
