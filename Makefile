# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pszleper < pszleper@student.42.fr >        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/05 21:57:25 by pszleper          #+#    #+#              #
#    Updated: 2023/01/07 18:08:37 by pszleper         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BONUS_NAME = checker

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRC = case_calculation_1.c case_calculation_2.c error_checking.c exit.c \
      push_swap.c rotation_types.c sort.c stack_management.c            \
      stack_operations_1.c stack_operations_2.c stack_operations_3.c    \
	  stack_utils_1.c stack_utils_2.c applied_operations.c utils_1.c    \
	  utils_2.c ft_split_whitespace_2.c

SRC_BONUS = checker.c checker_utils_1.c

OBJECTS = $(addprefix objects/, $(SRC:.c=.o))

OBJECTS_BONUS = $(addprefix objects/, $(SRC_BONUS:.c=.o))

HEADER = push_swap.h

all: $(NAME)

$(NAME): libft.a $(OBJECTS) $(HEADER)
	$(CC) $(FLAGS) $(OBJECTS) libft.a $(HEADER) -o $(NAME)

bonus: $(NAME) libft.a $(OBJECTS) $(OBJECTS_BONUS) $(HEADER)
	$(CC) $(FLAGS) $(OBJECTS_BONUS) libft.a $(HEADER) -o $(BONUS_NAME)

libft.a:
	make -C ./libft
	mv ./libft/libft.a .

objects/%.o: %.c push_swap.h
	mkdir -p objects
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf objects
	rm -f push_swap.h.gch

fclean: clean
	rm -f libft.a
	rm -f $(NAME)
	make -C ./libft fclean

re: fclean all

.PHONY: all clean fclean re