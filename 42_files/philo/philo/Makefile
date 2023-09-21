# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdornic <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/23 21:58:09 by gdornic           #+#    #+#              #
#    Updated: 2023/09/21 17:46:44 by gdornic          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

DEP = 

HEADERS = 

LIB_LINK = 

SRC = main.c check_arguments.c args_init.c get_time.c state_change.c init_philosopher.c

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -pthread -Wall -Werror -Wextra

define make_dep
	for d in $(DEP) ; do \
		make -C $$d $(1) ; \
	done
endef

all: $(NAME)

$(NAME): $(OBJ)
	$(call make_dep,all)
	$(CC) $(CFLAGS) $(OBJ) $(HEADERS) $(LIB_LINK) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(HEADERS) -O3 -c $< -o $@

clean:
	rm -f $(OBJ)
	$(call make_dep,clean)

fclean: clean
	rm -f $(NAME)
	$(call make_dep,fclean)

re: fclean all