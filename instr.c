/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:15:21 by meharit           #+#    #+#             */
/*   Updated: 2023/01/06 13:15:23 by meharit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	swap_a(t_list **stack_a, int ss)
{
	t_list	*second;
	int		tmp;

	if (ft_lstsize(*stack_a) > 1)
	{
		tmp = (*stack_a)->content;
		second = (*stack_a)->next;
		(*stack_a)->content = second->content;
		second->content = tmp;
	}
	if (ss == 0)
		write(1, "sa\n", 3);
}

void	swap_b(t_list **stack_b, int ss)
{
	t_list	*second;
	int		tmp;

	if (ft_lstsize(*stack_b) > 1)
	{
		tmp = (*stack_b)->content;
		second = (*stack_b)->next;
		(*stack_b)->content = second->content;
		second->content = tmp;
	}
	if (ss == 0)
		write(1, "sb\n", 3);
}

void	swap_a_b(t_list *stack_a, t_list *stack_b, int ss)
{
	swap_a(&stack_a, 1);
	swap_b(&stack_b, 1);
	if (ss == 0)
		write(1, "ss\n", 3);
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;

	if (ft_lstsize(*stack_a) > 0)
	{
		tmp_a = (*stack_a)->next;
		tmp_b = *stack_b;
		*stack_b = *stack_a;
		(*stack_b)->next = tmp_b;
		*stack_a = tmp_a;
	}
	write(1, "pb\n", 3);
}

void	push_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;

	if (ft_lstsize(*stack_b) > 0)
	{
		tmp_b = (*stack_b)->next;
		tmp_a = *stack_a;
		*stack_a = *stack_b;
		(*stack_a)->next = tmp_a;
		*stack_b = tmp_b;
	}
	write(1, "pa\n", 3);
}
