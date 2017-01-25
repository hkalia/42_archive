# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/24 14:41:06 by hkalia            #+#    #+#              #
#    Updated: 2017/01/25 14:22:34 by hkalia           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ft_ls
CC		=	gcc
CFLAGS	=	-fsanitize=address -Wall -Wextra -Werror -I libft/includes

.PHONY: all clean
all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) main.c libft.a -o $@

fclean:
	rm -f ft_ls

re: fclean all
