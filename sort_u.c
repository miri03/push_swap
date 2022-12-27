/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:03:07 by meharit           #+#    #+#             */
/*   Updated: 2022/12/27 17:35:39 by meharit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

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
	return (1);
}

void	sort_three_s(t_list *first, t_list *third, t_list **stack_a)
{
	if (first->content < third->content)
	{
		rev_rotate_a(stack_a, 0);
		swap_a(stack_a, 0);
	}
	else
		rev_rotate_a(stack_a, 0);
}

void	utiliti(t_list **stack_a, t_list **stack_b)
{
	int		min;
	int		index;
	t_list	*tmp;

	index = 1;
	min = min_value(*stack_a);
	tmp = (*stack_a);
	if (ft_lstsize(*stack_a) > 3)
	{
		while (tmp->content != min)
		{
			tmp = tmp->next;
			index++;
		}
		while ((*stack_a)->content != min)
		{
			if (index <= 3)
				rotate_a(stack_a, 0);
			else
				rev_rotate_a(stack_a, 0);
		}
		push_b(stack_a, stack_b);
	}
}

int	min_value(t_list *head)
{
	int		min;
	t_list	*current;

	current = head->next;
	min = head->content;
	while (current != NULL)
	{
		if (current->content < min)
			min = current->content;
		current = current->next;
	}
	return (min);
}
