/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 00:02:01 by meharit           #+#    #+#             */
/*   Updated: 2022/12/26 20:14:01 by meharit          ###   ########.fr       */
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

void	deleteList(t_list** head_ref) //
{
	t_list* current = *head_ref;
	t_list* next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*head_ref = NULL;
}

t_list	*make_stack(char **args, int argc)
{
	char	**str;
	t_list	*stack_a;
	int		i;
	int		j;

	stack_a = NULL;
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
			free_str(str);
			free(str);
		}
	
	}
	else
		error();
//	printf("THE STACK\n");
//	printList(stack_a); 		//print stack
	return (stack_a);
}

int main(int argc, char **argv)
{
	t_list	*stack_a = NULL;
	t_list	*stack_b = NULL;

	if (argc < 2)
		exit (0);
	stack_a = make_stack(argv, argc - 1);
	if (check_doubles(stack_a) == 0)
		error();

/*
	swap_a(stack_a, 0);
	swap_b(stack_b, 0);
	swap_a_b(stack_a, stack_b);
	push_a(&stack_a, &stack_b);
	push_b(&stack_a, &stack_b);
	rotate_a(&stack_a, 0);
	rotate_b(&stack_b, 0);
	rotate_a_b(&stack_a, &stack_b);
	rev_rotate_a(&stack_a, 0);
	rev_rotate_b(&stack_b, 0);
	rev_rotate(&stack_a, &stack_b);
*/


/*	
	printf("THE STACK\n");
	printList(stack_a); 		//print stack
*/

/*
	push_b(&stack_a, &stack_b);
	push_b(&stack_a, &stack_b);
	printf("%d\n",ft_lstsize(stack_b));
	push_a(&stack_a, &stack_b);
	printf("%d\n",ft_lstsize(stack_b));
*/


	sort_list(stack_a, stack_b);

	printList(stack_a);




//	deleteList(&stack_a); //
//	deleteList(&stack_b); //


//	system("leaks push_swap");


}

