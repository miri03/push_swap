/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 00:02:01 by meharit           #+#    #+#             */
/*   Updated: 2022/12/15 23:29:18 by meharit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

int	is_valide(char **s, int argc)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (is_numeric(s[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

t_list	**make_stack(char **args, int argc)
{
	char	**str;
	t_list	**stack_a = NULL;
	int		i;

	i = 0;
	int j = 0;
	if (is_valide(&args[i], argc - 1))
	{
		str = ft_split(args[i], ' ');
		while (j < 4)
		{
			printf("%s\n", str[j]);
			j++;
		}
		*stack_a = ft_lstnew(str[i]);
		i++;
	
		while (i < argc)
		{
			ft_lstadd_back(stack_a, ft_lstnew(&str[i]));
			i++;
		}
	}
	else
	{
		write(1, "Error\n", 6);
		exit (0);
	}
	return (stack_a);
}

int main(int argc, char **argv)
{
	int		i;
	t_list	**stack_a;

	i = 1;
	if (argc < 2)
		exit (0);
	stack_a = make_stack(&argv[i], argc - 1);

}
