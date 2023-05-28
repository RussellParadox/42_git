# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdornic <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/23 21:58:09 by gdornic           #+#    #+#              #
#    Updated: 2023/05/28 16:38:28 by gdornic          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

DEP = lib42

HEADERS = -I/usr/include -Imlx_linux -Ilib42

LIB_LINK = -Lmlx_linux -lmlx_Linux -Llib42 -l42 -L/usr/lib -lXext -lX11 -lm -lz

SRC = main.c map.c window.c projection.c color.c segment.c init.c vector_math.c map_utility.c

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra

define make_dep
	for d in $(DEP) ; do \
		make -C $$d $(1) ; \
	done
endef

all: $(NAME)

$(NAME): $(OBJ)
	$(call make_dep,all)
	$(CC) $(OBJ) $(HEADERS) $(LIB_LINK) -o $(NAME) -g

%.o: %.c
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@ -g

clean:
	rm -f $(OBJ)
	$(call make_dep,clean)

fclean: clean
	rm -f $(NAME)
	$(call make_dep,fclean)

re: fclean all
