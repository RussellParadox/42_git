# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdornic <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/23 21:58:09 by gdornic           #+#    #+#              #
#    Updated: 2023/10/11 20:08:05 by gdornic          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

DEP = 

HEADERS = 

LIB_LINK = 

SRC = main_test.c check_arguments.c args_init.c get_time.c watcher.c

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -pthread #-Wall -Werror -Wextra #-fsanitize=thread -g

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
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(call make_dep,clean)

fclean: clean
	rm -f $(NAME)
	$(call make_dep,fclean)

re: fclean all
