# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/16 02:41:41 by abaurens          #+#    #+#              #
#    Updated: 2019/01/22 21:00:26 by abaurens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	binary_bint

SRC		=	main.c	\
			srcs/utils.c			srcs/bint/bint.c	srcs/bint/print.c	\
			srcs/bint/bint_cmp.c	srcs/bint/add.c		srcs/bint/mul.c		\
			srcs/bint/pow.c			srcs/bint/div.c		srcs/bint/shift.c	\
			srcs/bint/sub.c

OBJ		=	$(addprefix objs/,$(SRC:.c=.o))

CFLAGS	=	-g -I./includes -W -Wall -Wextra -ansi -pedantic

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ)

objs/%.o:	%.c
	@mkdir -p $(dir $@)
	gcc -o $@ -c $< $(CFLAGS)

all:	$(NAME)

clean:
	rm -rf $(OBJ)
	rm -rf ./objs

fclean:	clean
	rm -rf $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
