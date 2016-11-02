# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkalia <hkalia@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/28 14:50:32 by hkalia            #+#    #+#              #
#    Updated: 2016/11/02 16:51:27 by hkalia           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a
NAME2		=	-lftprintf
CC 			=	gcc
CFLAGS 		=	-Wall -Wextra -Werror
INC_DIR		=	-I includes/
SRC_DIR		=	srcs
MAIN		=	main.c
OBJ_DIR		=	objs
# CUSTOM
FILES		=	ft_str{new,del,clr,iter,iteri,map,mapi,equ,nequ,sub,join}.c	\
				ft_str{trim,split,extend,len_2}.c							\
				ft_put{str,endl,nbr,char_fd,str_fd,endl_fd,nbr_fd}.c		\
				ft_put{tbl,lststr,nbrstr}.c									\
				ft_lst{new,delone,del,add,iter,map,addend}.c				\
				ft_tbl{new,new_2,del}.c										\
				ft_mem{alloc,del}.c											\
				ft_itoa.c	ft_nbrlen.c
# STRING
FILES		+=	ft_str{len,nlen,dup,ndup,cpy,ncpy,cat,ncat,lcat,chr,rchr}.c	\
				ft_str{str,nstr,cmp,ncmp}.c									\
				ft_mem{set,cpy,chr,ccpy,move,cmp}.c							\
				ft_bzero.c
# CTYPE
FILES		+=	ft_is{alpha,digit,alnum,ascii,print,upper,lower,blank}.c	\
				ft_to{upper,lower}.c
# STDLIB
FILES		+=	ft_atoi.c	ft_calloc.c
# STDIO
FILES		+=	ft_putchar.c ft_asprintf.c
SRC			=	$(addprefix $(SRC_DIR)/, $(FILES))
OBJ			=	$(FILES:.c=.o)

# COLORS

C_NONE		=	"\033[00m"
C_GREEN		=	"\033[32m"
C_RED		=	"\033[31m"
C_YELLOW	=	"\033[33m"

# RULES

.PHONY: all clean

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) -c $(SRC) $(INC_DIR)
	@ar rcs $@ $(OBJ)
	@echo "Compiling & indexing" $(NAME) $(C_GREEN)[DONE]$(C_NONE)

clean:
	@/bin/rm -f $(OBJ)
	@echo $(C_RED)"Cleaning object files ..."$(C_NONE)

fclean: clean
	@/bin/rm -f $(NAME)
	@echo $(C_RED)"Cleaning" $(NAME) $(C_NONE)

re: fclean all

test: re
	@/bin/rm -f $(OBJ)
	@echo $(C_RED)"Cleaning object files ..."$(C_NONE)
	$(CC) $(CFLAGS) $(MAIN) -L . $(NAME2) $(INC_DIR) -o test
