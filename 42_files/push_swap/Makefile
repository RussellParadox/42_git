# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdornic <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/23 21:58:09 by gdornic           #+#    #+#              #
#    Updated: 2023/07/02 15:30:36 by gdornic          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

DEP = lib42

HEADERS = -Ilib42

LIB_LINK = -Llib42 -l42 

SRC = main.c init_stack.c instructions_tools_low.c instructions_tools_high.c insert_sort.c quick_sort.c

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
	$(CC) $(OBJ) $(HEADERS) $(LIB_LINK) -o $(NAME) -g -fsanitize=address

%.o: %.c
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@ -g

clean:
	rm -f $(OBJ)
	$(call make_dep,clean)

fclean: clean
	rm -f $(NAME)
	$(call make_dep,fclean)

re: fclean all
