# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/28 21:41:24 by jonkim            #+#    #+#              #
#    Updated: 2017/11/06 12:46:53 by jonkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main.c           \
	  ft_blocks.c      \
	  ft_board.c       \
	  ft_check_valid.c \
	  ft_error.c       \
	  ft_fill.c        \
	  ft_stuff.c       \
	  ft_stuffs.c

OBJ = $(SRC:.c=.o)
HEADER = fillit.h
FLAGS = -Wall -Wextra -Werror

.PHONY: all fclean clean re

all: $(NAME)

$(NAME): $(OBJ)
	@gcc $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	@gcc -c $(FLAGS) $^ -o $@

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
