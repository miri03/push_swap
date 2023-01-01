/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:00:43 by meharit           #+#    #+#             */
/*   Updated: 2023/01/01 22:02:26 by meharit          ###   ########.fr       */
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

void	sort_hundred(t_list **stack_a, t_list **stack_b)
{
	int		*sorted;
	int		n;
	int		middle;
	int		size;
	int		offset;
	int		index;
	t_list	*tmp;
	int		start;
	int		end;
	int		st;
	int		content;

	sorted = array_sort(*stack_a);
	size = ft_lstsize(*stack_a); 
	n = ft_n(*stack_a);
	middle = ft_lstsize(*stack_a) / 2;
	offset = size / n;
	start = middle - offset;
	end = middle + offset;
	st = start;
	while (ft_lstsize(*stack_a) > 1)
	{
		st = start;
	//	while (start >= 0)
	//	{
			while (st <= end)
			{
			tmp = *stack_a;
			index = 0;		

			while (tmp->next != NULL)
			{
				if (tmp->content == sorted[st])
				{
			//		printf("num=%d st=%d end=%d\n", sorted[st],st,end);
					if (index < ft_lstsize(*stack_a)/2)//		if first
					{
						while ((*stack_a)->content != sorted[st])
							rotate_a(stack_a, 0);
					}
					else
					{
						while ((*stack_a)->content != sorted[st])
							rev_rotate_a(stack_a, 0);
					}
					if (*stack_b != NULL)
						content = (*stack_b)->content;
					push_b(stack_a, stack_b);
				//	printf("stack_b->%d\n",content);
					if (sorted[st] < content && ft_lstsize(*stack_b) > 1)
						rotate_b(stack_b, 0);
				//	printf("\n------------\n");
				//	printList(*stack_b);
				//	printf("------------\n\n");
					break ;
				}
				index++;
				tmp = tmp->next;
			}
			st++;
		}
		//	printf("st=%d end=%d\n",st,end);
		//	if (st >= end)
		//	{
		//		printf("KO\n");
		//	}
		end += offset;
		start -= offset;
	//	printf("end=%d start=%d size=%d\n",end,start,ft_lstsize(*stack_a));
	
	//	}
	//	if (start < 0 && ft_lstsize(*stack_a) > 1)
	//		break ;
	}
	if (ft_lstsize(*stack_a) == 1)
		push_b(stack_a,stack_b);
	printf("end\n");
	printList(*stack_b);
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
