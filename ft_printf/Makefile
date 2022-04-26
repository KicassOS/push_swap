# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pszleper <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/18 06:18:13 by pszleper          #+#    #+#              #
#    Updated: 2022/01/12 23:56:05 by pszleper         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

FLAGS = -Wall -Wextra -Werror -c

AR = ar -rcs

SRC = ft_printf.c ft_converters.c ft_strutil.c ft_numconverters.c				\
      ft_putpointer.c

LIBFT_DEPENDENCIES = ft_strlen.o ft_strncmp.o ft_strlcpy.o

OBJECTS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS) libft.a
	$(AR) $(NAME) $(OBJECTS)
	ar -rs libftprintf.a $(LIBFT_DEPENDENCIES)

libft.a:
	cd libft && $(MAKE) && $(MAKE) clean && mv libft.a ..
	ar -x libft.a $(LIBFT_DEPENDENCIES)

%.o: %.c
	$(CC) $(FLAGS) $< -o $@

.PHONY: all clean fclean re

clean:
	rm -f *.o
	rm -f libft/*.o

fclean: clean
	rm -f libft.a
	rm -f libft.h
	rm -f $(NAME)
	rm -f libft.a
	rm -f libft.h

re: fclean all
