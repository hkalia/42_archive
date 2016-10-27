NAME		=	libft.a
LIB			=	-lft
CC			=	gcc
CFLAG		=	-Wall -Werror -Wextra
MAIN		=	main.c
HDR_DIR		=	includes
AR			=	ar rc
RLIB		=	ranlib
RM			=	rm -f
FILES		=	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c						\
				ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c						\
				ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c						\
				ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c					\
				ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c						\
				ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c						\
				ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c					\
				ft_printf.c ft_memalloc.c ft_memdel.c ft_strnew.c						\
				ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c					\
				ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c						\
				ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c					\
				ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c							\
				ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c	\
				ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c				\
				ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_calloc.c						\
				ft_strextend.c ft_strlen_2.c ft_strnlen.c ft_strndup.c			\
				ft_putnbrstr.c ft_isupper.c ft_islower.c ft_isblank.c				\
				ft_putlststr.c ft_lstaddend.c ft_tblnew.c ft_tbldel.c				\
				ft_puttbl.c ft_nbrlen.c
SRC			=		$(addprefix srcs/, $(FILES))
OBJ			= 	$(FILES:.c=.o)

# COLORS

C_NONE		=	"\033[00m"
C_GREEN		=	"\033[32m"
C_RED			=	"\033[31m"
C_YELLOW	=	"\033[33m"

# RULES

.PHONY: all clean

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAG) -c $(SRC) -I $(HDR_DIR)
	@$(AR) $(NAME) $(OBJ)
	@$(RLIB) $(NAME)
	@echo "Compiling & indexing" $(NAME) $(C_GREEN)[DONE]$(C_NONE)

clean:
	@$(RM) $(OBJ)
	@echo $(C_RED)"Cleaning object files ..."$(C_NONE)

fclean: clean
	@$(RM) $(NAME)
	@echo $(C_RED)"Cleaning" $(NAME) $(C_NONE)

re: fclean all

habib: fclean all
	@$(RM) $(OBJ)
	@echo $(C_RED)"Cleaning object files ..."$(C_NONE)
	@$(CC) $(CFLAG) $(MAIN) -I $(HDR_DIR) -L . $(LIB)
	@echo "Compiling" $(MAIN) $(C_GREEN)[DONE]$(C_NONE)
