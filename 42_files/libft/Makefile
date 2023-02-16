# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdornic <gdornic@student.42perpignan.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/01 16:56:21 by gdornic           #+#    #+#              #
#    Updated: 2023/02/16 20:17:20 by gdornic          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

OBJ = ${SRC:.c=.o}

BONUS_SRC = ft_lstnew.c ft_lstadd_front.c

BONUS_OBJ = ${BONUS_SRC:.c=.o}

all: $(NAME)
	ar -cr $(NAME) $(OBJ)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRC)

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

bonus:
	gcc -Wall -Wextra -Werror -c $(BONUS_SRC)
	ar -cr $(NAME) $(BONUS_OBJ)

re: fclean all bonus
