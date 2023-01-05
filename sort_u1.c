/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_u1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:40:36 by meharit           #+#    #+#             */
/*   Updated: 2023/01/05 20:44:00 by meharit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"swap.h"

void	free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
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

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	count;
	int	i;

	i = 0;
	while (i < size)
	{
		count = i + 1;
		while (count < size)
		{
			if (tab[i] > tab[count])
				ft_swap(&tab[i], &tab[count]);
			count++;
		}
		i++;
	}
}

int	*array_sort(t_list *stack_a)
{
	int		*array;
	t_list	*tmp;
	int		i;

	i = 0;
	array = (int *)malloc(sizeof(int) * ft_lstsize(stack_a));
	if (array == NULL)
		return (NULL);
	tmp = stack_a;
	while (tmp != NULL)
	{
		array[i] = tmp->content;
		tmp = tmp->next;
		i++;
	}
	ft_sort_int_tab(array, ft_lstsize(stack_a));
	return (array);
}
