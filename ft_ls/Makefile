# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkinnear <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/15 12:38:32 by mkinnear          #+#    #+#              #
#    Updated: 2017/10/08 15:38:29 by mkinnear         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRCS= final.c \
			ft_arg.c \
			add_free.c \
			ft_rec_vert.c \
			ft_sort.c \
			horizontal.c \
	    	looper.c \
			relo_rela.c \
			vertical.c \
			ver_sort.c

OBJ= $(SRC.c=.o)

LIBFT_PATH = libft/

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_PATH)
	@gcc $(FLAGS) $(SRCS) -L $(LIBFT_PATH) -lft -o $(NAME)
	@echo "\033[32m\033[1;32m$(NAME)\033[1;0m\033[32m Successfully created.\033[0m"

clean:
	@make -C $(LIBFT_PATH)/ clean

fclean: clean
	@make -C $(LIBFT_PATH)/ fclean
	@/bin/rm -rf $(NAME)
	@echo "\033[31m\033[1;31m$(NAME)\033[1;0m\033[31m removed.\033[0m"

re: fclean all

.PHONY: all, clean, fclean, re
