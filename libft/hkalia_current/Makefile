# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/03 09:01:59 by hkalia            #+#    #+#              #
#    Updated: 2016/12/14 19:39:20 by hkalia           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	libft.a
SHELL		:=	/bin/zsh

CC 			:=	gcc
CFLAGS		+=	-Wall -Wextra -I includes
CFLAGS		+=	-Werror
CFLAGS		+=	-fsanitize=address
LDFLAGS		+=	-L . $(subst .a,,$(subst lib,-l,$(NAME)))
LDFLAGS		+=	-fsanitize=address

SRC_DIR		:=	srcs
TEST		:=	test.c

ARR			:=	arr_dtr arr_init arr_insertat arr_removeat arr_reserve
FT_CTYPE	:=	ft_isalnum ft_isalpha ft_isascii ft_isblank ft_iscntrl		\
				ft_isdigit ft_isgraph ft_islower ft_isprint ft_ispunct		\
				ft_isspace ft_isupper ft_isxdigit ft_tolower ft_toupper
FT_STDIO	:=	ft_putchar_fd ft_putchar
FT_STDLIB	:=	ft_abs ft_atoi ft_calloc ft_wctomb
FT_STRING	:=	ft_bzero ft_memccpy ft_memchr ft_memcmp ft_memcpy			\
				ft_memmove ft_memset ft_strcat ft_strchr ft_strcmp			\
				ft_strcpy ft_strdup ft_strlcat ft_strlen ft_strncat			\
				ft_strncmp ft_strncpy ft_strndup ft_strnlen ft_strnstr		\
				ft_strrchr ft_strstr
LST			:=	ft_lstadd ft_lstaddend ft_lstdel ft_lstdelone ft_lstiter	\
				ft_lstmap ft_lstnew
MEM			:=	ft_memalloc ft_memdel ft_realloc ft_reallocf
NBR			:=	ft_itoa_base ft_itoa ft_nbrlen_base ft_nbrlen				\
				ft_putnbr_base ft_putnbr_fd ft_putnbr
STR			:=	ft_putendl_fd ft_putendl ft_putstr_fd ft_putstr ft_strclr	\
				ft_strdel_2 ft_strdel ft_strequ ft_strextend ft_striter		\
				ft_striteri ft_strjoin_2 ft_strjoin ft_strlen_2 ft_strmap	\
				ft_strmapi ft_strnequ ft_strnew ft_strsplit ft_strsub		\
				ft_strtrim
TBL			:=	ft_puttbl ft_tbldel ft_tblnew_2 ft_tblnew
WCHR		:=
FILES		:=	$(addprefix arr/, $(ARR))		\
				$(addprefix ft_ctype/, $(FT_CTYPE))	\
				$(addprefix ft_stdio/, $(FT_STDIO))	\
				$(addprefix ft_stdlib/, $(FT_STDLIB))	\
				$(addprefix ft_string/, $(FT_STRING))	\
				$(addprefix gnl/, $(GNL))		\
				$(addprefix lst/, $(LST))		\
				$(addprefix mem/, $(MEM))		\
				$(addprefix nbr/, $(NBR))		\
				$(addprefix str/, $(STR))		\
				$(addprefix tbl/, $(TBL))		\
				$(addprefix wchr/, $(WCHR))		\

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
	@printf "\r\e[32mCompiling...(%d/%d)[DONE]\U1F44C\n\e[0m" $(MAX) $(MAX)
	@printf "\e[32mLinking and indexing... \e[0m"
	@ar rcs $(NAME) $(OBJ)
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
	@printf "\e[32mCompiling %s with %s... \e[0m" $(TEST) $(NAME)
	@$(CC) $(CFLAGS) $(LDFLAGS) $(TEST) -o test
	@printf "\e[32m[DONE]\U1F44C\e[0m\n"
