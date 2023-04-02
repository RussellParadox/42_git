# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdornic <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/23 21:58:09 by gdornic           #+#    #+#              #
#    Updated: 2023/04/01 20:49:29 by gdornic          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lib42.a

LIB = libft get_next_line libftprintf

define make_lib
	for d in $(LIB) ; do \
		make -C $$d $(1) ; \
	done
endef

define cp_header
	for d in $(LIB) ; do \
		cp $$d/$$d.h . ; \
	done
endef

all: $(NAME)

$(NAME):
	$(call make_lib,all)
	$(call cp_header)
	ar crsT $(NAME) $(join $(LIB:=/), $(LIB:=.a))

clean:
	$(call make_lib,clean)

fclean: clean
	rm -f $(NAME)
	$(call make_lib,fclean)

re: fclean all
