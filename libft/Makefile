CC=gcc
FLAGS=-Wall -Werror -Wextra
FILES=ft_isdigit.c ft_memdel.c ft_putnbr_fd.c ft_strdel.c ft_strmap.c \
ft_strrchr.c ft_isprint.c ft_memmove.c ft_putstr.c ft_strdup.c ft_strmapi.c \
ft_strsplit.c ft_itoa.c ft_memset.c ft_putstr_fd.c ft_strequ.c ft_strncat.c \
ft_strstr.c ft_atoi.c ft_memalloc.c ft_putchar.c ft_strcat.c ft_striter.c \
ft_strncmp.c ft_strsub.c ft_bzero.c ft_memccpy.c ft_putchar_fd.c ft_strchr.c \
ft_striteri.c ft_strncpy.c ft_strtrim.c ft_isalnum.c ft_memchr.c ft_putendl.c \
ft_strclr.c ft_strjoin.c ft_strnequ.c ft_tolower.c ft_isalpha.c ft_memcmp.c \
ft_putendl_fd.c ft_strcmp.c ft_strlcat.c ft_strnew.c ft_toupper.c ft_isascii.c \
ft_memcpy.c ft_putnbr.c ft_strcpy.c ft_strlen.c ft_strnstr.c ft_lstnew.c \
ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_lstswap.c
OBJ=$(FILES:.c=.o)
HEAD=-I.
NAME=libft.a

all: $(NAME)

$(NAME):
	@$(CC) $(FLAGS) -c $(FILES) $(HEAD)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[0;32mLibft make all done"

clean:
	@rm -f $(OBJ)
	@echo "\033[0;32mLibft make clean done"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[0;32mLibft make fclean done"

re: fclean all
	@echo "\033[0;32mLibft make re done"
