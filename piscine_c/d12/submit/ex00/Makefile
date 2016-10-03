NAME = ft_display_file

SRC = main.c ft_display_file.c ft_putchar.c ft_putstr.c

all: $(NAME)

$(NAME):
	gcc -c -Wall -Wextra -Werror $(SRC)
	gcc -o $(NAME) main.o ft_display_file.o ft_putchar.o ft_putstr.o

clean:
	/bin/rm -f main.o ft_display_file.o ft_putchar.o ft_putstr.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all