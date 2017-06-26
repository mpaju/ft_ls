CC = gcc


SRC_FILES = main.c \
			get_args.c
SRC_FOLDER = sources/
SRCS = $(SRC_FILES)

OBJ_FILES = $(SRC_FILES:.c=.o)
OBJ_FOLDER = objects/
OBJS = $(OBJ_FILES)

LIB_NAME = libft.a
LIB_FOLDER = libft/
LIB = $(addprefix $(LIB_FOLDER), $(LIB_NAME))
LIB_FLAGS = -L$(LIB_FOLDER) -lft -I$(LIB_FOLDER)

NAME = ft_ls

all:
	@make -C $(LIB_FOLDER)
	@$(CC) $(SRCS) -o $(NAME) $(LIB_FLAGS)

clean:
	@make clean -C $(LIB_FOLDER)
fclean:
	@make fclean -C $(LIB_FOLDER)
	@rm -rf $(NAME)

re: fclean all
	@echo "\033[0;32mFt_ls make re done"
