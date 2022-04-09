# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psz <psz@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/05 21:57:25 by pszleper          #+#    #+#              #
#    Updated: 2022/04/10 01:09:41 by psz              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRC = main.c utils.c 

OBJ = $(SRC:.o=.c)

HEADER = push_swap.h

all: $(NAME)

$(NAME): OBJ
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

utils.c:    $(HEADER)
main.c:     $(HEADER)

clean:
	rm -f *.o
	rm -f push_swap.h.gch

fclean: clean
	rm -f $(NAME)
	rm 

re: fclean all
