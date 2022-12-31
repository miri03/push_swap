/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:02:38 by meharit           #+#    #+#             */
/*   Updated: 2022/12/31 09:10:00 by meharit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	rotate_a(t_list **stack_a, int rr)
{
	t_list	*tmp;

	if (ft_lstsize(*stack_a) > 0)
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		tmp->next = NULL;
		ft_lstadd_back(stack_a, tmp);
	}
	if (rr == 0)
		write(1, "ra\n", 3);
}

void	rotate_b(t_list **stack_b, int rr)
{
	t_list	*tmp;

	if (ft_lstsize(*stack_b) > 0)
	{
		tmp = *stack_b;
		*stack_b = (*stack_b)->next;
		tmp->next = NULL;
		ft_lstadd_back(stack_b, tmp);
	}
	if (rr == 0)
		write(1, "rb\n", 3);
}

void	rotate_a_b(t_list **stack_a, t_list **stack_b)
{
	rotate_a(stack_a, 1);
	rotate_b(stack_b, 1);
	write(1, "rr\n", 3);
}

void	rev_rotate_a(t_list **stack_a, int rrr)
{
	t_list	*last;
	t_list	*new_last;

	if (ft_lstsize(*stack_a) > 1)
	{
		if (ft_lstsize(*stack_a) == 2)
		{
			swap_a(stack_a, 1);
		}
		else
		{
			last = ft_lstlast(*stack_a);
			new_last = ft_newlast(*stack_a);
			new_last->next = NULL;
			ft_lstadd_front(stack_a, last);
		}
	}
	if (rrr == 0)
		write(1, "rra\n", 4);
}

void	rev_rotate_b(t_list **stack_b, int rrr)
{
	t_list	*last;
	t_list	*new_last;

	if (ft_lstsize(*stack_b) > 1)
	{
		if (ft_lstsize(*stack_b) == 2)
			swap_b(*stack_b, 1);
		else
		{
			last = ft_lstlast(*stack_b);
			new_last = ft_newlast(*stack_b);
			new_last->next = NULL;
			ft_lstadd_front(stack_b, last);
		}
	}
	if (rrr == 0)
		write(1, "rrb\n", 4);
}
