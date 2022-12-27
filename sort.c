/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:00:43 by meharit           #+#    #+#             */
/*   Updated: 2022/12/27 17:38:17 by meharit          ###   ########.fr       */
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

int	ft_check_pb(t_list **stack_a, t_list **stack_b)
{
	if (!is_sorted(*stack_a))
	{
		push_b(stack_a, stack_b);
		return (1);
	}	
	return (0);
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	int		min;
	t_list	*tmp;
	int		index;

	index = 1;
	min = min_value(*stack_a);
	tmp = *stack_a;
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
	if (!ft_check_pb(stack_a, stack_b))
		return ;
	utiliti(stack_a, stack_b);
	sort_list(stack_a, stack_b);
	while (ft_lstsize(*stack_b) >= 1)
		push_a(stack_a, stack_b);
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
		else if (ft_lstsize(*stack_a) == 4 || ft_lstsize(*stack_a) == 5)
			sort_five(stack_a, stack_b);
		/*
		else if (ft_lstsize(stack_a) > 5 && ft_lstsize(stack_a) <= 100)
			sort_hundred(stack_a, stack_b);
		else if (ft_lstsize(stack_a) > 100 && ft_lstsize(stack_a) <= 500)
			sort_five_hundred(stack_a, stack_b);
			*/
	}
}
