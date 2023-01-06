/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilits_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 22:04:32 by meharit           #+#    #+#             */
/*   Updated: 2023/01/06 15:55:35 by meharit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	push_a_bonus(t_list **stack_a, t_list **stack_b, int pa)
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
    if (pa == 0)
	    write(1, "pa\n", 3);
}

void	push_b_bonus(t_list **stack_a, t_list **stack_b, int pb)
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
    if (pb == 0)
	    write(1, "pb\n", 3);
}
