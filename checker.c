/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 21:52:26 by meharit           #+#    #+#             */
/*   Updated: 2023/01/06 15:59:54 by meharit          ###   ########.fr       */
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

int	ft_strcmp(char *s1, char *s2)
{
	int	count;

	count = 0;
	while (s1[count] != '\0' || s2[count] != '\0')
	{
		if (s1[count] != s2[count])
			return (s1[count] - s2[count]);
		count++;
	}
	return (0);
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

int	check_line(char *line)
{
	if (!ft_strcmp("sa\n", line) || !ft_strcmp("sb\n", line) || !ft_strcmp("ss\n", line))  
		return (1);
	if (!ft_strcmp("pa\n", line) || !ft_strcmp("pb\n", line) || !ft_strcmp("rrr\n", line)) 
		return (1);
	if (!ft_strcmp("ra\n", line) || !ft_strcmp("rb\n", line) || !ft_strcmp("rr\n", line) )
		return (1);
	if (!ft_strcmp("rra\n", line) || !ft_strcmp("rrb\n", line) )
		return (1);
	return (0);
}

void	inst(char *line, t_list **stack_a, t_list **stack_b)
{
	if (!ft_strcmp("sa\n", line))
		swap_a(stack_a, 1);
	else if (!ft_strcmp("sb\n", line))
		swap_b(stack_b, 1);
	else if (!ft_strcmp("ss\n", line))
		swap_a_b(*stack_a, *stack_b, 1);
	else if (!ft_strcmp("pa\n", line))
		push_a_bonus(stack_a, stack_b, 1);
	else if (!ft_strcmp("pb\n", line))
		push_b_bonus(stack_a, stack_b, 1);
	else if (!ft_strcmp("ra\n", line))
		rotate_a(stack_a, 1);
	else if (!ft_strcmp("rb\n", line))
		rotate_b(stack_b, 1);
	else if (!ft_strcmp("rr\n", line))
		rotate_a_b(stack_a, stack_b, 1);
	else if (!ft_strcmp("rra\n", line))
		rev_rotate_a(stack_a, 1);
	else if (!ft_strcmp("rrb\n", line))
		rev_rotate_b(stack_b, 1);
	else if (!ft_strcmp("rrr\n", line))
		rev_rotate(stack_a, stack_b, 1);
}

int main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	*line;
	int		size;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		exit (0);
	stack_a = make_stack(argv, argc - 1);
	if (check_doubles(stack_a) == 0)
		error ();
	size = ft_lstsize(stack_a);
	line = get_next_line(0);
	while (line != NULL)
	{
		if(check_line(line) == 0)
			error();
		inst(line, &stack_a, &stack_b);
		line = get_next_line(0);
	}
	if (is_sorted(stack_a) && ft_lstsize(stack_a) == size)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
