# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/03 09:01:59 by hkalia            #+#    #+#              #
#    Updated: 2017/02/01 12:22:11 by hkalia           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	libftprintf.a
SHELL		:=	/bin/zsh

CC			:=	gcc
CFLAGS		+=	-Wall -Wextra -I includes
CFLAGS		+=	-Werror
#CFLAGS		+=	-g -fsanitize=address
LDFLAGS		+=	-L . $(subst .a,,$(subst lib,-l,$(NAME)))
#LDFLAGS		+=	-g -fsanitize=address

SRC_DIR		:=	srcs
TEST		:=	test.c

FILES		:=	ft_printf ft_printf_arr_1 ft_printf_arr_2 ft_printf_arr_3	\
				ft_printf_begin ft_printf_c ft_printf_d ft_printf_extras_1	\
				ft_printf_extras_2 ft_printf_extras_3 ft_printf_len_mod_1	\
				ft_printf_len_mod_2 ft_printf_o ft_printf_p ft_printf_s		\
				ft_printf_u ft_printf_x ft_vasprintf

SRC			:=	$(addprefix $(SRC_DIR)/, $(addsuffix .c, $(FILES)))
OBJ			:=	$(SRC:.c=.o)

# MATH

MAX			:=	$(words $(OBJ))
n			:=	x
increment	=	$1 x
COUNTER		=	$(words $n)$(eval n := $(call increment,$n))

# RULES

.PHONY: all clean

all: $(NAME)

$(OBJ): %.o: %.c
	@printf "\r\e[31mCompiling...(%d/%d)\e[0m" $(COUNTER) $(MAX)
	@$(CC) -c $(CFLAGS) $(INC_DIR) $< -o $@

$(NAME): $(OBJ)
	@printf "\r\e[32mCompiling...(%d/%d)[DONE]\n\e[0m" $(MAX) $(MAX)
	@printf "\e[32mLinking and indexing... \e[0m"
	@ar rcs $(NAME) $(OBJ)
	@printf "\e[32m[DONE]\e[0m\n"

clean:
	@printf "\e[31mDeleting object files... \e[0m"
	@rm -f $(OBJ)
	@printf "\e[32m[DONE]\e[0m\n"

fclean: clean
	@printf "\e[31mDeleting %s... \e[0m" $(NAME)
	@rm -f $(NAME)
	@printf "\e[32m[DONE]\e[0m\n"

re: fclean all

test: re
	@printf "\e[31mDeleting object files... \e[0m"
	@rm -f $(OBJ)
	@printf "\e[32m[DONE]\e[0m\n"
	@printf "\e[32mCompiling %s with %s... \e[0m" $(TEST) $(NAME)
	@$(CC) $(CFLAGS) $(LDFLAGS) $(TEST) -o test
	@printf "\e[32m[DONE]\e[0m\n"
