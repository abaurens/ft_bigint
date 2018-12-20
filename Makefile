# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/20 04:12:39 by abaurens          #+#    #+#              #
#    Updated: 2018/12/20 07:36:26 by abaurens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCD	=	srcs
OBJD	=	objs
NAME	=	libbnum.a
LNK		=	ar -rc
RM		=	rm -rf
CC		=	gcc

CFLAGS	+=	-g -I./includes -I./libft/includes -W -Wall -Wextra -ansi# -pedantic

SRC		:=	bint_instance.c			\
			bint_string.c			\
			bint_utils.c			\
			bint_add.c				\
			\
			bfloat_instance.c		\
			bfloat_string.c			\
			bfloat_utils.c			\
			new_bfloat.c

OBJ		:=	$(addprefix $(OBJD)/,$(SRC:.c=.o))
SRC		:=	$(addprefix $(SRCD)/,$(SRC))

$(NAME):	$(OBJ)
	$(LNK) $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJD)/%.o:	$(SRCD)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ -c $<

test:	$(NAME) main.o
	$(CC) -o test main.o -L./ -lbnum -L./libft -lft

all:	$(NAME)

clean:
	$(RM) main.o
	$(RM) $(OBJD)

fclean:
	$(RM) main.o
	$(RM) $(OBJD)
	$(RM) $(NAME)
	$(RM) test

re:	fclean all

retest:	fclean test

.PHONY:	all clean fclean re
