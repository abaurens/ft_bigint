# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/16 02:41:41 by abaurens          #+#    #+#              #
#    Updated: 2019/01/20 19:54:42 by abaurens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	binary_bint

SRC		=	main.c	\
			srcs/utils.c			srcs/bint/bint.c	srcs/bint/print.c	\
			srcs/bint/bint_cmp.c	srcs/bint/add.c		srcs/bint/mul.c

OBJ		=	$(addprefix objs/,$(SRC:.c=.o))

CFLAGS	=	-I./includes -W -Wall -Wextra -ansi -pedantic

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ)

objs/%.o:	%.c
	@mkdir -p $(dir $@)
	gcc -o $@ -c $< $(CFLAGS)

all:	$(NAME)

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
