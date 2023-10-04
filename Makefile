# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/04 16:40:09 by wteles-d          #+#    #+#              #
#    Updated: 2023/10/04 14:52:58 by wteles-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

SRCS	=	find_best_number.c	find_best_utils.c	new_argv.c		\
			list_utils.c		list_utils_2.c		list_utils_3.c	\
			p_moves.c			r_moves.c			s_moves.c		\
			rr_moves.c			push_swap.c			split.c			\
			sorting_alg.c
			

CC	=	cc

FLAGS	=	-Wall -Werror -Wextra -fPIE -g #-fsanitize=address

%.o: %.c
	$(CC) $(FLAGS) -c $^ -o $@
all: $(NAME)

$(NAME):
	$(MAKE) -C 42_Libft-master
	$(CC) $(FLAGS) $(SRCS) 42_Libft-master/libft.a -o $(NAME)

clean:
	$(MAKE) -C 42_Libft-master clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C 42_Libft-master fclean

re: fclean all

.PHONY: all clean fclean re