/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_u1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:40:36 by meharit           #+#    #+#             */
/*   Updated: 2023/01/03 16:57:04 by meharit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"swap.h"

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
	while (stack_a != NULL)
	{
		if (stack_a->next != NULL && (stack_a->content == min || min >= new_min))
		{
			if (stack_a->next != NULL && stack_a->content > min)
				new_min = stack_a->content; //
			stack_a = stack_a->next;
		}
		if (min > new_min || (stack_a->content < new_min && stack_a->content > min))
			new_min = stack_a->content;
		stack_a = stack_a->next;
	}
	return (new_min);
}

int	*array_sort(t_list *stack_a)
{
	int	min;
	int	*array;
	int	size;
	int	i;

	i = 0;
	min = min_value(stack_a);
	size = ft_lstsize(stack_a);
	array = (int*)malloc(sizeof(int) * size);
	array[i] = min;
	i++;
	while (size > i)
	{
		array[i] = min_array(stack_a, min);
		min = min_array(stack_a, min);
		i++;
	}
	return (array);
}
