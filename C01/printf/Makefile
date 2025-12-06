# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/21 23:25:07 by mosriji           #+#    #+#              #
#    Updated: 2025/12/06 08:34:12 by mosriji          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c\
		ft_print_char.c\
		ft_print_str.c\
		ft_print_putnbr.c\
		ft_print_adress.c\
		ft_print_positif_putnbr.c\
		ft_print_hexa.c\
		ft_print_up_hexa.c\
		ft_hexa_ptr.c\

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

INCLUDES = -I.

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
