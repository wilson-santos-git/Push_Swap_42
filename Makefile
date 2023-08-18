# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/04 16:40:09 by wteles-d          #+#    #+#              #
#    Updated: 2023/08/18 17:19:07 by wteles-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ps

SRCS	=	$(wildcard *.c)

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