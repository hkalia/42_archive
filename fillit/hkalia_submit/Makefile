NAME = fillit

CC = gcc

CFLAG = -Wall -Werror -Wextra

LIB = libft.a

SRC_NAME =	fillit_main.c \
			fillit_validators.c \
			fillit_specific_tbl.c \
			fillit_solve.c \
			fillit_solve_setup.c \
			fillit_solve_tetsetup.c

OBJ_NAME = $(SRC_NAME:.c=.o)

RM = rm -f

NORM = norminette

.PHONY: all clean fclean re norm

all: $(NAME)

$(NAME): 
	$(CC) -c $(CFLAG) $(SRC_NAME)
	$(CC) $(OBJ_NAME) $(LIB) -o $(NAME)

clean:
	$(RM) $(OBJ_NAME)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

norm: 
	$(NORM) $(SRC_NAME)
