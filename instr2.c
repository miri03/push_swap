/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:04:19 by meharit           #+#    #+#             */
/*   Updated: 2023/01/05 20:55:47 by meharit          ###   ########.fr       */
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

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

void	add_in_stack(t_list **stack_a, char **str)
{
	int	j;

	j = 0;
	while (str[j] != NULL)
	{
		ft_lstadd_back(stack_a, ft_lstnew(ft_atoi(str[j])));
		j++;
	}
	free_str(str);
	free(str);
}
