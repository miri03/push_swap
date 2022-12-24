/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilit1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:57:26 by meharit           #+#    #+#             */
/*   Updated: 2022/12/24 16:51:38 by meharit          ###   ########.fr       */
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

	while (stack->next != NULL)
	{
		tmp = stack->next;
		if (stack->content > tmp->content)
			return (0);
		else
			stack = stack->next;
	}
	exit(0);
}

void	sort_three_s(t_list *first, t_list *third, t_list *stack_a)
{
	if (first->content < third->content)
	{
		rev_rotate_a(&stack_a, 0);
		swap_a(stack_a, 0);
	}
	else
		rev_rotate_a(&stack_a, 0);
}


void	sort_three(t_list *stack_a)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	first = stack_a;
	second = stack_a->next;
	third = second->next;
	if (first->content > second->content)
	{
		if (second->content > third->content)
		{
			swap_a(stack_a, 0);
			rev_rotate_a(&stack_a, 0);
		}
		else
		{
			if (first->content < third->content)
				swap_a(stack_a, 0);
			else
				rotate_a(&stack_a,0);
		}
	}
	else
		sort_three_s(first, third, stack_a);
}

void	sort_list(t_list *stack_a, t_list *stack_b)
{
	(void)stack_b;

	if (!is_sorted(stack_a))
	{
		if (ft_lstsize(stack_a) <= 3)
		{
			if (ft_lstsize(stack_a) == 2)
				swap_a(stack_a, 0);
			else
				sort_three(stack_a);
		}
	/*	else if (ft_lstsize(stack_a) == 4 || ft_lstsize(stack_a) == 5)
			sort_five(stack_a, stack_b);
		else if (ft_lstsize(stack_a) > 5 && ft_lstsize(stack_a) <= 100)
			sort_hundred(stack_a, stack_b);
		else if (ft_lstsize(stack_a) > 100 && ft_lstsize(stack_a) <= 500)
			sort_five_hundred(stack_a, stack_b);
			*/
	}
}

