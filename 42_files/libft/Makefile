# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdornic <gdornic@student.42perpignan.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/01 16:56:21 by gdornic           #+#    #+#              #
#    Updated: 2023/02/01 17:20:39 by gdornic          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

all: $(NAME)
	ar -cr $(NAME) *.o

$(NAME):
	gcc -c *.c

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
