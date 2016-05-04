CC 		= gcc
NAME 	= prepX
SRC		= functions_print.c		\
		functions_str.c		\
		functions_start.c		\
		functions_algo.c		\
		main.c 		\

OBJ		= $(SRC:%.c=%.o)
RM 		= rm -f
CFLAGS = -W -Werror -Wall

$(NAME):	$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

all:	$(NAME) clean

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all