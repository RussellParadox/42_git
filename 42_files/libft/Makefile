# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdornic <gdornic@student.42perpignan.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/01 16:56:21 by gdornic           #+#    #+#              #
#    Updated: 2023/02/02 09:27:46 by gdornic          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

all: $(NAME)
	ar -cr $(NAME) *.o

$(NAME):
	gcc -c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
