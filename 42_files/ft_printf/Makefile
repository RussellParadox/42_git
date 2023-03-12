# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdornic <gdornic@student.42perpignan.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/28 17:08:19 by gdornic           #+#    #+#              #
#    Updated: 2023/03/12 15:51:20 by gdornic          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c ft_itoa_base.c ft_chrtostr.c ft_balloc.c ft_memset_int.c ft_printf_utils.c ft_printf_utils2.c ft_itoa_base_pointer.c inclusive_strjoin.c ft_chrswap.c

LIBFT_SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

OBJ = ${SRC:.c=.o}

LIBFT_OBJ = ${LIBFT_SRC:.c=.o}

all: $(NAME)
	ar -cr $(NAME) $(OBJ) $(LIBFT_OBJ)

$(NAME):
	cd libft/ && gcc -Wall -Wextra -Werror -c $(LIBFT_SRC) && mv $(LIBFT_OBJ) ../
	gcc -Wall -Wextra -Werror -c $(SRC)

clean:
	rm -f $(OBJ) $(LIBFT_OBJ)

fclean: clean
	rm -f $(NAME)

bonus: all

re: fclean all
