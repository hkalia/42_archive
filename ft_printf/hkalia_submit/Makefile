NAME = libftprintf.a

CC = gcc

CFLAG = -Wall -Werror -Wextra

SRC =

OBJ = $(SRC:.c=.o)

HDR_DIR = includes

AR = ar rc

RLIB = ranlib

RM = rm -f

.PHONY: all clean

all: $(NAME)

$(NAME):
	$(CC) $(CFLAG) -c $(SRC) -I $(HDR_DIR)
	$(AR) $(NAME) $(OBJ)
	$(RLIB) $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

