/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:00:43 by meharit           #+#    #+#             */
/*   Updated: 2023/01/08 21:16:10 by meharit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	sort_three(t_list **stack_a)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	first = *stack_a;
	second = (*stack_a)->next;
	third = second->next;
	if (first->content > second->content)
	{
		if (second->content > third->content)
		{
			swap_a(stack_a, 0);
			rev_rotate_a(stack_a, 0);
		}
		else
		{
			if (first->content < third->content)
				swap_a(stack_a, 0);
			else
				rotate_a(stack_a, 0);
		}
	}
	else
		sort_three_s(first, third, stack_a);
}

void	rev_or_rotate(t_list **stack_a, int min, int index)
{
	while ((*stack_a)->content != min)
	{
		if (index <= ft_lstsize(*stack_a) / 2)
			rotate_a(stack_a, 0);
		else
			rev_rotate_a(stack_a, 0);
	}
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	int		min;
	int		index;
	t_list	*tmp;

	while (ft_lstsize(*stack_a) > 3)
	{
		index = 0;
		tmp = *stack_a;
		min = min_value(*stack_a);
		while (tmp->content != min)
		{
			tmp = tmp->next;
			index++;
		}
		rev_or_rotate(stack_a, min, index);
		if (!ft_check_pb(stack_a, stack_b))
			break ;
	}
	sort_list(stack_a, stack_b);
	while (ft_lstsize(*stack_b) > 0)
		push_a(stack_a, stack_b);
}

void	sort_hundred(t_list **stack_a, t_list **stack_b)
{
	t_var_li	var;
	int			*array;

	var.size = ft_lstsize(*stack_a);
	var.middle = (var.size) / 2;
	var.offset = (var.size) / ft_n(*stack_a);
	var.start = var.middle - var.offset;
	var.end = var.middle + var.offset;
	array = array_sort(*stack_a);
	while ((*stack_a) != NULL)
	{
		while (!chunk(stack_a, stack_b, var, array))
		{
			var.start = var.start - var.offset;
			var.end = var.end + var.offset;
		}
	}
	if (is_rev_sorted(*stack_b))
	{
		while ((*stack_b) != NULL)
			push_a(stack_a, stack_b);
	}
	push_to_a(stack_a, stack_b, var, array);
	free(array);
}

void	sort_list(t_list **stack_a, t_list **stack_b)
{
	if (!is_sorted(*stack_a))
	{
		if (ft_lstsize(*stack_a) <= 3)
		{
			if (ft_lstsize(*stack_a) == 2)
				swap_a(stack_a, 0);
			else
				sort_three(stack_a);
		}
		else if (ft_lstsize(*stack_a) <= 16 && ft_lstsize(*stack_a) >= 4)
			sort_five(stack_a, stack_b);
		else if (ft_lstsize(*stack_a) > 16)
			sort_hundred(stack_a, stack_b);
	}
}
