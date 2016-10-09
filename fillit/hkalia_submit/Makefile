NAME = fillit

CC = gcc

CFLAG = -Wall -Werror -Wextra

OFLAG = 

SRC_NAME = fillit_main.c \
		   fillit_str.c \
		   fillit_tbl.c \
		   fillit_validators.c

OBJ_NAME = $(SRC_NAME:.c=.o)

RM = rm -f

NORM = norminette

.PHONY: all clean fclean re norm habib

all: $(NAME)

$(NAME): 
	$(CC) -c $(CFLAG) $(SRC_NAME)
	$(CC) $(OBJ_NAME) $(OFLAG) -o $(NAME)

clean:
	$(RM) $(OBJ_NAME)

fclean: clean
	$(RM) $(NAME)

re: fclean all

norm: 
	$(NORM) $(SRC_NAME)

habib: re
	$(RM) $(OBJ_NAME)
