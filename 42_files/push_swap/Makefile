# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdornic <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/23 21:58:09 by gdornic           #+#    #+#              #
#    Updated: 2023/07/22 08:14:51 by gdornic          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

DEP = lib42

HEADERS = -Ilib42

LIB_LINK = -Llib42 -l42 

SRC = main.c init_stack.c instructions_tools_low.c instructions_tools_low2.c instructions_tools_high.c backtrack.c printing_tools.c backtrack_tools.c quick_sort.c backtrack_sort.c exit.c

SRC_BONUS = checker.c checker_tools.c init_stack.c instructions_tools_low.c instructions_tools_low2.c instructions_tools_high.c backtrack.c printing_tools.c backtrack_tools.c quick_sort.c backtrack_sort.c exit.c

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

CC = gcc

CFLAGS = -Werror -Wall -Wextra

define make_dep
	for d in $(DEP) ; do \
		make -C $$d $(1) ; \
	done
endef

all: $(NAME)

bonus: $(OBJ_BONUS)
	$(call make_dep,all)
	$(CC) $(OBJ_BONUS) $(HEADERS) $(LIB_LINK) -o checker -fsanitize=address

$(NAME): $(OBJ)
	$(call make_dep,all)
	$(CC) $(OBJ) $(HEADERS) $(LIB_LINK) -o $(NAME) -fsanitize=address

%.o: %.c
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@ -fsanitize=address

clean:
	rm -f $(OBJ) $(OBJ_BONUS)
	$(call make_dep,clean)

fclean: clean
	rm -f $(NAME) checker
	$(call make_dep,fclean)

re: fclean all
