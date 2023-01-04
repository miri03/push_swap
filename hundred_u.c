/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundred_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:50:07 by meharit           #+#    #+#             */
/*   Updated: 2023/01/04 23:15:02 by meharit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	sort_b(t_list **stack_a, t_list **stack_b, int nb, int middle)
{
	t_list	*tmp;
	int		index;

	tmp = *stack_a;
	index = 0;
	while (tmp->content != nb)
	{
		index++;
		tmp = tmp->next;
	}
	while ((*stack_a)->content != nb)
	{
		if (index < ft_lstsize(*stack_a) / 2)
			rotate_a(stack_a, 0);
		else
			rev_rotate_a(stack_a, 0);
	}
	push_b(stack_a, stack_b);
	if (nb < middle)
		rotate_b(stack_b, 0);
}

int	chunk(t_list **stack_a, t_list **stack_b, list var, int *array)
{
	t_list	*tmp;

	tmp = *stack_a;
	while (tmp != NULL)
	{
		if (var.start < 0 || var.end > var.size)
		{
			while (ft_lstsize(*stack_a) > 0)
			{
				push_b(stack_a, stack_b);
				if ((*stack_b)->content < var.middle)
					rotate_b(stack_b, 0);
				return (1);
			}
		}
		if (tmp->content >= array[(var.start)] && tmp->content <= array[(var.end)])
		{
			sort_b(stack_a, stack_b, tmp->content, array[var.middle]);
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

int	max_value(t_list *stack)
{
	int		max;
	t_list	*current;

	current = stack->next;
	max = stack->content;
	while (current != NULL)
	{
		if (current->content > max)
			max  = current->content;
		current = current->next;
	}
	return (max);
}

int	next_max(t_list *stack, int max)
{
	int		 next_max;
	t_list	*current;

	if (ft_lstsize(stack) == 1)
		return (max);
	current = stack->next;
	next_max = current->content;

	while (current != NULL)
	{
		if (current->content != max && current->content > next_max)
			next_max = current->content;
		current  = current->next;
	}
	return (next_max);
}

int	is_rev_sorted(t_list *stack)
{
	t_list	*tmp;

	while (stack->next != NULL)
	{
		tmp = stack->next;
		if (stack->content < tmp->content)
			return (0);
		else
			stack = stack->next;
	}
	return (1);
}

int	ft_n(t_list *stack_a)
{
	int	size;
	int	n;

	n = 0;
	size = ft_lstsize(stack_a);
	if (size <= 150)
		n = 8;
	else if (size > 150)
		n = 18;
	return (n);
}

int	last(t_list *stack)
{
	while (stack->next != NULL)
		stack = stack->next;
	return (stack->content);
}

