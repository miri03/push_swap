/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 00:02:01 by meharit           #+#    #+#             */
/*   Updated: 2022/12/13 02:14:24 by meharit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// argc == 1

#include "swap.h"

typedef	struct	list
{
	void		*content;
	struct list	*next;
}				stk_list;

int	is_numeric(char *s)
{
	while (*s != '\0')
	{
		if (*s >= '0' && *s <= '9')
			s++;
		else
			return (0);
	}
	return (1);
}	

int	is_valid(char **s, int argc)
{
	int i;

	i = 0;
	if (argc == 0)
		return (0);
	while (i < argc)
	{
		if (is_numeric(s[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

int main(int argc, char **argv)
{
	int i;
	stk_list **stack_a;

	i = 1;
//func	stack_a =

   if (is_valid(&argv[i], argc - 1))
   {
	   while (i < argc)
	   {
			stack_a = malloc(sizeof(stk_list));
			if (stack_a == NULL) // free list ?
				exit(0);
			stack_a->content = argv[i];
		i++;
		stack_a->next = NULL;
		}
   }
   else
   {
	   write(1, "Error\n", 6);
	   exit (0);
   }
