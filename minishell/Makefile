# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkinnear <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/14 10:39:57 by mkinnear          #+#    #+#              #
#    Updated: 2017/12/15 01:57:33 by mkinnear         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	src/minishell1.c \
		src/env.c \
		src/path.c \
		src/exec.c \
		src/args.c \
		src/options.c \
		src/io.c \
		src/io_pipe.c \
		src/io_redirect.c \
		src/cmds/cd.c \
		src/cmds/setenv.c \
		src/cmds/unsetenv.c \
		src/cmds/env.c \
		src/cmds/exit.c \
		src/arraymy/my_add_to_array.c \
		src/arraymy/my_array_from_array.c \
		src/arraymy/my_remove_from_array.c \
		src/arraymy/my_split_string.c \
		src/arraymy/my_print_array.c \
		src/arraymy/my_free_array.c \
		src/arraymy/my_array_length.c \
		src/libft/my_putchar.c \
		src/libft/my_putstr.c \
		src/libft/my_puterror.c \
		src/libft/my_strcat.c \
		src/libft/my_strlen.c \
		src/libft/my_strcpy.c \
		src/libft/my_strncpy.c \
		src/libft/my_strncat.c \
		src/libft/my_strncmp.c \
		src/libft/my_strcmp.c \
		src/libft/merge_strings.c \
		src/libft/my_getnbr.c

CFLAGS	+=	-Wall -Werror
CFLAGS	+=	-pedantic -Wextra
CFLAGS	+=	-I./include

NAME	=	minishell

OBJS	=	$(SRCS:.c=.o)

CC	=	cc

RM	=	rm -f


all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		re all fclean clean
