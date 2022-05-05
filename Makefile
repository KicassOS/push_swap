# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psz <psz@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/05 21:57:25 by pszleper          #+#    #+#              #
#    Updated: 2022/05/05 18:33:09 by psz              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRC = main.c utils.c

OBJECTS = $(addprefix objects/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJECTS) push_swap.h
	$(CC) $(FLAGS) $(OBJECTS) -o $(NAME)

objects/%.o: %.c push_swap.h
	mkdir -p objects
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf objects
	rm -f push_swap.h.gch

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re