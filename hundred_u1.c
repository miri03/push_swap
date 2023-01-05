/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundred_u1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:58:34 by meharit           #+#    #+#             */
/*   Updated: 2023/01/05 19:06:53 by meharit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

int	is_sa(t_list **stack_a, t_list **stack_b, int *array, t_v_li vrb)
{
	int	sa;

	if ((*stack_b)->content == array[vrb.i])
	{
		push_a(stack_a, stack_b);
		sa = 1;
		return (sa);
	}
	return (0);
}

int	sa_rev_or_rotate(t_list **stack_a, t_list **stack_b, t_v_li vrb, int *array)
{
	int	max;
	int	sa;

	sa = 0;
	max = max_value(*stack_b);
	while ((*stack_b)->content != max)
	{
		if (vrb.index <= ft_lstsize(*stack_b) / 2)
		{
			if ((*stack_b)->content == array[vrb.i])
				sa = is_sa(stack_a, stack_b, array, vrb);
			else
				rotate_b(stack_b, 0);
		}
		else
		{
			if ((*stack_b)->content == array[vrb.i])
				sa = is_sa(stack_a, stack_b, array, vrb);
			else
				rev_rotate_b(stack_b, 0);
		}
	}
	return (sa);
}

void	push_to_a(t_list **stack_a, t_list **stack_b, t_var_li var, int *array)
{
	int		sa;
	t_list	*tmp;
	t_v_li	vrb;

	vrb.i = var.size - 2;
	while ((*stack_b) != NULL)
	{
		sa = 0;
		vrb.max = max_value(*stack_b);
		tmp = *stack_b;
		vrb.index = 0;
		while (tmp->content != vrb.max)
		{
			vrb.index = vrb.index + 1;
			tmp = tmp->next;
		}
		sa = sa_rev_or_rotate(stack_a, stack_b, vrb, array);
		vrb.i = vrb.i - 1;
		push_a(stack_a, stack_b);
		if (sa == 1)
		{
			swap_a(stack_a, 0);
			vrb.i = vrb.i - 1;
		}
	}
}
