NAME		:=	libft.a
SHELL		:=	/bin/zsh

CC 			:=	gcc
CFLAGS		+=	-Wall -Wextra -I includes
CFLAGS		+=	-Werror
#CFLAGS		+=	-g
#CFLAGS		+=	-fsanitize=address

SRC_DIR		:=	srcs
OBJ_DIR		:=	build
TEST		:=	test.c

ARR			:=
CHR			:=	ft_isalnum ft_isalpha ft_isascii ft_isblank ft_iscntrl \
 				ft_isdigit ft_isgraph ft_islower ft_isprint ft_ispunct \
				ft_isspace ft_isupper ft_isxdigit ft_putchar_fd ft_putchar \
				ft_tolower ft_toupper 
GNL			:=
LST			:=
MEM			:=
NBR			:=
PRINTF		:=
STR			:=
TBL			:=
WCHR		:=
FILES		:=	$(addprefix arr/, $(ARR))	\
				$(addprefix chr/, $(CHR))	\
				$(addprefix gnl/, $(GNL))	\
				$(addprefix lst/, $(LST))	\
				$(addprefix mem/, $(MEM))	\
				$(addprefix nbr/, $(NBR))	\
				$(addprefix printf/, $(PRINTF))	\
				$(addprefix str/, $(STR))	\
				$(addprefix tbl/, $(TBL))	\
				$(addprefix wchr/, $(WCHR))	\

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
	@$(CC) $(CFLAGS) $(TEST) -L . $(subst .a,,$(subst lib,-l,$(NAME))) -o test
	@printf "\e[32m[DONE]\U1F44C\e[0m\n"
