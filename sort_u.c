/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:03:07 by meharit           #+#    #+#             */
/*   Updated: 2022/12/31 05:48:44 by meharit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

int	is_sorted(t_list *stack)
{
	t_list	*tmp;

	while (stack->next != NULL)
	{
		tmp = stack->next;
		if (stack->content > tmp->content)
			return (0);
		else
			stack = stack->next;
	}
	return (1);
}

void	sort_three_s(t_list *first, t_list *third, t_list **stack_a)
{
	if (first->content < third->content)
	{
		rev_rotate_a(stack_a, 0);
		swap_a(stack_a, 0);
	}
	else
		rev_rotate_a(stack_a, 0);
}

int	min_value(t_list *head)
{
	int		min;
	t_list	*current;

	current = head->next;
	min = head->content;
	while (current != NULL)
	{
		if (current->content < min)
			min = current->content;
		current = current->next;
	}
	return (min);
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

t_list*	copy_stack(t_list *stack_a)
{
    t_list* copy_head = malloc(sizeof(t_list*));
    t_list* copy_tail = copy_head;

    t_list* curr = stack_a;
    while (curr != NULL)
	{
        copy_tail->next = malloc(sizeof(t_list*));
        copy_tail->next->content = curr->content;
        copy_tail = copy_tail->next;
        curr = curr->next;
    }

    copy_tail->next = NULL;

    return copy_head->next;
}

int	min_array(t_list *stack_a, int min)
{
	int	new_min;

	new_min = stack_a->content;
	printf("min=%d\n", min);
	while (stack_a != NULL)
	{
		printf("%d %d\n",stack_a->content,new_min);
		if (stack_a->next != NULL && (stack_a->content == min || min >= new_min))
		{
				
				if (stack_a->next != NULL && stack_a->content > min)
					new_min = stack_a->content; //
				stack_a = stack_a->next;
		}
		printf("===>%d %d\n",stack_a->content,new_min);
		if (min > new_min || (stack_a->content < new_min && stack_a->content > min))
			new_min = stack_a->content;
		stack_a = stack_a->next;
	}
	printf("new_min=%d\n",new_min);
	return (new_min);
}

int	*array_sort(t_list *stack_a)
{
	int	min;
	int	*array = NULL;
	int	size;
	int	i = 0;

	min = min_value(stack_a);
	size = ft_lstsize(stack_a);
	i++;
	while (size > i)
	{
	//	array[i] = min_array(stack_a, min);
	printList(stack_a);
		min = min_array(stack_a, min);
		printf("----------\n");
	//	printf("%d %d\n",min,i);
		i++;
	}
	return (array);
}



/*
int	*array_sort(t_list *stack_a)
{
	int		*array  = NULL;
	int		size;
	int		i = 0;
	t_list	*tmp;
	t_list	*store;
	int		min;

	tmp = copy_stack(stack_a);
	size = ft_lstsize(stack_a);
//	while (ft_lstsize(stack_a) > 0)
	while (size > i)
	{
		min = min_value(stack_a);
		while (tmp->content != min)
		{
			store = tmp;
			tmp = tmp->next;
		}
		store->next = tmp->next; // 

		printf("OKK\n");
		printf("%d\n", array[i]);
		array[i] = min;
		i++;
	}	return (array);
}
*/


