# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/24 14:41:06 by hkalia            #+#    #+#              #
#    Updated: 2017/01/28 14:08:00 by hkalia           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ft_ls
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -I libft/includes

.PHONY: all clean
all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) args.c extra.c libft.a main.c print_dirs.c print_files.c print.c -o $@

fclean:
	rm -f ft_ls

re: fclean all
