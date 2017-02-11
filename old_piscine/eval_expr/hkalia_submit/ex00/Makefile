CC = gcc

NAME = eval_expr

SRC = main.c eval_expr.c ft_putchar.c ft_putnbr.c ft_atoi.c

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	$(CC) -c $(CFLAGS) $(SRC)
	$(CC) -o $(NAME) main.o eval_expr.o ft_putchar.o ft_putnbr.o ft_atoi.o

clean:
	/bin/rm -f main.o eval_expr.o ft_putchar.o ft_putnbr.o ft_atoi.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
