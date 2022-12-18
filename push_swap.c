/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 00:02:01 by meharit           #+#    #+#             */
/*   Updated: 2022/12/18 01:10:11 by meharit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void printList(t_list *head) //print stack
{
    t_list *temp = head;

    while(temp != NULL)
    {
         printf("%d->", temp->content);
         temp = temp->next;
    }
    printf("NULL\n");
}

t_list	*make_stack(char **args, int argc)
{
	char	**str;
	t_list	*stack_a;
	int		i;
	int		j;

	i = 0;
	if (is_valide(&args[i], argc))
	{
		while (i < argc)
		{
			str = ft_split(args[i], ' ');
			i++;
			j = 0;
			while (str[j] != NULL)
			{
				ft_lstadd_back(&stack_a, ft_lstnew(ft_atoi(str[j])));
				j++;
			}
		}
	}
	else
	{
		write(1, "Error\n", 6);
		exit (0);
	}
	printList(stack_a); //print stack
	return (stack_a);
}

int main(int argc, char **argv)
{
	int		i;
	t_list	*stack_a;

	i = 1;
	if (argc < 2)
		exit (0);
	stack_a = make_stack(&argv[i], argc - 1);
	if (check_doubles(stack_a) == 0)
	{
		write(1, "Error\n", 6);
		exit (0);
	}
}
