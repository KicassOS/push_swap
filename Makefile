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

%.o: %.c
	$(CC) $(FLAGS) $< -o $@

all: $(NAME)

clean:
	rm -f *.o
	rm -f push_swap.h.gch

fclean: clean
	rm -f $(NAME)
	rm 

re: fclean all
