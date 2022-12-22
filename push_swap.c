/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 00:02:01 by meharit           #+#    #+#             */
/*   Updated: 2022/12/22 02:15:35 by meharit          ###   ########.fr       */
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
}

t_list	*make_stack(char **args, int argc)
{
	char	**str;
	t_list	*stack_a;
	int		i;
	int		j;
	int		f;

	i = 1;
	if (is_valide(args, argc))
	{
		while (i <= argc)
		{
			str = ft_split(args[i], ' ');
			i++;
			j = 0;
			while (str[j] != NULL)
			{
				ft_lstadd_back(&stack_a, ft_lstnew(ft_atoi(str[j])));
				j++;
			}
			f = 0;
			while (str[f])
			{
				free(str[f]);
				f++;
			}
		}
	}
	else
	{
		write(1, "Error\n", 6);
		exit (0);
	}
	printf("THE STACK\n");
	printList(stack_a); //print stack
	return (stack_a);
}

int main(int argc, char **argv)
{
	int		i;
	t_list	*stack_a;
//	t_list	*stack_b = NULL;

	i = 1;
	if (argc < 2)
		exit (0);
	stack_a = make_stack(argv, argc - 1);
	if (check_doubles(stack_a) == 0)
	{
		write(1, "Error\n", 6);
		exit (0);
	}
//	swap_a(stack_a);
//	push_b(&stack_a, &stack_b);
//	swap_b(stack_b);
//	push_b(&stack_a, &stack_b);
//	push_a(&stack_a, &stack_b);
//	rotate_a(&stack_a);
//	rotate_b(&stack_b);
//	rotate_a_b(&stack_a, &stack_b);
	
	rev_rotate_a(&stack_a);
//	rev_rotate_a(&stack_a);
//	rev_rotate_b(&stack_b);

/*	while (stack_a != NULL)
	{
		tmp = stack_a;
		stack_a = stack_a->next;
		free(tmp);
	}
*/

}

