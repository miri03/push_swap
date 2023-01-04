/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:00:43 by meharit           #+#    #+#             */
/*   Updated: 2023/01/04 23:25:31 by meharit          ###   ########.fr       */
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
		while ((*stack_a)->content != min)
		{
			if (index <= ft_lstsize(*stack_a) / 2)
				rotate_a(stack_a, 0);
			else
				rev_rotate_a(stack_a, 0);
		}
		if (!ft_check_pb(stack_a, stack_b))
			break ;
	}
	sort_list(stack_a, stack_b);
	while (ft_lstsize(*stack_b) >= 1)
		push_a(stack_a, stack_b);
}

void	push_to_a(t_list **stack_a, t_list **stack_b, list var, int *array)
{
	int		i;
	int		sa;
	int		max;
	t_list	*tmp;
	int		index;

	i = var.size - 2;
	while ((*stack_b) != NULL)
	{
		sa = 0;
//		printf("array=%d\n", array[i]);
		max = max_value(*stack_b);
		tmp = *stack_b;
		index = 0;
		while (tmp->content != max)
		{
			index++;
			tmp = tmp->next;
		}
		while ((*stack_b)->content != max)
		{
			if (index <= ft_lstsize(*stack_b) / 2)
			{
				if ((*stack_b)->content == array[i])
				{
					push_a(stack_a, stack_b);
					sa = 1;
				}
				else
				rotate_b(stack_b, 0);
			}
			else
			{
				if ((*stack_b)->content == array[i])
				{
					push_a(stack_a, stack_b);
					sa = 1;
				}
				else
				rev_rotate_b(stack_b, 0);
			}
		}
		i--;
		push_a(stack_a, stack_b);
		if (sa == 1)
		{
		//	printf("OK\n\n");
			swap_a(stack_a, 0);
			i--;
		}
		
	}
}

void	sort_hundred(t_list **stack_a, t_list **stack_b)
{
	list	var;
	int		*array;

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
	//	printList(*stack_b);

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
		else if (ft_lstsize(*stack_a) <= 16 && ft_lstsize(*stack_a)  >= 4)
			sort_five(stack_a, stack_b);
		else if (ft_lstsize(*stack_a) > 16 && ft_lstsize(*stack_a) <= INT_MAX)
			sort_hundred(stack_a, stack_b);
		/*
		else if (ft_lstsize(stack_a) > 100 && ft_lstsize(stack_a) <= 500)
			sort_five_hundred(stack_a, stack_b);
			*/
	}
}

