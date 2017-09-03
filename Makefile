# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpaju <mpaju@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/20 20:38:05 by valdisemacpro     #+#    #+#              #
#    Updated: 2017/09/03 17:59:17 by mpaju            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CC = gcc
FLAGS = -Wall -Werror -Wextra

SRCS = main.c \
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
			print.c \
			free.c \
			print_long.c \
			print_long2.c \
			print_ftype_and_rights.c

OBJS = $(SRC_FILES:.c=.o)

LIB_NAME = libft.a
LIBDIR = libft/
LIB = $(addprefix $(LIBDIR), $(LIB_NAME))
LIB_FLAGS = -L$(LIBDIR) -lft -I$(LIBDIR)

NAME = ft_ls

all: $(NAME)

$(NAME):
	@make -C $(LIBDIR)
	@$(CC) $(SRCS) -o $(NAME) $(FLAGS) $(LIB_FLAGS)
	@echo "\033[0;32mFt_ls make all done"

deb:
	@make deb -C $(LIBDIR)
	@$(CC)  $(SRCS) -o $(NAME) $(FLAGS) -g $(LIB_FLAGS)
	@echo "\033[0;32mFt_ls make deb done"

clean:
	@rm -rf $(OBJS)
	@make clean -C $(LIBDIR)
	@echo "\033[0;32mFt_ls make clean done"

fclean:
	@make fclean -C $(LIBDIR)
	@rm -rf $(NAME)
	@echo "\033[0;32mFt_ls make fclean done"

re: fclean all
	@echo "\033[0;32mFt_ls make re done"
