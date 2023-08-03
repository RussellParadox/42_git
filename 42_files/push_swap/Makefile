# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdornic <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/23 21:58:09 by gdornic           #+#    #+#              #
#    Updated: 2023/08/03 14:46:21 by gdornic          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

DEP = lib42

HEADERS = -Ilib42

LIB_LINK = -Llib42 -l42 

SRC = main.c init_stack.c instructions_tools_low.c instructions_tools_low2.c instructions_tools_high.c backtrack.c printing_tools.c backtrack_tools.c backtrack_sort.c exit.c insert_sort.c statistic_tools.c quick_sort_array.c instructions_tools_high2.c gsort_3.c gsort_3_tools.c rotate_sort.c extremum.c

SRC_BONUS = checker.c checker_tools.c instructions_tools_low.c instructions_tools_low2.c instructions_tools_high.c backtrack.c printing_tools.c backtrack_tools.c backtrack_sort.c exit.c insert_sort.c statistic_tools.c quick_sort_array.c instructions_tools_high2.c gsort_3.c gsort_3_tools.c rotate_sort.c extremum.c

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

define make_dep
	for d in $(DEP) ; do \
		make -C $$d $(1) ; \
	done
endef

all: $(NAME)

bonus: $(OBJ_BONUS)
	$(call make_dep,all)
	$(CC) $(OBJ_BONUS) $(HEADERS) $(LIB_LINK) -o checker

$(NAME): $(OBJ)
	$(call make_dep,all)
	$(CC) $(OBJ) $(HEADERS) $(LIB_LINK) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJ_BONUS)
	$(call make_dep,clean)

fclean: clean
	rm -f $(NAME) checker
	$(call make_dep,fclean)

re: fclean all
