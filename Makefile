# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sidrissi <sidrissi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/16 14:52:35 by sidrissi          #+#    #+#              #
#    Updated: 2024/11/19 17:47:39 by sidrissi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Wextra -Werror
AR = ar -rc
RM = rm -f
FILES = ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_hex.c ft_p.c ft_u.c

OBJECTS = $(FILES:.c=.o)
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJECTS)

%.o: %.c ft_printf.h
	$(CC) $(FLAGS) -c $< -o $@
	$(AR) $(NAME) $@

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all