/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilit1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:57:26 by meharit           #+#    #+#             */
/*   Updated: 2022/12/24 02:15:02 by meharit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	error(void)
{
	write (2, "Error\n", 6);
	exit(1);
}

void	free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
}

int	is_sorted(t_list *stack)
{
	t_list	*tmp;
	//int i = 0;
	printList(stack);
	while (stack->next != NULL)
	{
		printf("i\n");
	//	i++;
		tmp = stack->next;
		if (stack->content > tmp->content)
		{
			printf("not sorted\n");
			return (0);
		}
		else
			stack = stack->next;
	}
	printf("sorted\n");
	exit(0);
//	return (1);
}

//void	sort_three(t_list *stack_a)

void	sort_list(t_list *stack_a, t_list *stack_b)
{
	(void)stack_b;

	if (!is_sorted(stack_a))
	{
		printf("zbi\n");
	}





	/*
	if (ft_lstsize(stack_a) <= 3)
		sort_three(stack_a);
	else if (ft_lstsize(stack_a) == 4 || ft_lstsize(stack_a) == 5)
		sort_five(stack_a, stack_b);
	else if (ft_lstsize(stack_a) > 5 && ft_lstsize(stack_a) <= 100)
		sort_hundred(stack_a, stack_b);
	else if (ft_lstsize(stack_a) > 100 && ft_lstsize(stack_a) <= 500)
		sort_five_hundred(stack_a, stack_b);
		*/
}


