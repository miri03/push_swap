# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meharit <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/17 19:37:49 by meharit           #+#    #+#              #
#    Updated: 2022/12/18 00:02:17 by meharit          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CFLAGS = -Wall -Wextra -Werror

CFILES = push_swap.c \
		 lib.c \
		 1lib.c \
		 2lib.c \

OBJ = push_swap.o \
	  lib.o \
	  1lib.o \
	  2lib.o \

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
