/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 00:02:01 by meharit           #+#    #+#             */
/*   Updated: 2022/12/12 01:05:09 by meharit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
// argc == 1

#include "swap.h"
int	is_valid(char *s)
{
	if (ft_strlen(s) > 1)
		return (0);
	return (1);
}

int main(int argc, char **argv)
{
	int i;
	stk_list **stack_a;

	i = 1;
//func	stack_a = 
	while (i < argc)
	{
		if (is_valid(argv[i]))
		{
			stack_a = malloc(sizeof(stk_list));
			if (stack_a == NULL) // free list ?
				exit(0);
			stack_a->content = argv[i];
		}
		else
		{
			write(1, "Error\n", 6);
			exit (0);
		}
		i++;
		stack_a->next = NULL;
	}

