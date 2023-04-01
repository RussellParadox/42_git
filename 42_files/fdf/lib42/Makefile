# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdornic <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/23 21:58:09 by gdornic           #+#    #+#              #
#    Updated: 2023/04/01 18:18:13 by gdornic          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lib42.a

LIB = libft get_next_line

define make_lib
	for d in $(LIB) ; do \
		make -C $$d $(1) ; \
	done
endef

all: $(NAME)

$(NAME):
	$(call make_lib,all)
	ar crsT $(NAME) $(join $(LIB:=/), $(LIB:=.a))

clean:
	$(call make_lib,clean)

fclean: clean
	rm -f $(NAME)
	$(call make_lib,fclean)

re: fclean all
