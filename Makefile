##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Task01 of CPool Day10
##

SRC		=		main.c						\
				linked_lists.c				\
				add_to_list_tunnel.c		\
				add_to_list.c				\
				init_remove_list_tunnel.c	\
				init_remove_list.c			\
				create_rooms.c				\
				rooms.c						\
				ants_moves.c				\
				create_anthill.c			\
				moves.c

OBJ		=		$(SRC:.c=.o)

NAME	=		lem_in

all:	$(NAME) clean

$(NAME):	$(OBJ)
		(cd ./lib/my/ && make)
		gcc -o $(NAME) $(OBJ) -g3 -Llib/my/. -lmy

clean:
		@rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re:		fclean all clean

auteur:
		echo LuCas > Auteur
