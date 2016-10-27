NAME = libftprintf.a

CC = gcc

CFLAG = -Wall -Werror -Wextra

SRC = ft_printf.c \
		ft_asprintf.c \
		ft_dprintf.c \
		ft_strnew.c

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

habib: fclean
	$(CC) $(CFLAG) -c $(SRC) -I $(HDR_DIR)
	$(AR) $(NAME) $(OBJ)
	$(RLIB) $(NAME)
	$(CC) $(CFLAG) main.c -I $(HDR_DIR) -L . -lftprintf
	$(RM) $(OBJ)
