# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igomez-p <igomez-p@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/17 20:15:03 by igomez-p          #+#    #+#              #
#    Updated: 2021/12/13 13:52:29 by igomez-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC =	push_swap.c \
		src/algorithm.c		\
		src/checker.c		\
		src/management.c 	\
		src/operations.c 	\
		src/instructions.c	\
		src/rotates.c		\
		src/utils.c			\
		libft/ft_split.c			\
		libft/str_functions.c 		\
		libft/number_functions.c 	\
		libft/mem_functions.c		\

OBJ = $(SRC:.c=.o)

%.o: %.c
	gcc -Wall -Werror -Wextra -g -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
		gcc -Wall -Werror -Wextra -g $(OBJ) -o $(NAME)

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)

re : fclean all
