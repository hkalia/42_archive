NAME = test_gnl

CC = clang

CFLAG = -Wall -Werror -Wextra 

OBJ = main.o \
	  get_next_line.o

HDR_DIR = libft/includes

RM = rm -f

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	$(CC) $(CFLAG) -I $(HDR_DIR) -o get_next_line.o -c get_next_line.c
	$(CC) $(CFLAG) -I $(HDR_DIR) -o main.o -c main.c
	$(CC) -o $(NAME) main.o get_next_line.o -I $(HDR_DIR) -L libft/ -lft

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

habib: re
	$(RM) $(OBJ)
