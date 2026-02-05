# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/03 07:46:37 by mosriji           #+#    #+#              #
#    Updated: 2026/02/05 11:25:22 by mosriji          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS		=	$(SRCS:.c=.o)
NAME		=	push_swap
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
INCLUDES	=	-I.

SRCS		= stack/parsing.c \
				stack/stack_fill.c \
				tools/errors.c \
				tools/ft_split.c \
				tools/long_range.c \
				tools/parsing_utils.c \
				main.c

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re