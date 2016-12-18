# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 11:52:51 by hkalia            #+#    #+#              #
#    Updated: 2016/12/18 09:42:49 by hkalia           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	fdf
SHELL		:=	/bin/zsh

CC			:=	gcc
CFLAGS		+=	-Wall -Wextra -I includes
CFLAGS		+=	-Werror
#CFLAGS		+=	-g
#CFLAGS		+=	-fsanitize=address
#LDFLAGS		+=	-fsanitize=address
LDFLAGS		+=	-L minilibx -lmlx -framework OpenGL -framework AppKit
MINILIBX	:=	minilibx/libmlx.a

SRC_DIR		:=	srcs

FILES		:=	img key line main mouse pixel
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

$(OBJ): %.o: %.c
	@printf "\r\e[31mCompiling...(%d/%d)\e[0m" $(COUNTER) $(MAX)
	@$(CC) -c $(CFLAGS) $(INC_DIR) $< -o $@

$(NAME): $(MINILIBX) $(OBJ)
	@printf "\r\e[32mCompiling...(%d/%d)[DONE]\U1F44C\n\e[0m" $(MAX) $(MAX)
	@printf "\e[32mLinking... \e[0m"
	@$(CC) -o $(NAME) $(LDFLAGS) $(OBJ)
	@printf "\e[32m[DONE]\U1F44C\e[0m\n"

clean:
	@printf "\e[31mDeleting object files... \e[0m"
	@rm -f $(OBJ)
	@printf "\e[32m[DONE]\U1F44C\e[0m\n"

fclean: clean
	@printf "\e[31mDeleting %s... \e[0m" $(NAME)
	@rm -f $(NAME)
	@printf "\e[32m[DONE]\U1F44C\e[0m\n"

re: fclean all

test: re
	@printf "\e[31mDeleting object files... \e[0m"
	@rm -f $(OBJ)
	@printf "\e[32m[DONE]\U1F44C\e[0m\n"

norm:
	@norminette includes srcs
