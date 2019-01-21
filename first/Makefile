# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/20 04:12:39 by abaurens          #+#    #+#              #
#    Updated: 2018/12/30 19:56:15 by abaurens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCD	=	srcs
OBJD	=	objs
NAME	=	libbnum.a
LNK		=	ar -rc
RM		=	rm -rf
CC		=	gcc

CFLAGS	+=	-g -I./includes -I./libft/includes -W -Wall -Wextra -ansi# -pedantic

SRC		:=	cast.c					\
			digit_converter.c		\
			\
			bint/instance.c			\
			bint/string.c			\
			bint/utils.c			\
			bint/add.c				\
			bint/set.c				\
			bint/mul.c				\
			\
			bfloat/instance.c		\
			bfloat/string.c			\
			bfloat/utils.c			\
			bfloat/add.c			\
			bfloat/mul.c			\
			bfloat/set2.c

OBJ		:=	$(addprefix $(OBJD)/,$(SRC:.c=.o))
SRC		:=	$(addprefix $(SRCD)/,$(SRC))

$(NAME):	$(OBJ) libft/libft.a
	$(LNK) $(NAME) $(OBJ)
	@ranlib $(NAME)

libft/libft.a:
	make -C libft/

$(OBJD)/%.o:	$(SRCD)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ -c $<

test:	$(NAME) main.o
	$(CC) -o test main.o -L./ -lbnum -L./libft -lft

all:	$(NAME)

clean:
	$(RM) main.o
	$(RM) $(OBJD)

cleanl:
	make -C libft/ clean

fclean:
	$(RM) main.o
	$(RM) $(OBJD)
	$(RM) $(NAME)
	$(RM) test

fcleanl:
	make -C libft/ fclean
re:	fcleanl fclean all

retest:	fclean test

.PHONY:	all clean fclean re
