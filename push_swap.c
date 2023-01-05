/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 00:02:01 by meharit           #+#    #+#             */
/*   Updated: 2023/01/05 20:54:47 by meharit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void printList(t_list *head) //print stack
{
    t_list *temp = head;

  	while (temp != NULL)
    {
         printf("%d\n", temp->content);
         temp = temp->next;
    }
	printf("NULL\n");
}

t_list	*make_stack(char **args, int argc)
{
	char	**str;
	t_list	*stack_a;
	int		i;

	stack_a = NULL;
	i = 1;
	if (is_valide(args, argc))
	{
		while (i <= argc)
		{
			str = ft_split(args[i], ' ');
			i++;
			add_in_stack(&stack_a, str);
		}
	}
	else
		error();
	return (stack_a);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		exit (0);
	stack_a = make_stack(argv, argc - 1);
	if (check_doubles(stack_a) == 0)
		error();
	sort_list(&stack_a, &stack_b);
	//system("leaks push_swap");
}
