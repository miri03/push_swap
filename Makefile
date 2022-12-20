# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meharit <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/17 19:37:49 by meharit           #+#    #+#              #
#    Updated: 2022/12/18 19:19:16 by meharit          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CFLAGS = -Wall -Wextra -Werror

CFILES = push_swap.c \
		 lib.c \
		 lib1.c \
		 split.c \
		 instr.c \
		 utilit.c \

OBJ = push_swap.o \
	  lib.o \
	  lib1.o \
	  split.o \
	  instr.o \
	  utilit.o \

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
