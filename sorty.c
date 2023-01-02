/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:00:43 by meharit           #+#    #+#             */
/*   Updated: 2023/01/02 01:21:53 by meharit          ###   ########.fr       */
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

int	ft_n(t_list *stack_a)
{
	int	size;
	int	n;

	n = 0; //
	size = ft_lstsize(stack_a);
	if (size <= 10)
		n = 5;
	else if (size <= 150)
		n = 8;
	else if (size > 150)
		n = 18;
	return (n);
}

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
	while (ft_lstsize(*stack_a) > 0)
	{
		while ((*stack_a)->content != nb)
		{
			if (index < ft_lstsize(*stack_a) / 2)
				rotate_a(stack_a, 0);
			else
				rev_rotate_a(stack_a, 0);
		}
		if (nb < middle)
			rev_rotate_b(stack_b, 0);
		push_b(stack_a, stack_b);
	}
}

void	sort_hundred(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	int	*array;
	int size;
	int	n;
	int	middle;
	int	offset;
	int	start;
	int	end;
	int index;

	size = ft_lstsize(*stack_a);
	n = ft_n(*stack_a);
	middle = size / 2;
	offset = size / n;
	start = middle - offset;
	end = middle + offset;
	array = array_sort(*stack_a);
	while (ft_lstsize(*stack_a) > 0)
	{
		index = start;
		while (index <= end)
		{
			tmp = *stack_a;
			while (tmp != NULL)
			{
				if (tmp->content >= array[start] && tmp->content <= array[end])
				{
					index++;
					sort_b(stack_a, stack_b, tmp->content, array[middle]);
					break ;
				}
				tmp = tmp->next;
			}
		}
		start = start - offset;
		end = end + offset;
	}
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
		else if (ft_lstsize(*stack_a) > 5 && ft_lstsize(*stack_a) <= 500)
			sort_hundred(stack_a, stack_b);
		/*
		else if (ft_lstsize(stack_a) > 100 && ft_lstsize(stack_a) <= 500)
			sort_five_hundred(stack_a, stack_b);
			*/
	}
}