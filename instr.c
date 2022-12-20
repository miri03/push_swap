/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:15:21 by meharit           #+#    #+#             */
/*   Updated: 2022/12/20 03:23:21 by meharit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	swap_a(t_list *stack_a)
{
	t_list	*second;
	int		tmp;

	if (ft_lstsize(stack_a) > 1)
	{
		tmp = stack_a->content;
		second = stack_a->next;
		stack_a->content = second->content;
		second->content = tmp;
	}
	printf("sa\n");
	printList(stack_a); //
}

void	swap_b(t_list *stack_b)
{
	t_list	*second;
	int		tmp;

	if (ft_lstsize(stack_b) > 1)
	{
		tmp = stack_b->content;
		second = stack_b->next;
		stack_b->content = second->content;
		second->content = tmp;
	}
	printf("sb\n");
	printList(stack_b); //
}

void	swap_a_b(t_list *stack_a, t_list *stack_b)
{

	printf("SS: \n");
	printf("stack_a\n");
	printList(stack_a);
	printf("stack_b\n");
	printList(stack_b);
	swap_a(stack_a);
	swap_b(stack_b);
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;
	printf("PB: \n");

	if (ft_lstsize(*stack_a) < 1)
		return ;
	tmp_a = (*stack_a)->next;
	tmp_b = *stack_b;
	*stack_b = *stack_a;
	(*stack_b)->next = tmp_b;
	*stack_a = tmp_a;

	printf("stack_a\n");
	printList(*stack_a);
	printf("stack_b\n");
	printList(*stack_b);
}

void	push_a(t_list	**stack_a, t_list **stack_b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;

	printf("PA: \n");

	if (ft_lstsize(*stack_b) > 0)
	{
		tmp_b = (*stack_b)->next;
		tmp_a = *stack_a;
		*stack_a = *stack_b;
		(*stack_a)->next = tmp_a;
		*stack_b = tmp_b;
	}
	printf("stack_a\n");
	printList(*stack_a);
	printf("stack_b\n");
	printList(*stack_b);

}

void	rotate_a(t_list *stack_a)
{
	
