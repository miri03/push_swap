/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:04:19 by meharit           #+#    #+#             */
/*   Updated: 2022/12/22 21:42:54 by meharit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"swap.h"

t_list	*ft_newlast(t_list	*stack)
{
	t_list	*tmp;

	while (stack->next != NULL)
	{
		stack = stack->next;
		tmp = stack->next;
		if (tmp->next == NULL)
			return (stack);
	}
	return (NULL);
}

void	rev_rotate(t_list **stack_a, t_list **stack_b)
{
	rev_rotate_a(stack_a, 1);
	rev_rotate_b(stack_b, 1);
	write(1, "rrr\n", 4);
}
