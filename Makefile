##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## 
##

SRC	=	src/windows.c	\
		src/randnum.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_hunter

CPPFLAGS=	-I include

LDFLAGS	=	-l c_graph_prog -L lib/my -lmy

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	make clean -C lib/my
	$(RM) $(OBJ)

fclean: clean
	make fclean -C lib/my
	$(RM) $(NAME)

re: fclean all
