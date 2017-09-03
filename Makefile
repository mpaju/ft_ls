# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpaju <mpaju@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/20 20:38:05 by valdisemacpro     #+#    #+#              #
#    Updated: 2017/09/03 15:05:22 by mpaju            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CC = gcc


SRC_FILES = main.c \
			process_args.c \
			process_flags.c \
			errors.c \
			filename_ops.c \
			ft_ls.c\
			first_args_printing.c \
			first_sort.c \
			sort.c \
			sort_help.c \
			tfile_ops.c \
			tdir_ops.c \
			tmp_print.c \
			free.c \
			print_long.c \
			print_long2.c \
			print_ftype_and_rights.c
SRCDIR = sources/
SRCS = $(SRC_FILES)

OBJ_FILES = $(SRC_FILES:.c=.o)
OBJDIR = objects/
OBJS = $(OBJ_FILES)

LIB_NAME = libft.a
LIBDIR = libft/
LIB = $(addprefix $(LIBDIR), $(LIB_NAME))
LIB_FLAGS = -L$(LIBDIR) -lft -I$(LIBDIR)

NAME = ft_ls

all: $(NAME)

$(NAME):
	@make -C $(LIBDIR)
	@$(CC) $(SRCS) -o $(NAME) $(LIB_FLAGS)

deb:
	@make deb -C $(LIBDIR)
	@$(CC)  $(SRCS) -o $(NAME) -g $(LIB_FLAGS)

clean:
	@rm -rf $(OBJS)
	@make clean -C $(LIBDIR)

fclean:
	@make fclean -C $(LIBDIR)
	@rm -rf $(NAME)

re: fclean all
	@echo "\033[0;32mFt_ls make re done"	
