# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 11:52:51 by hkalia            #+#    #+#              #
#    Updated: 2016/12/05 12:31:29 by hkalia           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	fdf
SHELL		:=	/bin/zsh
CC 			:=	gcc
CFLAGS		+=	-Wall -Wextra -I includes
CFLAGS		+=	-Werror
#CFLAGS		+=	-g
LDFLAGS		+=	-fsanitize=address
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
	@$(CC) -c $(CFLAGS) $< -o $@

$(NAME): $(MINILIBX) $(OBJ)
	@printf "\r\e[32mCompiling...(%d/%d)[DONE]\U1F44C\n\e[0m" $(MAX) $(MAX)
	@$(CC) -o $(NAME) $(LDFLAGS) $(OBJ)
	@printf "\e[32mLinking... [DONE]\U1F44C\e[0m\n"

clean:
	@rm -f $(OBJ)
	@printf "\e[31mDeleting object files... [DONE]\U1F44C\e[0m\n"

fclean: clean
	@rm -f $(NAME)
	@printf '\e[31mDeleting %s... [DONE]\U1F44C\e[0m\n' $(NAME)

re: fclean all

test: fclean all
	@rm -f $(OBJ)
	@printf "\e[31mDeleting object files... [DONE]\U1F44C\e[0m\n"

norm:
	@norminette includes srcs
