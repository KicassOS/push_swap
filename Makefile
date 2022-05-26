# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pszleper < pszleper@student.42.fr >        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/05 21:57:25 by pszleper          #+#    #+#              #
#    Updated: 2022/05/26 18:29:39 by pszleper         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRC = main.c utils.c

OBJECTS = $(addprefix objects/, $(SRC:.c=.o))

HEADER = push_swap.h

all: $(NAME)

$(NAME): libft.a $(OBJECTS) $(HEADER)
	$(CC) $(FLAGS) $(OBJECTS) libft.a $(HEADER) -o $(NAME)

libft.a:
	make -C ./Libft
	mv ./Libft/libft.a .

objects/%.o: %.c push_swap.h
	mkdir -p objects
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf objects
	rm -f push_swap.h.gch

fclean: clean
	rm -f libft.a
	rm -f $(NAME)
	make -C ./Libft fclean

re: fclean all

.PHONY: all clean fclean re