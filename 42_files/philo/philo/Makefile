# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdornic <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/23 21:58:09 by gdornic           #+#    #+#              #
#    Updated: 2023/10/02 08:00:04 by gdornic          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

DEP = 

HEADERS = 

LIB_LINK = 

SRC = main.c check_arguments.c args_init.c get_time.c state_change.c init_philosopher.c usleep_extend.c eat.c simulate.c wait_for.c hold_philo.c

OBJ = $(SRC:.c=.o)

SRC_TEST = main_test.c check_arguments.c args_init.c get_time.c state_change.c init_philosopher.c usleep_extend.c eat.c simulate.c wait_for.c

OBJ_TEST = $(SRC_TEST:.c=.o)

CC = gcc

CFLAGS = -pthread -Wall -Werror -Wextra #-fsanitize=thread -g

define make_dep
	for d in $(DEP) ; do \
		make -C $$d $(1) ; \
	done
endef

all: $(NAME)

$(NAME): $(OBJ)
	$(call make_dep,all)
	$(CC) $(CFLAGS) $(OBJ) $(HEADERS) $(LIB_LINK) -o $(NAME)

test: $(OBJ_TEST)
	$(call make_dep,all)
	$(CC) $(CFLAGS) $(OBJ_TEST) $(HEADERS) $(LIB_LINK) -o generate_delay

%.o: %.c
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

clean:
	rm -f $(OBJ)
	rm -f $(OBJ_TEST)
	$(call make_dep,clean)

fclean: clean
	rm -f $(NAME)
	rm -f generate_delay
	$(call make_dep,fclean)

re: fclean all
