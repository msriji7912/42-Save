# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/14 09:34:34 by mosriji           #+#    #+#              #
#    Updated: 2026/02/14 15:25:33 by mosriji          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS		=	$(SRCS:.c=.o)
NAME		=	pipex
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g
INCLUDES	=	-I.
   
SRCS = parsing.c \
		tools/utils.c \
		tools/ft_split.c \
		error_bro.c

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