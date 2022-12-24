# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meharit <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/17 19:37:49 by meharit           #+#    #+#              #
#    Updated: 2022/12/23 17:31:32 by meharit          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CFLAGS = -Wall -Wextra -Werror

CFILES = push_swap.c \
		 lib.c \
		 lib1.c \
		 split.c \
		 instr.c \
		 instr1.c \
		 instr2.c \
		 utilit.c \
		 utilit1.c \

OBJ = push_swap.o \
	  lib.o \
	  lib1.o \
	  split.o \
	  instr.o \
	  instr1.o \
	  instr2.o \
	  utilit.o \
	  utilit1.o \

RM = rm -rf 

LIBC = ar -rc

all: $(NAME)

$(NAME): $(OBJ)
	cc $(OBJ) -o $(NAME)

clean: 
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re: fclean all
