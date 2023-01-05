# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meharit <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/17 19:37:49 by meharit           #+#    #+#              #
#    Updated: 2023/01/05 22:08:51 by meharit          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BNAME = checker

CFLAGS = -Wall -Wextra -Werror

CFILES = push_swap.c \
		 lib.c \
		 split.c \
		 instr.c \
		 instr1.c \
		 instr2.c \
		 utilit.c \
		 sort.c \
		 sort_u.c \
		 sort_u1.c \
		 hundred_u.c \
		 hundred_u1.c \

OBJ = push_swap.o \
	  lib.o \
	  split.o \
	  instr.o \
	  instr1.o \
	  instr2.o \
	  utilit.o \
	  sort.o \
	  sort_u.o \
	  sort_u1.o \
	  hundred_u.o \
	  hundred_u1.o

BCFILES = checker.c \


BOBJ = checker.o \


RM = rm -rf 

LIBC = ar -rc

all: $(NAME)

$(NAME): $(OBJ)
	cc $(OBJ) -o $(NAME) 

bonus : $(BNAME)

$(BNAME): $(BOBJ)
	cc $(BOBJ) -o $(BNAME)
	
clean: 
	$(RM) $(OBJ) $(BOBJ)

fclean : clean
	$(RM) $(NAME) $(BNAME)

re: fclean all
