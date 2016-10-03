NAME = rush-2

SRC = main.c linked_list.c print.c all_rush_0.c rush_call.c

all: $(NAME)

$(NAME):
	gcc -c -Wall -Wextra -Werror $(SRC) 
	gcc -o $(NAME) main.o linked_list.o print.o all_rush_0.o rush_call.o

clean:
	/bin/rm -f main.o linked_list.o print.o all_rush_0.o rush_call.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all