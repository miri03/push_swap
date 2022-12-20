/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:15:21 by meharit           #+#    #+#             */
/*   Updated: 2022/12/20 23:33:32 by meharit          ###   ########.fr       */
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

void	rotate_a(t_list **stack_a)
{
	t_list	*tmp;

	printf("RA :\n");

	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = NULL;
	ft_lstadd_back(stack_a, tmp);
	
	printList(*stack_a);
}

void	rotate_b(t_list **stack_b)
{
	t_list	*tmp;

	printf("RB :\n");

	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = NULL;
	ft_lstadd_back(stack_b, tmp);
	
	printList(*stack_b);
}


void	rotate_a_b(t_list **stack_a, t_list **stack_b)
{
	printf("RR: \n\n");

	rotate_a(stack_a);
	rotate_b(stack_b);
}

t_list	*ft_newlast(t_list	*stack)
{
	t_list *tmp;
	printf("infunc\n");
	printList(stack);
	while (stack->next != NULL)
 	{
		stack = stack->next;
		printf("stack %d\n", stack->content);
		tmp = stack->next;
	//	printf("tmp %d\n",tmp->content);
		if (stack->next == NULL)
		{
			printf("result=%d\n",stack->content);
			return (stack);
		}
	}

	printf("KO");
	return (NULL);
}

void	rev_rotate_a(t_list **stack_a)
{
//	t_list	*tmp;
	t_list	*last;
	t_list	*new_last;

	last = ft_lstlast(*stack_a);
	new_last = ft_newlast(*stack_a);
//	tmp = *stack_a;
//	last->next = tmp;
//	ft_lstadd_front(stack_a, last);
	printf("last->%d\n", new_last->content);
}
