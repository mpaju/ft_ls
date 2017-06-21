CC = gcc


SRC_FILES = main.c
SRC_FOLDER = sources/
SRCS = $(SRC_FILES)

OBJ_FILES = $(SRC_FILES:.c=.o)
OBJ_FOLDER = objects/
OBJS = $(OBJ_FILES)

NAME = ft_ls

all:
	$(CC) $(SRCS) -o $(NAME)

fclean:
	rm -rf $(NAME)

re: fclean all
