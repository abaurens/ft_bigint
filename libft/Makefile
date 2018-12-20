# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 16:08:06 by abaurens          #+#    #+#              #
#    Updated: 2018/12/13 18:04:26 by abaurens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=		libft.a

LINKER	=		ar rc

CC		=		gcc

RM		=		rm -rf

CP		=		cp

CMPT	=		0
CURUP	=		\e[1A
GRN		=		\e[1;92m
BLE		=		\e[1;34m
CYA		=		\e[1;96m
MAG		=		\e[1;35m
RED		=		\e[1;91m
NRM		=		\e[0m
LINE	=		" $(CYA)[%3d%%]\t$(BLE)%-24s $(MAG)=>$(BLE)\t%-24s$(NRM)\n"


GCC_STR	=	<---------------------- Compiling sources... ---------------------->
CLN_STR	=	<---------------------- Cleaning  sources... ---------------------->
FCL_STR	=	<---------------------- Cleaning  $(NAME)... ---------------------->
LNK_STR	=	<----------------------- Linking $(NAME)... ----------------------->
DNE_STR	=	<----------------------------- DONE ! ----------------------------->

SRC_DIR	=		srcs
OBJ_DIR	=		objs
SRC		=		ft_absolute.c			\
				ft_minimum.c			\
				ft_maximum.c			\
				ft_strmapi.c			\
				ft_strsub.c				\
				ft_freturn.c			\
				ft_strnequ.c			\
				ft_striteri.c			\
				ft_strjoin.c			\
				ft_strmap.c				\
				ft_strequ.c				\
				ft_striter.c			\
				ft_strsplit.c			\
				ft_strtrim.c			\
				ft_memalloc.c			\
				ft_strmcat.c			\
				ft_strnew.c				\
				ft_memdel.c				\
				ft_strdel.c				\
				ft_strclr.c				\
				ft_itoa.c				\
				ft_lltoa.c				\
				ft_lltoa_base.c			\
				ft_numlen.c				\
				ft_numlen_base.c		\
				ft_unsignedlen.c		\
				ft_unsignedlen_base.c	\
				ft_putnbr_base.c		\
				ft_putnbr_base_fd.c		\
				ft_isbase.c				\
				ft_putnbr.c				\
				ft_putstr.c				\
				ft_putchar.c			\
				ft_putendl.c			\
				ft_putnbr_fd.c			\
				ft_putstr_fd.c			\
				ft_putchar_fd.c			\
				ft_putendl_fd.c			\
				ft_idxof.c				\
				ft_contains.c			\
				ft_atol_base.c			\
				ft_isupper.c			\
				ft_islower.c			\
				ft_memset.c				\
				ft_bzero.c				\
				ft_memcpy.c				\
				ft_memccpy.c			\
				ft_memmove.c			\
				ft_memchr.c				\
				ft_memcmp.c				\
				ft_strlen.c				\
				ft_strdup.c				\
				ft_strcpy.c				\
				ft_strncpy.c			\
				ft_strcat.c				\
				ft_strncat.c			\
				ft_strlcat.c			\
				ft_strchr.c				\
				ft_strrchr.c			\
				ft_strstr.c				\
				ft_strnstr.c			\
				ft_strcmp.c				\
				ft_strncmp.c			\
				ft_atoi.c				\
				ft_isalpha.c			\
				ft_isdigit.c			\
				ft_isalnum.c			\
				ft_isascii.c			\
				ft_isprint.c			\
				ft_toupper.c			\
				ft_tolower.c			\
				ft_lstnew.c				\
				ft_lstdelone.c			\
				ft_lstdel.c				\
				ft_lstadd.c				\
				ft_lstiter.c			\
				ft_lstmap.c

SRCS	=		$(addprefix $(SRC_DIR)/,$(SRC))
OBJ		=		$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

INCLUDE	=		-I./includes

CFLAGS	=		$(INCLUDE) -W -Wall -Wextra -Werror -ansi

$(NAME):	$(OBJ)
	@printf "$(GRN)$(LNK_STR)$(NRM)\n"
	@$(LINKER) $(NAME) $(OBJ)
	@printf "$(MAG)ranlib $(RED)$(NAME)$(NRM)\n"
	@ranlib $(NAME)
	@printf "$(GRN)$(DNE_STR)$(NRM)\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@if [[ $(CMPT) -eq 0 ]]; then printf "$(GRN)$(GCC_STR)$(NRM)\n";\
	else printf "$(CURUP)"; fi
	$(eval FCNT	= $(words $(SRCS)))
	$(eval CMPT = $(shell echo $(CMPT) + 1 | bc))
	$(eval PRC = $(shell echo "$(CMPT) / $(FCNT) * 100" | bc -l))
	@printf $(LINE) $(shell echo $(PRC) | sed -E "s:\.[0-9]{20}::") $< $@
	@printf "\e[0m"
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -o $@ -c $<

all: $(NAME)

clean:
	@printf "$(GRN)$(CLN_STR)$(NRM)\n"
	@$(RM) $(OBJ_DIR)

fclean:	clean
	@printf "$(GRN)$(FCL_STR)$(NRM)\n"
	@$(RM) $(NAME)

space:
	@echo

re:	fclean space all

.PHONY: all clean fclean space re
