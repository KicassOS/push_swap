# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pszleper <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/05 21:57:25 by pszleper          #+#    #+#              #
#    Updated: 2022/04/05 21:57:25 by pszleper         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRC = main.c utils.c

OBJECTS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS) push_swap.h
	$(CC) $(FLAGS) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(FLAGS) $< -o $@

clean:
	rm -f *.o
	rm -f push_swap.h.gch

fclean: clean
	rm -f $(NAME)

re: fclean all
