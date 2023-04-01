# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdornic <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/23 21:58:09 by gdornic           #+#    #+#              #
#    Updated: 2023/04/01 16:46:14 by gdornic          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

DEP =

HEADERS =

LIB_LINK =

SRC = 

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
	ar -cr $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) $(HEADERS) -O3 -c $< -o $@

clean:
	rm -f $(OBJ)
	$(call make_dep,clean)

fclean: clean
	rm -f $(NAME)
	$(call make_dep,fclean)

re: fclean all
