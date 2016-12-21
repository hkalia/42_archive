# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 11:52:51 by hkalia            #+#    #+#              #
#    Updated: 2016/12/21 11:10:56 by hkalia           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	fdf
SHELL		:=	/bin/zsh

CC			:=	gcc
CFLAGS		+=	-Wall -Wextra -I includes
CFLAGS		+=	-Werror
CFLAGS		+=	-I libft/includes
CFLAGS		+=	-I minilibx
#CFLAGS		+=	-fsanitize=address
LDFLAGS		+=	-L libft/ -lft
LDFLAGS		+=	-L minilibx -lmlx -framework OpenGL -framework AppKit
#LDFLAGS		+=	-fsanitize=address

MINILIBX	:=	minilibx/libmlx.a
LIBFT		:=	libft/libft.a

SRC_DIR		:=	srcs

FILES		:=	key line main mouse pixel
SRC			:=	$(addprefix $(SRC_DIR)/, $(addsuffix .c, $(FILES)))
OBJ			:=	$(SRC:.c=.o)

# MATH

MAX			:=	$(words $(OBJ))
n			:=	x
increment	=	$1 x
COUNTER		=	$(words $n)$(eval n := $(call increment,$n))

# RULES

.PHONY: all clean norm

all: $(NAME)

$(MINILIBX):
	make -C minilibx/

$(LIBFT):
	make -C libft/

$(OBJ): %.o: %.c
	@printf "\r\e[31mCompiling...(%d/%d)\e[0m" $(COUNTER) $(MAX)
	@$(CC) -c $(CFLAGS) $(INC_DIR) $< -o $@

$(NAME): $(LIBFT) $(MINILIBX) $(OBJ)
	@printf "\r\e[32mCompiling...(%d/%d)[DONE]\n\e[0m" $(MAX) $(MAX)
	@printf "\e[32mLinking... \e[0m"
	@$(CC) -o $(NAME) $(LDFLAGS) $(OBJ)
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

norm:
	@norminette includes srcs
