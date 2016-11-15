# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 11:52:51 by hkalia            #+#    #+#              #
#    Updated: 2016/11/14 16:18:45 by hkalia           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	libftprintf.a
SHELL		:=	/bin/zsh
CC 			:=	gcc
CFLAGS		+=	-Wall -Wextra -Werror -I includes
CFLAGS		+=	-fsanitize=address
SRC_DIR		:=	srcs
MAIN		:=	main.c
FT_CUSTOM	:=	ft_strnew		ft_strdel		ft_strclr		ft_striter		\
				ft_striteri		ft_strmap		ft_strmapi		ft_strequ		\
				ft_strnequ		ft_strsub		ft_strjoin		ft_strtrim		\
				ft_strsplit		ft_strextend	ft_strlen_2		ft_putstr		\
				ft_putendl		ft_putnbr		ft_putchar_fd	ft_putstr_fd	\
				ft_putendl_fd	ft_putnbr_fd	ft_puttbl		ft_putlststr	\
				ft_putnbrstr	ft_lstnew		ft_lstdelone	ft_lstdel		\
				ft_lstadd		ft_lstiter		ft_lstmap		ft_lstaddend	\
				ft_tblnew		ft_tblnew_2		ft_tbldel		ft_memalloc		\
				ft_memdel		ft_itoa			ft_nbrlen		ft_putnbr_base	\
				ft_wcstombs		ft_strjoin_2	ft_strdel_2
FT_STRING	:=	ft_strlen		ft_strnlen		ft_strdup		ft_strndup		\
				ft_strcpy		ft_strncpy		ft_strcat		ft_strncat		\
				ft_strlcat		ft_strchr		ft_strrchr		ft_strstr		\
				ft_strnstr		ft_strcmp		ft_strncmp		ft_memset		\
				ft_memcpy		ft_memchr		ft_memccpy		ft_memmove		\
				ft_memcmp		ft_bzero
FT_CTYPE	:=	ft_isalpha		ft_isdigit		ft_isalnum		ft_isascii		\
				ft_isprint		ft_isupper		ft_islower		ft_isblank		\
				ft_toupper		ft_tolower
FT_STDIO	:=	ft_putchar		ft_vasprintf	ft_printf_flags	ft_printf_width	\
				ft_printf_dot	ft_printf_hh	ft_printf_h		ft_printf_l		\
				ft_printf_ll	ft_printf_j		ft_printf_z		ft_printf_mod	\
				ft_printf_cap_c	ft_printf_c		ft_printf_cap_d	ft_printf_d		\
				ft_printf_i		ft_printf_cap_o	ft_printf_o		ft_printf_p		\
				ft_printf_cap_s	ft_printf_s		ft_printf_cap_u	ft_printf_u		\
				ft_printf_cap_x	ft_printf_x		ft_printf
FT_STDLIB	:=	ft_atoi			ft_calloc		ft_abs			ft_wctomb
FILES		:=	$(addprefix ft_custom/, $(FT_CUSTOM))	\
				$(addprefix ft_string/, $(FT_STRING))	\
				$(addprefix ft_ctype/, $(FT_CTYPE))		\
				$(addprefix ft_stdio/, $(FT_STDIO))		\
				$(addprefix ft_stdlib/, $(FT_STDLIB))
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
	@ar rcs $(NAME) $(OBJ)
	@printf "\e[32mLinking and indexing... [DONE]\U1F44C\e[0m\n"

clean:
	@-rm -f $(OBJ)
	@printf "\e[31mDeleting object files... [DONE]\U1F44C\e[0m\n"

fclean: clean
	@-rm -f $(NAME)
	@printf '\e[31mDeleting %s... [DONE]\U1F44C\e[0m\n' $(NAME)

re: fclean all

test: re
	@-rm -f $(OBJ)
	@printf "\e[31mDeleting object files... [DONE]\U1F44C\e[0m\n"
	@$(CC) $(CFLAGS) $(MAIN) -L . $(subst .a,,$(subst lib,-l,$(NAME)))\
	$(INC_DIR) -o test
	@printf "\e[32mCompiling %s with %s... [DONE]\U1F44C\e[0m\n" $(MAIN) $(NAME)
