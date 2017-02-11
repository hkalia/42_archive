CC = gcc

CFLAGS = -Werror -Wextra -Wall

NAME = bsq

SRCS = main.c ft_algo.c ft_open.c ft_print.c ft_str.c

OBJECTS = main.o ft_algo.o ft_open.o ft_print.o ft_str.o

all: $(NAME)

$(NAME):
	$(CC) -c $(CFLAGS) $(SRCS)
	$(CC) -o $(NAME) $(OBJECTS)

clean:
	/bin/rm -f $(OBJECTS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all