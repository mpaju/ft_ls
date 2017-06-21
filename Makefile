CC = gcc


SRC_FILES = main.c
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
	@echo "\033[0;32mFt_ls make all done"

clean:
	@make clean -C $(LIB_FOLDER)
	@echo "\033[0;32mFt_ls make clean done"
fclean:
	@make fclean -C $(LIB_FOLDER)
	@rm -rf $(NAME)
	@echo "\033[0;32mFt_ls make fclean done"

re: fclean all
	@make re -C $(LIB_FOLDER)
	@echo "\033[0;32mFt_ls make re done"
