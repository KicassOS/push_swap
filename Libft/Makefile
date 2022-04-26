# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pszleper <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 18:55:10 by pszleper          #+#    #+#              #
#    Updated: 2021/12/15 21:16:18 by pszleper         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

AR = ar -rcs

FLAGS = -Wall -Wextra -Werror -c

NAME = libft.a

SRC	=	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c	\
		ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c			\
		ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c		\
		ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c		\
		ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c			\
		ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c		\
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

EXTRA = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c				\
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c			\
		ft_lstmap.c

OBJECTS = $(SRC:.c=.o)

BONUS_OBJECTS = $(EXTRA:.c=.o)

HEADER = libft.h

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) $(FLAGS) $< -o $@

ft_strlen.o:		$(HEADER)
ft_memset.o:		$(HEADER)
ft_bzero.o:			$(HEADER)
ft_memcpy.o:		$(HEADER)
ft_memmove.o:		$(HEADER)
ft_strlcpy.o:		$(HEADER)
ft_strlcat.o:		$(HEADER)
ft_strchr.o:		$(HEADER)
ft_strrchr.o:		$(HEADER)
ft_strncmp.o:		$(HEADER)
ft_memchr.o:		$(HEADER)
ft_memcmp.o:		$(HEADER)
ft_strnstr.o:		$(HEADER)
ft_atoi.o:			$(HEADER)
ft_calloc.o:		$(HEADER)
ft_strdup.o:		$(HEADER)
ft_substr.o:		$(HEADER)
ft_strjoin.o:		$(HEADER)
ft_strtrim.o:		$(HEADER)
ft_split.o:			$(HEADER)
ft_itoa.o:			$(HEADER)
ft_strmapi.o:		$(HEADER)
ft_striteri.o:		$(HEADER)
ft_putchar_fd.o:	$(HEADER)
ft_putstr_fd.o:		$(HEADER)
ft_putendl_fd.o:	$(HEADER)
ft_putnbr_fd.o:		$(HEADER)
ft_lstnew.o:		$(HEADER)
ft_lstadd_front.o:	$(HEADER)
ft_lstsize.o:		$(HEADER)
ft_lstlast.o:		$(HEADER)
ft_lstadd_back.o:	$(HEADER)
ft_lstdelone.o:		$(HEADER)
ft_lstclear.o:		$(HEADER)
ft_lstiter.o:		$(HEADER)
ft_lstmap.o:		$(HEADER)

.PHONY: all clean fclean re

bonus: $(NAME) $(BONUS_OBJECTS)
	ar -rs $(NAME) $(BONUS_OBJECTS)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all